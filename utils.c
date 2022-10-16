#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

float get_CPU_temp(void){
    adc_init();
    adc_set_temp_sensor_enabled(true);
    adc_select_input(4);
    uint16_t raw = adc_read();
    const float conversion = 3.3f / (1<<12); //Devide by 12bit value (65535)
    float voltage = raw * conversion;
    float temp = 27 - (voltage - 0.706)/0.001721;
    adc_set_temp_sensor_enabled(false);
    return temp;
} 