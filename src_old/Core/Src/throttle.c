#include "tx_api.h"
#include "throttle.h"



int servo_init( void ) {
    // pot0 = PA0
    GPIO_InitTypeDef throttle_init_a = {0};
    throttle_init_a.Pin = GPIO_PIN_0;
    // mode is push-pull, but Analog?
    throttle_init_a.Mode = GPIO_MODE_ANALOG;
    throttle_init_a.Pull = GPIO_NOPULL;
    throttle_init_a.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA, &throttle_init_a);

    // pot1 = PA1
    GPIO_InitTypeDef throttle_init_b = {0};
    throttle_init_b.Pin = GPIO_PIN_1;
    // mode is push-pull, but Analog?
    throttle_init_b.Mode = GPIO_MODE_ANALOG;
    throttle_init_b.Pull = GPIO_NOPULL;
    throttle_init_b.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA, &throttle_init_b);

    // servo0 = PA2
    GPIO_InitTypeDef servo_init_a = {0};
    servo_init_a.Pin = GPIO_PIN_2;
    servo_init_a.Mode = GPIO_MODE_AF_PP;
    servo_init_a.Pull = GPIO_NOPULL;
    servo_init_a.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA, &servo_init_a);

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
}

void task_poll_servo( void ) {
    servo_init();

}

/**
 * gets the average of the two pots in Volts
*/
double pot_avg(){
    double volt_avg;
    __UINT32_t pot0 = GPIO_PIN_0; //I know wrong just a placeholder
    __UINT32_t pot1 = GPIO_PIN_1; //I know wrong just a placeholder

    // Get ADC value
    HAL_ADC_Start(&pot0);
    HAL_ADC_PollForConversion(&pot0, HAL_MAX_DELAY);
    int value0 = HAL_ADC_GetValue(&pot0);

    HAL_ADC_Start(&pot1);
    HAL_ADC_PollForConversion(&pot1, HAL_MAX_DELAY);
    int value1 = HAL_ADC_GetValue(&pot1);

    //converts reading into volts
    pot0 = (3.3 / 4095) * pot0;
    pot1 = (3.3 / 4095) * pot1;

    volt_avg = (pot0 + pot1)/2;

    return volt_avg;
}