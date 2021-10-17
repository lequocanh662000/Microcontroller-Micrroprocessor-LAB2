/*
 * 8x8matrix_display.c
 *
 *  Created on: Oct 8, 2021
 *      Author: Dell
 */
#include "main.h"
#include "8x8matrix_display.h"
#define 	NUMBER_LED_MATRIX		1
#define 	SIZE_OF_MATRIX			8
#define		ENABLE					0
#define 	DISABLE					1

static uint8_t matrix8x8LEDConversion[8] = {0xff, 0x03, 0x01, 0xcc, 0xcc, 0x01, 0x03, 0xff}; // show letter A

//static uint8_t column_buffer[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
static uint8_t row_buffer[SIZE_OF_MATRIX]  = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};


static uint16_t mColumnControlPin[SIZE_OF_MATRIX] = {
		DISABLE_COL_8x8_1, DISABLE_COL_8x8_2,
		DISABLE_COL_8x8_3, DISABLE_COL_8x8_4,
		DISABLE_COL_8x8_5, DISABLE_COL_8x8_6,
		DISABLE_COL_8x8_7, DISABLE_COL_8x8_8
};

static GPIO_TypeDef * mColumnControlPort[SIZE_OF_MATRIX] = {
		DISABLE_COL_8x8_1_PORT, DISABLE_COL_8x8_2_PORT,
		DISABLE_COL_8x8_3_PORT, DISABLE_COL_8x8_4_PORT,
		DISABLE_COL_8x8_5_PORT, DISABLE_COL_8x8_6_PORT,
		DISABLE_COL_8x8_7_PORT, DISABLE_COL_8x8_8_PORT
};

static uint16_t mRowControlPin[SIZE_OF_MATRIX] = {
		ROW1,ROW2,
		ROW3,ROW4,
		ROW5,ROW6,
		ROW7,ROW8,
};

static GPIO_TypeDef * mRowControlPort[SIZE_OF_MATRIX] = {
		ROW1_PORT, ROW2_PORT,
		ROW3_PORT, ROW4_PORT,
		ROW5_PORT, ROW6_PORT,
		ROW7_PORT, ROW8_PORT
};


void update_row_matrix_8x8_led_buffer(uint8_t column_index){
	if(column_index > 7 || column_index < 0)return;
	row_buffer[column_index] = matrix8x8LEDConversion[column_index];
	return;
}

void matrix8x8_data_ouput(uint8_t value){
	uint8_t index = 0;
	for(index = 0; index < SIZE_OF_MATRIX; index ++){
		if((value >> index) & 0x01){
			HAL_GPIO_WritePin(mRowControlPort[index], mRowControlPin[index], SET);
		}else{
			HAL_GPIO_WritePin(mRowControlPort[index], mRowControlPin[index], RESET);
		}
	}
}

void clear_previous_matrix8x8_row_led(uint8_t index){
	if(index > SIZE_OF_MATRIX)return;
	else{
		HAL_GPIO_WritePin(mColumnControlPort[index], mColumnControlPin[index], DISABLE);
	}
}

void set_current_matrix8x8_col_led(uint8_t index){
	if(index > SIZE_OF_MATRIX)return;
	else{
		HAL_GPIO_WritePin(mColumnControlPort[index], mColumnControlPin[index], ENABLE);
	}
}

void matrix8x8_led_driver(void){
	static uint8_t led_index;
	uint8_t tempData;

	clear_previous_matrix8x8_row_led(led_index);

	led_index = (led_index+1) % SIZE_OF_MATRIX;
	tempData = matrix8x8LEDConversion[led_index];
	matrix8x8_data_ouput(tempData);
	set_current_matrix8x8_col_led(led_index);
}

void display_matrix8x8_led(){
	matrix8x8_led_driver();
	HAL_Delay(1);
}






//
//uint8_t RowMatrix_buffer[8] = {0xff, 0x03, 0x01, 0xcc, 0xcc, 0x01, 0x03, 0xff};
//
// void updateLEDMatrix(int index){
//	 uint32_t saveState = GPIOB->ODR;
//	 GPIOB->ODR = saveState|0x0001;
//	 switch (index){
//	 	 case 0:
//	 		 GPIOB->ODR = RowMatrix_buffer[0];
//	 		 break;
//	 	 case 1:
//	 		 GPIOB->ODR = RowMatrix_buffer[1];
//	 		 break;
//	 	 case 2:
//	 		 GPIOB->ODR = RowMatrix_buffer[2];
//	 		 break;
//	 	 case 3:
//	 		 GPIOB->ODR = RowMatrix_buffer[3];
//	 		 break;
//	 	 case 4:
//	 		 GPIOB->ODR = RowMatrix_buffer[4];
//	 		 break;
//	 	 case 5:
//	 		 GPIOB->ODR = RowMatrix_buffer[5];
//	 		 break;
//	 	 case 6:
//	 		GPIOB->ODR = RowMatrix_buffer[6];
//	 		 break;
//	 	 case 7:
//	 		GPIOB->ODR = RowMatrix_buffer[7];
//	 		 break;
//	 	 default:
//	 		 break;
//	 }
// }
//
// void columnScan(int index){
//	 switch (index){
//	 	 	 case 0:
//	 	 		 HAL_GPIO_WritePin(ENABLE_COL_8x8_8_PORT, ENABLE_COL_8x8_8, SET);
//	 	 		 HAL_GPIO_WritePin(ENABLE_COL_8x8_1_PORT, ENABLE_COL_8x8_1, RESET);
//
//	 	 		 break;
//	 	 	 case 1:
//	 	 		 HAL_GPIO_WritePin(ENABLE_COL_8x8_1_PORT, ENABLE_COL_8x8_1, SET);
//	 	 		 HAL_GPIO_WritePin(ENABLE_COL_8x8_2_PORT, ENABLE_COL_8x8_2, RESET);
//
//	 	 		 break;
//	 	 	 case 2:
//	 	 		 HAL_GPIO_WritePin(ENABLE_COL_8x8_2_PORT, ENABLE_COL_8x8_2, SET);
//	 	 		 HAL_GPIO_WritePin(ENABLE_COL_8x8_3_PORT, ENABLE_COL_8x8_3, RESET);
//
//	 	 		 break;
//	 	 	 case 3:
//	 	 		 HAL_GPIO_WritePin(ENABLE_COL_8x8_3_PORT, ENABLE_COL_8x8_3, SET);
//	 	 		 HAL_GPIO_WritePin(ENABLE_COL_8x8_4_PORT, ENABLE_COL_8x8_4, RESET);
//
//	 	 		 break;
//	 	 	 case 4:
//	 	 		 HAL_GPIO_WritePin(ENABLE_COL_8x8_4_PORT, ENABLE_COL_8x8_4, SET);
//	 	 		 HAL_GPIO_WritePin(ENABLE_COL_8x8_5_PORT, ENABLE_COL_8x8_5, RESET);
//
//	 	 		 break;
//	 	 	 case 5:
//	 	 		 HAL_GPIO_WritePin(ENABLE_COL_8x8_5_PORT, ENABLE_COL_8x8_5, SET);
//	 	 		 HAL_GPIO_WritePin(ENABLE_COL_8x8_6_PORT, ENABLE_COL_8x8_6, RESET);
//
//	 	 		 break;
//	 	 	 case 6:
//	 	 		 HAL_GPIO_WritePin(ENABLE_COL_8x8_6_PORT, ENABLE_COL_8x8_6, SET);
//	 	 		 HAL_GPIO_WritePin(ENABLE_COL_8x8_7_PORT, ENABLE_COL_8x8_7, RESET);
//
//	 	 		 break;
//	 	 	 case 7:
//	 	 		 HAL_GPIO_WritePin(ENABLE_COL_8x8_7_PORT, ENABLE_COL_8x8_7, SET);
//	 	 		 HAL_GPIO_WritePin(ENABLE_COL_8x8_8_PORT, ENABLE_COL_8x8_8, RESET);
//
//	 	 		 break;
//	 	 	 default:
//	 	 		 break;
//	 }
// }