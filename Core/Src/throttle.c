#include "tx_api.h"
#include "throttle.h"



int servo_init( void ) {
    // pot0 = PA0
    GPIO_InitTypeDef init_struct = {0};
    init_struct.Pin = GPIO_PIN_0
    // mode is push-pull, but Analog?
    init_struct.Mode = GPIO_MODE_ANALOG;
    init_struct.Pull = GPIO_NOPULL;
    init_struct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA, &init_struct)

    // pot1 = PA1

}

void task_poll_servo( void ) {
    servo_init();

}