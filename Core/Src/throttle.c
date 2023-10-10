#include "tx_api.h"
#include "throttle.h"



int servo_init( void ) {
    // pot0 = PA0
    GPIO_InitTypeDef throttle_init_a = {0};
    throttle_init_a.Pin = GPIO_PIN_0
    // mode is push-pull, but Analog?
    throttle_init_a.Mode = GPIO_MODE_ANALOG;
    throttle_init_a.Pull = GPIO_NOPULL;
    throttle_init_a.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA, &throttle_init_a)

    // pot1 = PA1
    GPIO_InitTypeDef throttle_init_b = {0};
    throttle_init_b.Pin = GPIO_PIN_1
    // mode is push-pull, but Analog?
    throttle_init_b.Mode = GPIO_MODE_ANALOG;
    throttle_init_b.Pull = GPIO_NOPULL;
    throttle_init_b.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA, &throttle_init_b)

}

void task_poll_servo( void ) {
    servo_init();

}