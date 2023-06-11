/*
 * EXTI_config.h
 *
 *  Created on: Apr 16, 2023
 *      Author: Muham
 */

#ifndef MCAL_EXTI_EXTI_CONFIG_H_
#define MCAL_EXTI_EXTI_CONFIG_H_

/* Options:
  			1- LOW_LEVEL
  			2- ON_CHANGE
  			3- FALLING_EDGE
  			4- RISING_EDGE
 */
#define INT0_SENSE			FALLING_EDGE
/* Options:
  			1- LOW_LEVEL
  			2- ON_CHANGE
  			3- FALLING_EDGE
  			4- RISING_EDGE
 */
#define INT1_SENSE			FALLING_EDGE
/* Options:
  			1- FALLING_EDGE
  			2- RISING_EDGE
 */
#define INT2_SENSE			FALLING_EDGE

/* Options:
 	 	 	 1-ENABLED
 	 	 	 2-DISABLED
 */
#define INT0_INITIAL_STATE	ENABLED
#define INT1_INITIAL_STATE	DISABLED
#define INT2_INITIAL_STATE	DISABLED


#endif /* MCAL_EXTI_EXTI_CONFIG_H_ */
