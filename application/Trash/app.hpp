#ifndef app_h
#define app_h
#include "Adafruit_NeoPixel.h"
#include "colors.h"
#include "active_leds.hpp"

namespace led_consts{
    constexpr uint8_t one_wire_led_pin{ 13 };
    constexpr uint8_t led_count{ 30 };
    constexpr uint8_t brightness{ 255 };
};

class App{
public:
    static Adafruit_NeoPixel strip;

    static void main_function();
    static void forward_running_led(int active_n, int wait, rgbw_colors::rgbw_color c);
    static void back_and_forth_running_led(int active_n, int wait, rgbw_colors::rgbw_color c);
    static void circle(int active_n, int wait, rgbw_colors::rgbw_color c);
};

#endif