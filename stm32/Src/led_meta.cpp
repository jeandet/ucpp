/**
 ******************************************************************************
 * @file    main.c
 * @author  Auto-generated by STM32CubeIDE
 * @version V1.0
 * @brief   Default main function.
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning                                                                                           \
    "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "../../ucpp/register.hpp"
#include "../../ucpp/stm32/gpio.hpp"
#include "../../ucpp/stm32/rcc.hpp"
#include "../../ucpp/stm32/stm32f7.hpp"

using namespace ucpp;
using namespace ucpp::stm32;
using namespace ucpp::gpio;
// LED on PB8

int main(void)
{
    rcc::enable_clock(stm32f7, stm32f7.GPIOB);
    set_direction(stm32f7, GPIOB8, stm32::gpio::mode::output);
    for (;;)
    {
        stm32f7.GPIOB.od.get<8>() = !stm32f7.GPIOB.od.get<8>();
        //stm32f7.GPIOB.od = stm32f7.GPIOB.od xor (1<<8);
        for (volatile int i = 0; i < 1024 * 1024 * 2; i++)
            ;
    }
}
