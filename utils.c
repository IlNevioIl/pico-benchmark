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
    int percentage = currentLoop / 100; // :100 because we have 10.000 loops in total
    switch(percentage) {
	    case 10: printf("\rStatus: #--------- | 10%%"); fflush(stdout); break;
        case 20: printf("\rStatus: ##-------- | 20%%"); fflush(stdout); break;
        case 30: printf("\rStatus: ###------- | 30%%"); fflush(stdout); break;
        case 40: printf("\rStatus: ####------ | 40%%"); fflush(stdout); break;
        case 50: printf("\rStatus: #####----- | 50%%"); fflush(stdout); break;
        case 60: printf("\rStatus: ######---- | 60%%"); fflush(stdout); break;
        case 70: printf("\rStatus: #######--- | 70%%"); fflush(stdout); break;
        case 80: printf("\rStatus: ########-- | 80%%"); fflush(stdout); break;
        case 90: printf("\rStatus: #########- | 90%%"); fflush(stdout); break;
        case 100: printf("\rStatus: ########## | Done\n\n"); break;
	default: break;
}
}