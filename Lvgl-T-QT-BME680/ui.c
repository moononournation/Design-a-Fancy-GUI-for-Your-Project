// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.1
// LVGL VERSION: 8.3.3
// PROJECT: SquareLine_Project

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t *ui_Screen1;
lv_obj_t *ui_Screen1_Arc_Temps;
lv_obj_t *ui_Screen1_Arc_Humid;
lv_obj_t *ui_Screen1_Arc_Air_Q;
lv_obj_t *ui_Screen1_Label1;
lv_obj_t *ui_Screen1_Label2;
lv_obj_t *ui_Screen1_Label3;
lv_obj_t *ui_Screen1_Label4;
lv_obj_t *ui_Screen1_Label_Temps;
lv_obj_t *ui_Screen1_Label_Humid;
lv_obj_t *ui_Screen1_Label_Air_Q;
lv_obj_t *ui_Screen1_Label_Pressu;
lv_obj_t *ui_Screen2;
lv_obj_t *ui_Screen2_Chart1;
lv_obj_t *ui_Screen2_Label1;
lv_obj_t *ui_Screen3;
lv_obj_t *ui_Screen3_Chart1;
lv_obj_t *ui_Screen3_Label1;
lv_obj_t *ui_Screen4;
lv_obj_t *ui_Screen4_Chart1;
lv_obj_t *ui_Screen4_Label1;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=1
    #error "LV_COLOR_16_SWAP should be 1 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////

///////////////////// SCREENS ////////////////////
void ui_Screen1_screen_init(void)
{
ui_Screen1 = lv_obj_create(NULL);
lv_obj_clear_flag( ui_Screen1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Screen1_Arc_Temps = lv_arc_create(ui_Screen1);
lv_obj_set_width( ui_Screen1_Arc_Temps, 128);
lv_obj_set_height( ui_Screen1_Arc_Temps, 128);
lv_obj_set_align( ui_Screen1_Arc_Temps, LV_ALIGN_CENTER );
lv_arc_set_range(ui_Screen1_Arc_Temps, -1,50);
lv_arc_set_value(ui_Screen1_Arc_Temps, 0);
lv_arc_set_bg_angles(ui_Screen1_Arc_Temps,265,180);
lv_obj_set_style_arc_width(ui_Screen1_Arc_Temps, 11, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_arc_color(ui_Screen1_Arc_Temps, lv_color_hex(0xFF6565), LV_PART_INDICATOR | LV_STATE_DEFAULT );
lv_obj_set_style_arc_opa(ui_Screen1_Arc_Temps, 255, LV_PART_INDICATOR| LV_STATE_DEFAULT);
lv_obj_set_style_arc_width(ui_Screen1_Arc_Temps, 11, LV_PART_INDICATOR| LV_STATE_DEFAULT);

lv_obj_set_style_bg_color(ui_Screen1_Arc_Temps, lv_color_hex(0xFF6565), LV_PART_KNOB | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Screen1_Arc_Temps, 255, LV_PART_KNOB| LV_STATE_DEFAULT);
lv_obj_set_style_pad_left(ui_Screen1_Arc_Temps, 0, LV_PART_KNOB| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_Screen1_Arc_Temps, 0, LV_PART_KNOB| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_Screen1_Arc_Temps, 0, LV_PART_KNOB| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_Screen1_Arc_Temps, 0, LV_PART_KNOB| LV_STATE_DEFAULT);

ui_Screen1_Arc_Humid = lv_arc_create(ui_Screen1);
lv_obj_set_width( ui_Screen1_Arc_Humid, 100);
lv_obj_set_height( ui_Screen1_Arc_Humid, 100);
lv_obj_set_align( ui_Screen1_Arc_Humid, LV_ALIGN_CENTER );
lv_arc_set_range(ui_Screen1_Arc_Humid, -2,100);
lv_arc_set_value(ui_Screen1_Arc_Humid, 0);
lv_arc_set_bg_angles(ui_Screen1_Arc_Humid,263,180);
lv_obj_set_style_arc_width(ui_Screen1_Arc_Humid, 11, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_arc_color(ui_Screen1_Arc_Humid, lv_color_hex(0x6565FF), LV_PART_INDICATOR | LV_STATE_DEFAULT );
lv_obj_set_style_arc_opa(ui_Screen1_Arc_Humid, 255, LV_PART_INDICATOR| LV_STATE_DEFAULT);
lv_obj_set_style_arc_width(ui_Screen1_Arc_Humid, 11, LV_PART_INDICATOR| LV_STATE_DEFAULT);

lv_obj_set_style_bg_color(ui_Screen1_Arc_Humid, lv_color_hex(0x6565FF), LV_PART_KNOB | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Screen1_Arc_Humid, 255, LV_PART_KNOB| LV_STATE_DEFAULT);
lv_obj_set_style_pad_left(ui_Screen1_Arc_Humid, 0, LV_PART_KNOB| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_Screen1_Arc_Humid, 0, LV_PART_KNOB| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_Screen1_Arc_Humid, 0, LV_PART_KNOB| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_Screen1_Arc_Humid, 0, LV_PART_KNOB| LV_STATE_DEFAULT);

ui_Screen1_Arc_Air_Q = lv_arc_create(ui_Screen1);
lv_obj_set_width( ui_Screen1_Arc_Air_Q, 72);
lv_obj_set_height( ui_Screen1_Arc_Air_Q, 72);
lv_obj_set_align( ui_Screen1_Arc_Air_Q, LV_ALIGN_CENTER );
lv_arc_set_value(ui_Screen1_Arc_Air_Q, 100);
lv_arc_set_bg_angles(ui_Screen1_Arc_Air_Q,260,180);
lv_arc_set_mode(ui_Screen1_Arc_Air_Q, LV_ARC_MODE_REVERSE);
lv_obj_set_style_arc_color(ui_Screen1_Arc_Air_Q, lv_color_hex(0x65FF65), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_arc_opa(ui_Screen1_Arc_Air_Q, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_arc_width(ui_Screen1_Arc_Air_Q, 11, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_arc_color(ui_Screen1_Arc_Air_Q, lv_color_hex(0x327F32), LV_PART_INDICATOR | LV_STATE_DEFAULT );
lv_obj_set_style_arc_opa(ui_Screen1_Arc_Air_Q, 255, LV_PART_INDICATOR| LV_STATE_DEFAULT);
lv_obj_set_style_arc_width(ui_Screen1_Arc_Air_Q, 11, LV_PART_INDICATOR| LV_STATE_DEFAULT);

lv_obj_set_style_bg_color(ui_Screen1_Arc_Air_Q, lv_color_hex(0x327F32), LV_PART_KNOB | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Screen1_Arc_Air_Q, 255, LV_PART_KNOB| LV_STATE_DEFAULT);
lv_obj_set_style_pad_left(ui_Screen1_Arc_Air_Q, 0, LV_PART_KNOB| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_Screen1_Arc_Air_Q, 0, LV_PART_KNOB| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_Screen1_Arc_Air_Q, 0, LV_PART_KNOB| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_Screen1_Arc_Air_Q, 0, LV_PART_KNOB| LV_STATE_DEFAULT);

ui_Screen1_Label1 = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_Screen1_Label1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Screen1_Label1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Screen1_Label1, -76 );
lv_obj_set_y( ui_Screen1_Label1, -59 );
lv_obj_set_align( ui_Screen1_Label1, LV_ALIGN_RIGHT_MID );
lv_label_set_text(ui_Screen1_Label1,"Temps.");
lv_obj_set_style_text_color(ui_Screen1_Label1, lv_color_hex(0xFF6565), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Screen1_Label1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Screen1_Label1, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Screen1_Label1, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Screen1_Label2 = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_Screen1_Label2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Screen1_Label2, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Screen1_Label2, -76 );
lv_obj_set_y( ui_Screen1_Label2, -45 );
lv_obj_set_align( ui_Screen1_Label2, LV_ALIGN_RIGHT_MID );
lv_label_set_text(ui_Screen1_Label2,"Humid.");
lv_obj_set_style_text_color(ui_Screen1_Label2, lv_color_hex(0x6565FF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Screen1_Label2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Screen1_Label2, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Screen1_Label3 = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_Screen1_Label3, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Screen1_Label3, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Screen1_Label3, -76 );
lv_obj_set_y( ui_Screen1_Label3, -31 );
lv_obj_set_align( ui_Screen1_Label3, LV_ALIGN_RIGHT_MID );
lv_label_set_text(ui_Screen1_Label3,"Air Q.");
lv_obj_set_style_text_color(ui_Screen1_Label3, lv_color_hex(0x65FF65), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Screen1_Label3, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Screen1_Label3, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Screen1_Label4 = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_Screen1_Label4, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Screen1_Label4, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Screen1_Label4, -76 );
lv_obj_set_y( ui_Screen1_Label4, -16 );
lv_obj_set_align( ui_Screen1_Label4, LV_ALIGN_RIGHT_MID );
lv_label_set_text(ui_Screen1_Label4,"Pressu.");
lv_obj_set_style_text_font(ui_Screen1_Label4, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Screen1_Label_Temps = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_Screen1_Label_Temps, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Screen1_Label_Temps, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Screen1_Label_Temps, 57 );
lv_obj_set_y( ui_Screen1_Label_Temps, -59 );
lv_obj_set_align( ui_Screen1_Label_Temps, LV_ALIGN_LEFT_MID );
lv_label_set_text(ui_Screen1_Label_Temps,"0");
lv_obj_set_style_text_color(ui_Screen1_Label_Temps, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Screen1_Label_Temps, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Screen1_Label_Temps, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Screen1_Label_Humid = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_Screen1_Label_Humid, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Screen1_Label_Humid, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Screen1_Label_Humid, 57 );
lv_obj_set_y( ui_Screen1_Label_Humid, -45 );
lv_obj_set_align( ui_Screen1_Label_Humid, LV_ALIGN_LEFT_MID );
lv_label_set_text(ui_Screen1_Label_Humid,"0");
lv_obj_set_style_text_color(ui_Screen1_Label_Humid, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Screen1_Label_Humid, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Screen1_Label_Humid, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Screen1_Label_Air_Q = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_Screen1_Label_Air_Q, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Screen1_Label_Air_Q, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Screen1_Label_Air_Q, 57 );
lv_obj_set_y( ui_Screen1_Label_Air_Q, -31 );
lv_obj_set_align( ui_Screen1_Label_Air_Q, LV_ALIGN_LEFT_MID );
lv_label_set_text(ui_Screen1_Label_Air_Q,"0");
lv_obj_set_style_text_color(ui_Screen1_Label_Air_Q, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Screen1_Label_Air_Q, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Screen1_Label_Air_Q, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Screen1_Label_Pressu = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_Screen1_Label_Pressu, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Screen1_Label_Pressu, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Screen1_Label_Pressu, 0 );
lv_obj_set_y( ui_Screen1_Label_Pressu, 6 );
lv_obj_set_align( ui_Screen1_Label_Pressu, LV_ALIGN_CENTER );
lv_label_set_text(ui_Screen1_Label_Pressu,"1013.25\nhPa");
lv_obj_set_style_text_align(ui_Screen1_Label_Pressu, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Screen1_Label_Pressu, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);

}
void ui_Screen2_screen_init(void)
{
ui_Screen2 = lv_obj_create(NULL);
lv_obj_clear_flag( ui_Screen2, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Screen2_Chart1 = lv_chart_create(ui_Screen2);
lv_obj_set_width( ui_Screen2_Chart1, 100);
lv_obj_set_height( ui_Screen2_Chart1, 100);
lv_obj_set_x( ui_Screen2_Chart1, 10 );
lv_obj_set_y( ui_Screen2_Chart1, 10 );
lv_obj_set_align( ui_Screen2_Chart1, LV_ALIGN_CENTER );

ui_Screen2_Label1 = lv_label_create(ui_Screen2);
lv_obj_set_width( ui_Screen2_Label1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Screen2_Label1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Screen2_Label1, 0 );
lv_obj_set_y( ui_Screen2_Label1, -52 );
lv_obj_set_align( ui_Screen2_Label1, LV_ALIGN_CENTER );
lv_label_set_text(ui_Screen2_Label1,"Temperature");
lv_obj_set_style_text_color(ui_Screen2_Label1, lv_color_hex(0xFF6565), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Screen2_Label1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Screen2_Label1, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

}
void ui_Screen3_screen_init(void)
{
ui_Screen3 = lv_obj_create(NULL);
lv_obj_clear_flag( ui_Screen3, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Screen3_Chart1 = lv_chart_create(ui_Screen3);
lv_obj_set_width( ui_Screen3_Chart1, 96);
lv_obj_set_height( ui_Screen3_Chart1, 100);
lv_obj_set_x( ui_Screen3_Chart1, 12 );
lv_obj_set_y( ui_Screen3_Chart1, 10 );
lv_obj_set_align( ui_Screen3_Chart1, LV_ALIGN_CENTER );

ui_Screen3_Label1 = lv_label_create(ui_Screen3);
lv_obj_set_width( ui_Screen3_Label1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Screen3_Label1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Screen3_Label1, 0 );
lv_obj_set_y( ui_Screen3_Label1, -52 );
lv_obj_set_align( ui_Screen3_Label1, LV_ALIGN_CENTER );
lv_label_set_text(ui_Screen3_Label1,"Humidity");
lv_obj_set_style_text_color(ui_Screen3_Label1, lv_color_hex(0x6565FF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Screen3_Label1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Screen3_Label1, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

}
void ui_Screen4_screen_init(void)
{
ui_Screen4 = lv_obj_create(NULL);
lv_obj_clear_flag( ui_Screen4, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Screen4_Chart1 = lv_chart_create(ui_Screen4);
lv_obj_set_width( ui_Screen4_Chart1, 96);
lv_obj_set_height( ui_Screen4_Chart1, 100);
lv_obj_set_x( ui_Screen4_Chart1, 12 );
lv_obj_set_y( ui_Screen4_Chart1, 10 );
lv_obj_set_align( ui_Screen4_Chart1, LV_ALIGN_CENTER );

ui_Screen4_Label1 = lv_label_create(ui_Screen4);
lv_obj_set_width( ui_Screen4_Label1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Screen4_Label1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Screen4_Label1, 0 );
lv_obj_set_y( ui_Screen4_Label1, -52 );
lv_obj_set_align( ui_Screen4_Label1, LV_ALIGN_CENTER );
lv_label_set_text(ui_Screen4_Label1,"Air Quality");
lv_obj_set_style_text_color(ui_Screen4_Label1, lv_color_hex(0x65FF65), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Screen4_Label1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Screen4_Label1, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

}

void ui_init( void )
{
lv_disp_t *dispp = lv_disp_get_default();
lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
lv_disp_set_theme(dispp, theme);
ui_Screen1_screen_init();
ui_Screen2_screen_init();
ui_Screen3_screen_init();
ui_Screen4_screen_init();
lv_disp_load_scr( ui_Screen1);
}
