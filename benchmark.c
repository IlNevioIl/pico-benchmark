#include <stdio.h>
#include "pico/stdlib.h"
#include "numbers.h"
#include "utils.h"

int main(void){

    //Todo: split everything into different files, print cpu temp/cpu clock speed, implement an system that allows easy overclocking to check the results, add a progressbar or %

    stdio_init_all();
    
    uint16_t temp, totaltime;

    sleep_ms(5000); //Waiting so user can connect pico to Putty
    //float cpu = get_CPU_temp();
    //printf("CPU Temp: %d\n", cpu);
    printf("Starting benchmark now...\n\n");

    //Check the milliseconds since boot
    absolute_time_t t1 = get_absolute_time();
    uint32_t time1 = to_ms_since_boot(t1);

    for (int i = 0; i <= 10000; i++) //Loop 10.000 times
    {
        for (int j = 0; j <= 9998; j++) //Looping though the 10000 size array (9998 because we check the next existing number (array[j+1]) and this doesnt exist if we are checking the last number at array[9999]) array[10000] does not exist since we start counting at 0
        {
            if (numbers[j] > numbers[j+1]) //O(n) bubble sort
            {
                //Swap numbers
                temp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = temp;
            }
        }
    }
    //Check the milliseconds since boot for a second time
    absolute_time_t t2 = get_absolute_time();
    uint32_t time2 = to_ms_since_boot(t2);

    //Calculating how long it takes to sort the array
    totaltime = time2 - time1;
    printf("Benchmark score: %d (ms)\n\n", totaltime);
    printf("The lower the score, the better the pico\n");
    printf("Please star the github repo if this was useful :)\n");

    //Printing the hole array
    /*for (int i = 0; i <= 9999; i++)
    {
        printf("%d ", numbers[i]);
    }*/
    return 0;
}