/*
 * 8x8matrix_display.h
 *
 *  Created on: Oct 8, 2021
 *      Author: Dell
 */

#ifndef INC_8X8MATRIX_DISPLAY_H_
#define INC_8X8MATRIX_DISPLAY_H_
// using column scan
#define DISABLE_COL_8x8_1			GPIO_PIN_8
#define DISABLE_COL_8x8_1_PORT 		GPIOA
#define DISABLE_COL_8x8_2			GPIO_PIN_9
#define DISABLE_COL_8x8_2_PORT 		GPIOA
#define DISABLE_COL_8x8_3			GPIO_PIN_10
#define DISABLE_COL_8x8_3_PORT 		GPIOA
#define DISABLE_COL_8x8_4			GPIO_PIN_11
#define DISABLE_COL_8x8_4_PORT 		GPIOA
#define DISABLE_COL_8x8_5			GPIO_PIN_12
#define DISABLE_COL_8x8_5_PORT 		GPIOA
#define DISABLE_COL_8x8_6			GPIO_PIN_13
#define DISABLE_COL_8x8_6_PORT 		GPIOA
#define DISABLE_COL_8x8_7			GPIO_PIN_14
#define DISABLE_COL_8x8_7_PORT 		GPIOA
#define DISABLE_COL_8x8_8			GPIO_PIN_15
#define DISABLE_COL_8x8_8_PORT 		GPIOA
// define row
#define ROW1						GPIO_PIN_0
#define ROW1_PORT					GPIOB
#define ROW2						GPIO_PIN_1
#define ROW2_PORT					GPIOB
#define ROW3						GPIO_PIN_2
#define ROW3_PORT					GPIOB
#define ROW4						GPIO_PIN_3
#define ROW4_PORT					GPIOB
#define ROW5						GPIO_PIN_4
#define ROW5_PORT					GPIOB
#define ROW6						GPIO_PIN_5
#define ROW6_PORT					GPIOB
#define ROW7						GPIO_PIN_6
#define ROW7_PORT					GPIOB
#define ROW8						GPIO_PIN_7
#define ROW8_PORT					GPIOB

void update_row_matrix_8x8_led_buffer(uint8_t column_index);
void matrix8x8_led_driver(void);

void display_matrix8x8_led(void);


#endif /* INC_8X8MATRIX_DISPLAY_H_ */