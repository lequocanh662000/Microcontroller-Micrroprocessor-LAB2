
#include "led7_display.h"
#include "main.h"

#define NUMBER_OF_SEVEN_SEGMENT_LED  	1
#define MAX_LED							4
//common Anode 0:off  1:one
static uint8_t sevenSegmentLEDConversion[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};

//common Cathode 0:one  1:off
//uint8_t sevenSegmentLEDConversion[10] = {};

static int sevenSegmentLEDBuffer[NUMBER_OF_SEVEN_SEGMENT_LED]; // buffer to display one or more 7segLED

void update_seven_segment_led_buffer(int number){
	sevenSegmentLEDBuffer[0] = number;
}

void seven_segment_led_driver(void){
	uint8_t temp = sevenSegmentLEDConversion[sevenSegmentLEDBuffer[0]];

	HAL_GPIO_WritePin(SEVEN_SEGMENT_1_A_PORT, SEVEN_SEGMENT_1_A, !((temp>>0)&0x01));
	HAL_GPIO_WritePin(SEVEN_SEGMENT_1_B_PORT, SEVEN_SEGMENT_1_B, !((temp>>1)&0x01));
	HAL_GPIO_WritePin(SEVEN_SEGMENT_1_C_PORT, SEVEN_SEGMENT_1_C, !((temp>>2)&0x01));
	HAL_GPIO_WritePin(SEVEN_SEGMENT_1_D_PORT, SEVEN_SEGMENT_1_D, !((temp>>3)&0x01));
	HAL_GPIO_WritePin(SEVEN_SEGMENT_1_E_PORT, SEVEN_SEGMENT_1_E, !((temp>>4)&0x01));
	HAL_GPIO_WritePin(SEVEN_SEGMENT_1_F_PORT, SEVEN_SEGMENT_1_F, !((temp>>5)&0x01));
	HAL_GPIO_WritePin(SEVEN_SEGMENT_1_G_PORT, SEVEN_SEGMENT_1_G, !((temp>>6)&0x01));
	//HAL_GPIO_WritePin(SEVEN_SEGMENT_1_H_PORT, SEVEN_SEGMENT_1_H, !((temp>>7)&0x01));
}

void display7SEG(int number){
	update_seven_segment_led_buffer(number);
	seven_segment_led_driver();
}
//////////////////////////////////////////////////////

void initialclock(void){
	HAL_GPIO_WritePin(ENABLE_7SEG_1_PORT, ENABLE_7SEG_1, SET);
	HAL_GPIO_WritePin(ENABLE_7SEG_2_PORT, ENABLE_7SEG_2, SET);
	HAL_GPIO_WritePin(ENABLE_7SEG_3_PORT, ENABLE_7SEG_3, SET);
	HAL_GPIO_WritePin(ENABLE_7SEG_4_PORT, ENABLE_7SEG_4, SET);
}


