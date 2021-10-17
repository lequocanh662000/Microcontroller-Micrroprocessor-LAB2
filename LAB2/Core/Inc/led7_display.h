/*
 * led7seg_display.h
 *
 *  Created on: Oct 2, 2021
 *      Author: Dell
 */
#include "stdint.h"
#ifndef INC_LED7SEG_DISPLAY_H_
#define INC_LED7SEG_DISPLAY_H_


#define DISABLE_7SEG_1				GPIO_PIN_2
#define DISABLE_7SEG_1_PORT			GPIOA
#define DISABLE_7SEG_2				GPIO_PIN_3
#define DISABLE_7SEG_2_PORT			GPIOA
#define DISABLE_7SEG_3				GPIO_PIN_6
#define DISABLE_7SEG_3_PORT			GPIOA
#define DISABLE_7SEG_4				GPIO_PIN_7
#define DISABLE_7SEG_4_PORT			GPIOA



#define SEVEN_SEGMENT_1_A 			GPIO_PIN_8
#define SEVEN_SEGMENT_1_A_PORT 		GPIOB
#define SEVEN_SEGMENT_1_B 			GPIO_PIN_9
#define SEVEN_SEGMENT_1_B_PORT 		GPIOB
#define SEVEN_SEGMENT_1_C 			GPIO_PIN_10
#define SEVEN_SEGMENT_1_C_PORT 		GPIOB
#define SEVEN_SEGMENT_1_D 			GPIO_PIN_11
#define SEVEN_SEGMENT_1_D_PORT 		GPIOB
#define SEVEN_SEGMENT_1_E 			GPIO_PIN_12
#define SEVEN_SEGMENT_1_E_PORT 		GPIOB
#define SEVEN_SEGMENT_1_F 			GPIO_PIN_13
#define SEVEN_SEGMENT_1_F_PORT 		GPIOB
#define SEVEN_SEGMENT_1_G 			GPIO_PIN_14
#define SEVEN_SEGMENT_1_G_PORT 		GPIOB
#define SEVEN_SEGMENT_1_H 			GPIO_PIN_15
#define SEVEN_SEGMENT_1_H_PORT 		GPIOB



void update_seven_segment_led_buffer(uint8_t index,uint8_t value);
void seven_segment_led_driver(void);
void updateClockBuffer(int hour, int min);



#endif /* INC_LED7SEG_DISPLAY_H_ */
