#pragma once

#include "driver/gpio.h"

namespace Gpio 
{

class GpioBase {

    const gpio_pin_t _pin;
    const bool _inverted_logic = false;
    const gpio_config_t _cfg;

    public: 
        GpioBase(const gpio_pin_t pin, 
                    const gpio_config_& config, 
                    const bool _invert_logic = false) :
                _pin{pin},
                _cfg{config},
                _inverted_logic{invert_logic}
                {
                    
                }

        virtual bool state(void)=0;
        virtual esp_err_t set(const bool state)=0;

        esp_err_t init(void);


};
class GpioOutput {
    bool _state = false;
    const bool _inverted_logic = false;
    const gpio_num_t _pin

    public:
        constexpr GpioOutput(const gpio_num_t pin,const bool invert = false) :
            _inverted_logic{invert},
            _pin(pin)
            {

            }


        esp_err_t init(void);
        esp_err_t set(const bool state);
        esp_err_t toggle(void);
        bool state(void){return _state; }


}
class GpioInput {
    gpio_pin_t _pin;
    const bool _inverted_logic = false;

    public:
    esp_err_t init(void);
    bool state(void);
}
} // namespace GPIO