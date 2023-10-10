#include "BlinkyLightTask.h"

BlinkyLightTaskState current_thread_state;

static void Blink_Shit( void ) {
    /* Put implementation here */
}

void BlinkyLightTaskControlLoop( void ) {

    switch(current_thread_state){

        case BLINK:
            Blink_Shit();
            break;

        case DO_OTHER_STUFF:
            /* Nothing here */
            
            break;

        default:
            /* Program execution should never reach this point ! */

            break;
    }
}