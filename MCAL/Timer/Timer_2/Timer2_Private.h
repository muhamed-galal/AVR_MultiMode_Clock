/*
 * Timer2_Private.h
 *
 *  Created on: Apr 1, 2023
 *      Author: MIX
 */

#ifndef MCAL_TIMER_TIMER_2_TIMER2_PRIVATE_H_
#define MCAL_TIMER_TIMER_2_TIMER2_PRIVATE_H_

#define OCR2_REG      (*(volatile u8*)0x43)
#define TCNT2_REG     (*(volatile u8*)0x44)
#define TCCR2_REG     (*(volatile u8*)0x45)
#define TIMSK_REG     (*(volatile u8*)0x59)
#define SREG_REG      (*(volatile u8*)0x5F)



#define TIMER_PRESCALING_NO_CLOCK     0
#define TIMER_PRESCALING_NO_SCALE     1
#define TIMER_PRESCALING_8            2
#define TIMER_PRESCALING_32           3
#define TIMER_PRESCALING_64           4
#define TIMER_PRESCALING_128          5
#define TIMER_PRESCALING_256          6
#define TIMER_PRESCALING_1024         7

#define TIMER_NORMAL_MODE                  0
#define TIMER_PWM_MODE                     1
#define TIMER_CTC_MODE                     2
#define TIMER_FAST_PWM_MODE                3


#define TIMER_INTURRUPT    0
#define TIMER_POLLING      1







#endif /* MCAL_TIMER_TIMER_2_TIMER2_PRIVATE_H_ */
