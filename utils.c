#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

float get_CPU_temp(void){
    adc_init();  
    adc_set_temp_sensor_enabled(true);
    adc_select_input(4);
    uint16_t raw = adc_read();
    adc_set_temp_sensor_enabled(false);
    const float conversion = 3.3f / (1<<12); //Devide by 12bit value (65535)
    float voltage = raw * conversion;
    float temp = 27 - (voltage - 0.706)/0.001721;
    float cpuTemp = temp; //Have to do this because it will return the voltage otherwise (idk why)
    return cpuTemp;
} 

void progressbar_check(int currentLoop) {
    //Todo: Make this not hard coded and actually a progressbar
    switch(currentLoop) {
	    case 1000: printf("10%% done\n"); break;
        case 2000: printf("20%% done\n"); break;
        case 3000: printf("30%% done\n"); break;
        case 4000: printf("40%% done\n"); break;
        case 5000: printf("50%% done\n"); break;
        case 6000: printf("60%% done\n"); break;
        case 7000: printf("70%% done\n"); break;
        case 8000: printf("80%% done\n"); break;
        case 9000: printf("90%% done\n"); break;
	default: break;
}
}