/*
Copyright 2026 cha1n0oO <https://github.com/cha1n0oO>
Copyright 2026 Clack Chen

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#ifdef RGB_MATRIX_ENABLE

/* clang-format off */
led_config_t g_led_config = {
{
        

    {0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10,  11,  12,  13, 14},
    {28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, NO_LED, 15},
    {29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, NO_LED, NO_LED},
    {54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, NO_LED, NO_LED, 42},
    {NO_LED, 55, 56, NO_LED, NO_LED, 57, NO_LED, NO_LED, NO_LED, NO_LED, 58, 59, NO_LED, NO_LED}

}, {
    {0,0}, {17,0}, {34,0}, {52,0}, {69,0}, {86,0}, {103,0}, {121,0}, {138,0}, {155,0}, {172,0}, {190,0}, {207,0}, {224,0}, {238,0},
    {0,16}, {17,16}, {34,16}, {52,16}, {69,16}, {86,16}, {103,16}, {121,16}, {138,16}, {155,16}, {172,16}, {190,16}, {207,16}, {238,16},
    {0,32}, {17,32}, {34,32}, {52,32}, {69,32}, {86,32}, {103,32}, {121,32}, {138,32}, {155,32}, {172,32}, {190,32}, {207,32},
    {0,48}, {17,48}, {34,48}, {52,48}, {69,48}, {86,48}, {103,48}, {121,48}, {138,48}, {155,48}, {172,48}, {190,48}, {238,48},
    {17,64}, {34,64}, {86,64}, {172,64}, {190,64}
},
{
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4
}

};
/* clang-format on */

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max)
{
    if (led_min <= 29 && led_max > 29 && host_keyboard_led_state().caps_lock)
    {
        RGB_MATRIX_INDICATOR_SET_COLOR(29, 0xFF, 0x00, 0x00);
    }

    return true;
}

#endif

int main()
{
    extern void protocol_setup();
    extern void protocol_pre_init();
    extern void protocol_post_init();
    extern void platform_run();

    platform_setup();

    protocol_setup();
#if !defined ESB_ENABLE || ESB_ENABLE != 2
    keyboard_setup();
#endif

    protocol_pre_init();
    keyboard_init();
    protocol_post_init();

    /* Main loop */
    for (;;)
    {
        platform_run();
        //! housekeeping_task() is handled by platform
    }
}