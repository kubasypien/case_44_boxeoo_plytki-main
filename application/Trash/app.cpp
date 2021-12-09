#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "app.hpp"
#include "active_leds.hpp"
#include "driver/gpio.h"


Adafruit_NeoPixel App::strip(led_consts::led_count, led_consts::one_wire_led_pin, NEO_GRBW + NEO_KHZ800);

void App::main_function(){
    strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
    strip.show();            
    strip.setBrightness(led_consts::brightness);
    //int distance = 0;

    //Serial.begin(115200); 
    //sonic_sensor.begin(9600); 
            
    //rgbw_colors::rgbw_color color = rgbw_colors::rgbw_color::MAX;
    //unsigned animation_params[]{ 1, 30, 50, reinterpret_cast<unsigned>(&color) };

    //xTaskCreatePinnedToCore(led_strip_task, "animation task", 20000, reinterpret_cast<void*>(animation_params), 0, NULL, 0);

    /*while(1){
        auto tmp_dist = get_distance(sonic_sensor);
        if(tmp_dist > 0){
            distance = 0.9 * distance + 0.1 * tmp_dist;
        }


        Serial.print("Distance: ");
        Serial.print(distance);
        Serial.println("cm");
    }
    */
} 

void App::forward_running_led(int active_n, int wait, rgbw_colors::rgbw_color c){
    while(1){
        active_leds current_led = active_leds{ (uint8_t)active_n };
        rgbw_colors::rgbw_color tmp;

        for(int j = 0; j < led_consts::led_count; ++j){
            if(j > (led_consts::led_count - current_led.len())){
                break;
            }
            for(int k = 0; k < led_consts::led_count; ++k){
                if(current_led == k){
                    tmp = c;
                }
                else{
                    tmp = rgbw_colors::rgbw_color::NONE;
                }
                strip.setPixelColor(k, rgbw_colors::Color(tmp));
                }

            strip.show();
            vTaskDelay(wait/portTICK_PERIOD_MS);
            current_led++;
        }
    }
}

void App::back_and_forth_running_led(int active_n, int wait, rgbw_colors::rgbw_color c){
    while(1){
        active_leds current_led = active_leds{ (uint8_t)active_n };
        rgbw_colors::rgbw_color tmp;

        for(int j = 0; j < led_consts::led_count; ++j){
            if(j > (led_consts::led_count - current_led.len())){
                break;
            }
            for(int k = 0; k < led_consts::led_count; ++k){
                if(current_led == k){
                    tmp = c;
                }
                else{
                    tmp = rgbw_colors::rgbw_color::NONE;
                }
                strip.setPixelColor(k, rgbw_colors::Color(tmp));
                }

                strip.show();
                vTaskDelay(wait/portTICK_PERIOD_MS);
                current_led++;
            }

            current_led--;

        for(int j = led_consts::led_count - 1; j >= 0; --j){
            if(j < (current_led.len())){
                break;
            }
            for(int k = led_consts::led_count - 1; k >= 0; --k){
                if(current_led == k){
                    tmp = c;
                }
                else{
                    tmp = rgbw_colors::rgbw_color::NONE;
                }
                strip.setPixelColor(k, rgbw_colors::Color(tmp));
            }

            strip.show();
            vTaskDelay(wait/portTICK_PERIOD_MS);
            current_led--;
        }
    }
}

void App::circle(int active_n, int wait, rgbw_colors::rgbw_color c){
    active_leds current_led = active_leds{ (uint8_t)active_n };
    rgbw_colors::rgbw_color tmp;

    for(int j = 0; ; ++j){
        if(j >= led_consts::led_count) j = 0;
        for(int k = 0; k < led_consts::led_count; ++k){
            if(current_led == k){
                tmp = c;
            }
            else{
                tmp = rgbw_colors::rgbw_color::NONE;
            }

            strip.setPixelColor(k, rgbw_colors::Color(tmp));
            current_led.shift_index(led_consts::led_count);
        }

        strip.show();
        vTaskDelay(wait/portTICK_PERIOD_MS);
        current_led++;
    }

}