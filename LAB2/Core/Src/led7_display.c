
#include "led7_display.h"
#include "main.h"

#define NUMBER_OF_SEVEN_SEGMENT_LED  	4
#define NUMBER_OF_DECIMAL_DIGIT			10

//common Anode 0:off  1:one
static uint8_t sevenSegmentLEDConversion[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};

//common Cathode 0:one  1:off
//uint8_t sevenSegmentLEDConversion[10] = {};

static uint8_t sevenSegmentLEDBuffer[NUMBER_OF_SEVEN_SEGMENT_LED]; // buffer to store value of each led

// FORMAT PIN, PORT
static uint16_t sevenSegmentDataPin[8] = {
		SEVEN_SEGMENT_1_A, SEVEN_SEGMENT_1_B,
		SEVEN_SEGMENT_1_C, SEVEN_SEGMENT_1_D,
		SEVEN_SEGMENT_1_E, SEVEN_SEGMENT_1_F,
		SEVEN_SEGMENT_1_G, SEVEN_SEGMENT_1_H
};

static GPIO_TypeDef * sevenSegmentDataPort[8] = {
		SEVEN_SEGMENT_1_A_PORT, SEVEN_SEGMENT_1_B_PORT,
		SEVEN_SEGMENT_1_C_PORT, SEVEN_SEGMENT_1_D_PORT,
		SEVEN_SEGMENT_1_E_PORT, SEVEN_SEGMENT_1_F_PORT,
		SEVEN_SEGMENT_1_G_PORT, SEVEN_SEGMENT_1_H_PORT
};

static uint16_t sevenSegmentControlPin[NUMBER_OF_SEVEN_SEGMENT_LED] = {
		DISABLE_7SEG_1, DISABLE_7SEG_2,
		DISABLE_7SEG_3, DISABLE_7SEG_4
};

static GPIO_TypeDef * sevenSegmentControlPort[NUMBER_OF_SEVEN_SEGMENT_LED] = {
		DISABLE_7SEG_1_PORT, DISABLE_7SEG_2_PORT,
		DISABLE_7SEG_3_PORT, DISABLE_7SEG_4_PORT
};

// 						FUNCTION CONFIGURATION

void update_seven_segment_led_buffer(uint8_t index, uint8_t value){
	if(index >= NUMBER_OF_SEVEN_SEGMENT_LED) return;
	if(value > 10) return ;
	sevenSegmentLEDBuffer[index] = value;
	return;
}

void seven_segment_data_output(uint8_t value){
	uint8_t index;
	for(index = 0; index < 8; index ++){
			if((value>>index) & 0x01){
				HAL_GPIO_WritePin(sevenSegmentDataPort[index], sevenSegmentDataPin[index], RESET);
			} else {
				HAL_GPIO_WritePin(sevenSegmentDataPort[index], sevenSegmentDataPin[index],	SET);
			}
		}
}

void clear_previous_seven_segment_led(uint8_t index){
	if(index >= NUMBER_OF_SEVEN_SEGMENT_LED) return;
	HAL_GPIO_WritePin(sevenSegmentControlPort[index], sevenSegmentControlPin[index], SET);
}

void set_current_seven_segment_led(uint8_t index){
	if(index >= NUMBER_OF_SEVEN_SEGMENT_LED) return;
	HAL_GPIO_WritePin(sevenSegmentControlPort[index], sevenSegmentControlPin[index], RESET);
}

void seven_segment_led_driver(void){
	static uint8_t led_index = 0;
	uint8_t tempData;
	// clear previous led data
	clear_previous_seven_segment_led(led_index);
	// current led data setting
	led_index = (led_index + 1) % NUMBER_OF_SEVEN_SEGMENT_LED;
	tempData = sevenSegmentLEDConversion[sevenSegmentLEDBuffer[led_index]];
	seven_segment_data_output(tempData);
	set_current_seven_segment_led(led_index);
}

void updateClockBuffer(int hour, int min){
	//upadte hour
	update_seven_segment_led_buffer(0, hour/10);
	update_seven_segment_led_buffer(1, hour%10);
	//update min
	update_seven_segment_led_buffer(2, min/10);
	update_seven_segment_led_buffer(3, min%10);
}
