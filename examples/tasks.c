#include "tx_api.h"
#include "BlinkyLightTask.h"

#define BYTES_TO_ALLOC_TO_BLINKY_THREAD 1024
#define BLINKY_LIGHT_TASK_PRIORITY 1

uint8_t BlinkyLightTaskStack[BYTES_TO_ALLOC_TO_BLINKY_THREAD];

TX_THREAD BlinkyLightTaskThread;
void BlinkyLightTask( void ) {

    while(1) {

        BlinkyLightTaskControlLoop();

    }

    tx_thread_sleep(10);

}

void Setup_Tasks( void ) {

    /* Setup memory registry for thread */
    tx_thread_create(   &BlinkyLightTaskThread, 
                        "Blink light task",
                        BlinkyLightTask,
                        NULL,
                        (void *) BlinkyLightTaskStack,
                        BYTES_TO_ALLOC_TO_BLINKY_THREAD,
                        BLINKY_LIGHT_TASK_PRIORITY,
                        BLINKY_LIGHT_TASK_PRIORITY,
                        TX_NO_TIME_SLICE);

    tx_kernel_enter(); /* START THE OS */

}