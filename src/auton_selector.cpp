#include "liblvgl/core/lv_disp.h"
#include "liblvgl/core/lv_obj.h"
#include "liblvgl/core/lv_obj_pos.h"
#include "liblvgl/lvgl.h"
#include "auton_selector.h"
#include "liblvgl/misc/lv_color.h"


static void button_pressed(lv_event_t * event) {
    lv_obj_set_style_bg_color(lv_scr_act(), lv_color_hex(0xff0000), LV_PART_MAIN);
}

void set_brain_screen(void)
{
    // Set background color
    lv_obj_set_style_bg_color(lv_scr_act(), lv_color_hex(0xffffff), LV_PART_MAIN);

    lv_obj_t * button = lv_obj_create(lv_scr_act());

    lv_obj_align(button, LV_ALIGN_CENTER, 0, 0);

    //lv_obj_add_event_cb(button, button_pressed, LV_EVENT_CLICKED, NULL);

}