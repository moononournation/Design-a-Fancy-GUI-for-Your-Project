/*******************************************************************************
 * LVGL T-QT BME680
 * This is a BME680 demo
 *
 * Dependent libraries:
 * LVGL: https://github.com/lvgl/lvgl.git
 *
 * LVGL Configuration file:
 * Copy your_arduino_path/libraries/lvgl/lv_conf_template.h
 * to your_arduino_path/libraries/lv_conf.h
 * Then find and set:
 * #define LV_COLOR_DEPTH     16
 * #define LV_TICK_CUSTOM     1
 *
 * For SPI display set color swap can be faster, parallel screen don't set!
 * #define LV_COLOR_16_SWAP   1
 * 
 * Enable font size
 * #define LV_FONT_MONTSERRAT_12 1
 * #define LV_FONT_MONTSERRAT_16 1
 ******************************************************************************/
#include <lvgl.h>
#include "ui.h"
#define SCR_LOAD_ANIM_TIME 300 // ms
#define CHART_SERIAL_VALUE_COUNT 60

/*******************************************************************************
 * Start of Arduino_GFX setting
 *
 * Arduino_GFX try to find the settings depends on selected board in Arduino IDE
 * Or you can define the display dev kit not in the board list
 * Defalult pin list for non display dev kit:
 * Arduino Nano, Micro and more: CS:  9, DC:  8, RST:  7, BL:  6, SCK: 13, MOSI: 11, MISO: 12
 * ESP32 various dev board     : CS:  5, DC: 27, RST: 33, BL: 22, SCK: 18, MOSI: 23, MISO: nil
 * ESP32-C3 various dev board  : CS:  7, DC:  2, RST:  1, BL:  3, SCK:  4, MOSI:  6, MISO: nil
 * ESP32-S2 various dev board  : CS: 34, DC: 35, RST: 33, BL: 21, SCK: 36, MOSI: 35, MISO: nil
 * ESP32-S3 various dev board  : CS: 40, DC: 41, RST: 42, BL: 48, SCK: 36, MOSI: 35, MISO: nil
 * ESP8266 various dev board   : CS: 15, DC:  4, RST:  2, BL:  5, SCK: 14, MOSI: 13, MISO: 12
 * Raspberry Pi Pico dev board : CS: 17, DC: 27, RST: 26, BL: 28, SCK: 18, MOSI: 19, MISO: 16
 * RTL8720 BW16 old patch core : CS: 18, DC: 17, RST:  2, BL: 23, SCK: 19, MOSI: 21, MISO: 20
 * RTL8720_BW16 Official core  : CS:  9, DC:  8, RST:  6, BL:  3, SCK: 10, MOSI: 12, MISO: 11
 * RTL8722 dev board           : CS: 18, DC: 17, RST: 22, BL: 23, SCK: 13, MOSI: 11, MISO: 12
 * RTL8722_mini dev board      : CS: 12, DC: 14, RST: 15, BL: 13, SCK: 11, MOSI:  9, MISO: 10
 * Seeeduino XIAO dev board    : CS:  3, DC:  2, RST:  1, BL:  0, SCK:  8, MOSI: 10, MISO:  9
 * Teensy 4.1 dev board        : CS: 39, DC: 41, RST: 40, BL: 22, SCK: 13, MOSI: 11, MISO: 12
 ******************************************************************************/
#include <Arduino_GFX_Library.h>

#define GFX_EXTRA_PRE_INIT() { pinMode(10 /* BL */, OUTPUT); digitalWrite(10 /* BL */, LOW); }
Arduino_DataBus *bus = new Arduino_ESP32SPI(6 /* DC */, 5 /* CS */, 3 /* SCK */, 2 /* MOSI */, GFX_NOT_DEFINED /* MISO */);
Arduino_GFX *gfx = new Arduino_GC9107(bus, 1 /* RST */, 0 /* rotation */, true /* IPS */);
/*******************************************************************************
 * End of Arduino_GFX setting
 ******************************************************************************/

/*******************************************************************************
 * hardware setting
 ******************************************************************************/
#define LEFT_BTN_PIN 0
#define RIGHT_BTN_PIN 47
#define I2C_SDA_PIN 16
#define I2C_SCL_PIN 17

/*******************************************************************************
 * BME680 setting
 ******************************************************************************/
#define GET_VALUE_INTERVAL 60000 // 1 minute
#include "Zanshin_BME680.h"  // Include the BME680 Sensor library
BME680_Class BME680;  ///< Create an instance of the BME680 class

static int32_t  temp, humidity, pressure, gas;  // BME readings
static char     buf[16];                        // sprintf text buffer
static float    alt;                            // Temporary variable
static uint16_t loopCounter = 0;                // Display iterations

static uint32_t screenWidth;
static uint32_t screenHeight;
static lv_disp_draw_buf_t draw_buf;
static lv_color_t *disp_draw_buf;
static lv_color_t *disp_draw_buf2;
static lv_disp_drv_t disp_drv;
static lv_chart_series_t * ser_temps;
static lv_chart_series_t * ser_humid;
static lv_chart_series_t * ser_air_q;
static long last_value_ms = -GET_VALUE_INTERVAL;
static long last_point_ms = -GET_VALUE_INTERVAL;
static uint8_t current_screen = 1;
static long last_pressed = -GET_VALUE_INTERVAL;
static long chart_value_interval = GET_VALUE_INTERVAL; // initial interval is same as GET_VALUE_INTERVAL, double after each serials cycle

/* Display flushing */
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);

#if (LV_COLOR_16_SWAP != 0)
  gfx->draw16bitBeRGBBitmap(area->x1, area->y1, (uint16_t *)&color_p->full, w, h);
#else
  gfx->draw16bitRGBBitmap(area->x1, area->y1, (uint16_t *)&color_p->full, w, h);
#endif

  lv_disp_flush_ready(disp);
}

void left_btn_pressed() {
  if ((millis() - last_pressed) >= SCR_LOAD_ANIM_TIME) {
    switch(current_screen) {
      case 1:
        lv_scr_load_anim(ui_Screen4, LV_SCR_LOAD_ANIM_MOVE_RIGHT, SCR_LOAD_ANIM_TIME, 0, false);
        current_screen = 4;
        break;
      case 2:
        lv_scr_load_anim(ui_Screen1, LV_SCR_LOAD_ANIM_MOVE_RIGHT, SCR_LOAD_ANIM_TIME, 0, false);
        current_screen = 1;
        break;
      case 3:
        lv_scr_load_anim(ui_Screen2, LV_SCR_LOAD_ANIM_MOVE_RIGHT, SCR_LOAD_ANIM_TIME, 0, false);
        current_screen = 2;
        break;
      default:
        lv_scr_load_anim(ui_Screen3, LV_SCR_LOAD_ANIM_MOVE_RIGHT, SCR_LOAD_ANIM_TIME, 0, false);
        current_screen = 3;
        break;
    }

    last_pressed = millis();
  }
}

void right_btn_pressed() {
  if ((millis() - last_pressed) >= SCR_LOAD_ANIM_TIME) {
    switch(current_screen) {
      case 1:
        lv_scr_load_anim(ui_Screen2, LV_SCR_LOAD_ANIM_MOVE_LEFT, SCR_LOAD_ANIM_TIME, 0, false);
        current_screen = 2;
        break;
      case 2:
        lv_scr_load_anim(ui_Screen3, LV_SCR_LOAD_ANIM_MOVE_LEFT, SCR_LOAD_ANIM_TIME, 0, false);
        current_screen = 3;
        break;
      case 3:
        lv_scr_load_anim(ui_Screen4, LV_SCR_LOAD_ANIM_MOVE_LEFT, SCR_LOAD_ANIM_TIME, 0, false);
        current_screen = 4;
        break;
      default:
        lv_scr_load_anim(ui_Screen1, LV_SCR_LOAD_ANIM_MOVE_LEFT, SCR_LOAD_ANIM_TIME, 0, false);
        current_screen = 1;
        break;
    }

    last_pressed = millis();
  }
}

void setup() {
  Serial.begin(115200);  // Start serial port at Baud rate
  // Serial.setDebugOutput(true);
  // while(!Serial);
  Serial.print(F("TTGO T-QT BME680\n"));

#ifdef GFX_EXTRA_PRE_INIT
  GFX_EXTRA_PRE_INIT();
#endif

  // Init Display
  gfx->begin(80000000);
  gfx->fillScreen(BLACK);

#ifdef GFX_BL
  pinMode(GFX_BL, OUTPUT);
  digitalWrite(GFX_BL, HIGH);
#endif

  Serial.print(F("start I2C\n"));
  Wire.begin(I2C_SDA_PIN, I2C_SCL_PIN);

  /* Init BME680 */
  Serial.print(F("Starting I2CDemo example program for BME680\n"));
  Serial.print(F("- Initializing BME680 sensor\n"));
  while (!BME680.begin(I2C_STANDARD_MODE)) {  // Start BME680 using I2C, use first device found
    Serial.print(F("-  Unable to find BME680. Trying again in 5 seconds.\n"));
    delay(5000);
  }  // of loop until device is located
  Serial.print(F("- Setting 16x oversampling for all sensors\n"));
  BME680.setOversampling(TemperatureSensor, Oversample16);  // Use enumerated type values
  BME680.setOversampling(HumiditySensor, Oversample16);     // Use enumerated type values
  BME680.setOversampling(PressureSensor, Oversample16);     // Use enumerated type values
  Serial.print(F("- Setting IIR filter to a value of 4 samples\n"));
  BME680.setIIRFilter(IIR4);  // Use enumerated type values
  Serial.print(F("- Setting gas measurement to 320\xC2\xB0\x43 for 150ms\n"));  // "�C" symbols
  BME680.setGas(320, 150);  // 320�c for 150 milliseconds
  BME680.getSensorData(temp, humidity, pressure, gas);  // Get readings

  /* Init LVGL */
  lv_init();

  screenWidth = gfx->width();
  screenHeight = gfx->height();
#ifdef ESP32
  disp_draw_buf = (lv_color_t *)heap_caps_malloc(sizeof(lv_color_t) * screenWidth * 32, MALLOC_CAP_INTERNAL | MALLOC_CAP_8BIT);
#else
  disp_draw_buf = (lv_color_t *)malloc(sizeof(lv_color_t) * screenWidth * 32);
#endif
  if (!disp_draw_buf)
  {
    Serial.println("LVGL disp_draw_buf allocate failed!");
  }
  else
  {
    lv_disp_draw_buf_init(&draw_buf, disp_draw_buf, NULL, screenWidth * 32);

    /* Initialize the display */
    lv_disp_drv_init(&disp_drv);
    /* Change the following line to your display resolution */
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);

    /* Initialize the (dummy) input device driver */
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    lv_indev_drv_register(&indev_drv);

    /* Init SquareLine prepared UI */
    ui_init();

    /* Init Charts */
    lv_chart_set_type(ui_Screen2_Chart1, LV_CHART_TYPE_LINE);
    lv_chart_set_type(ui_Screen3_Chart1, LV_CHART_TYPE_LINE);
    lv_chart_set_type(ui_Screen4_Chart1, LV_CHART_TYPE_LINE);

    lv_chart_set_range(ui_Screen2_Chart1, LV_CHART_AXIS_PRIMARY_Y, 0, 50);
    lv_chart_set_range(ui_Screen3_Chart1, LV_CHART_AXIS_PRIMARY_Y, 0, 100);
    lv_chart_set_range(ui_Screen4_Chart1, LV_CHART_AXIS_PRIMARY_Y, 0, 100);

    lv_chart_set_axis_tick(ui_Screen2_Chart1, LV_CHART_AXIS_PRIMARY_Y, 5, 5, 6, 1, true, 24);
    lv_chart_set_axis_tick(ui_Screen3_Chart1, LV_CHART_AXIS_PRIMARY_Y, 5, 2, 6, 2, true, 28);
    lv_chart_set_axis_tick(ui_Screen4_Chart1, LV_CHART_AXIS_PRIMARY_Y, 5, 2, 6, 2, true, 28);

    lv_chart_set_point_count(ui_Screen2_Chart1, CHART_SERIAL_VALUE_COUNT);
    lv_chart_set_point_count(ui_Screen3_Chart1, CHART_SERIAL_VALUE_COUNT);
    lv_chart_set_point_count(ui_Screen4_Chart1, CHART_SERIAL_VALUE_COUNT);

    lv_chart_set_update_mode(ui_Screen2_Chart1, LV_CHART_UPDATE_MODE_SHIFT);
    lv_chart_set_update_mode(ui_Screen3_Chart1, LV_CHART_UPDATE_MODE_SHIFT);
    lv_chart_set_update_mode(ui_Screen4_Chart1, LV_CHART_UPDATE_MODE_SHIFT);

    lv_obj_set_style_size(ui_Screen2_Chart1, 0, LV_PART_INDICATOR);
    lv_obj_set_style_size(ui_Screen3_Chart1, 0, LV_PART_INDICATOR);
    lv_obj_set_style_size(ui_Screen4_Chart1, 0, LV_PART_INDICATOR);

    /* Init data series */
    ser_temps = lv_chart_add_series(ui_Screen2_Chart1, lv_palette_main(LV_PALETTE_RED), LV_CHART_AXIS_PRIMARY_Y);
    ser_humid = lv_chart_add_series(ui_Screen3_Chart1, lv_palette_main(LV_PALETTE_BLUE), LV_CHART_AXIS_PRIMARY_Y);
    ser_air_q = lv_chart_add_series(ui_Screen4_Chart1, lv_palette_main(LV_PALETTE_GREEN), LV_CHART_AXIS_PRIMARY_Y);

    lv_chart_set_all_value(ui_Screen2_Chart1, ser_temps, 0);
    lv_chart_set_all_value(ui_Screen3_Chart1, ser_humid, 0);
    lv_chart_set_all_value(ui_Screen4_Chart1, ser_air_q, 0);

    Serial.print(F("Setup done\n"));
  }

  /* Init buttons */
  pinMode(LEFT_BTN_PIN, INPUT_PULLUP);
  attachInterrupt(LEFT_BTN_PIN, left_btn_pressed, FALLING);
  pinMode(RIGHT_BTN_PIN, INPUT_PULLUP);
  attachInterrupt(RIGHT_BTN_PIN, right_btn_pressed, FALLING);
}

void loop() {
  lv_timer_handler(); /* let the GUI do its work */

  if ((millis() - last_value_ms) < GET_VALUE_INTERVAL) {
    delay(5);
  } else {
    last_value_ms = millis();

    BME680.getSensorData(temp, humidity, pressure, gas);  // Get readings
    sprintf(buf, "%2d",(int8_t)(temp / 100));   // Temp in decidegrees
    lv_arc_set_value(ui_Screen1_Arc_Temps, temp / 100);
    lv_label_set_text(ui_Screen1_Label_Temps, buf);

    sprintf(buf, "%2d", (int8_t)(humidity / 1000));  // Humidity milli-pct
    lv_arc_set_value(ui_Screen1_Arc_Humid, humidity / 1000);
    lv_label_set_text(ui_Screen1_Label_Humid, buf);

    sprintf(buf, "%2d", (int16_t)(gas / 10000));  // Resistance milliohms
    lv_arc_set_value(ui_Screen1_Arc_Air_Q, gas / 10000);
    lv_label_set_text(ui_Screen1_Label_Air_Q, buf);

    sprintf(buf, "%4d.%02d\nhPa", (int16_t)(pressure / 100), (uint8_t)(pressure % 100));  // Pressure Pascals
    lv_label_set_text(ui_Screen1_Label_Pressu, buf);

    if ((millis() - last_point_ms) > chart_value_interval) {
      last_point_ms = millis();

      lv_chart_set_next_value(ui_Screen2_Chart1, ser_temps, temp / 100);
      lv_chart_set_next_value(ui_Screen3_Chart1, ser_humid, humidity / 1000);
      lv_chart_set_next_value(ui_Screen4_Chart1, ser_air_q, gas / 10000);
    }
    if ((loopCounter % CHART_SERIAL_VALUE_COUNT) == 0) {
      chart_value_interval *= 2;
    }
  }
}
