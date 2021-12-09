#pragma once

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
// #include "esp_spi_flash.h"

#define pdSECOND pdMS_TO_TICKS(1000)

class Main final {
    public: 
        esp_err_t setup(void);
        void loop(void);
};