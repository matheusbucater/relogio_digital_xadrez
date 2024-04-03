/*
 * tm1637.c
 *
 *  Created on: Apr 3, 2024
 *      Author: matheusbucater
 */

#include <stdint.h>
#include "stm32f4xx_hal.h"
#include "tm1637.h"

void tm1637_scl_high(GPIO_TypeDef* scl_gpio, uint16_t scl_pin);
void tm1637_scl_low(GPIO_TypeDef* scl_gpio, uint16_t scl_pin);
void tm1637_sda_high(GPIO_TypeDef* sda_gpio, uint16_t sda_pin);
void tm1637_sda_low(GPIO_TypeDef* sda_gpio, uint16_t sda_pin);
void tm1637_start_packet(GPIO_TypeDef* scl_gpio, uint16_t scl_pin, GPIO_TypeDef* sda_gpio, uint16_t sda_pin);
void tm1637_end_packet(GPIO_TypeDef* scl_gpio, uint16_t scl_pin, GPIO_TypeDef* sda_gpio, uint16_t sda_pin);
void tm1637_change_sda_mode(uint32_t mode, GPIO_TypeDef* sda_gpio, uint32_t sda_pin);
uint8_t nums_to_segments(char num);

void tm1637_scl_high(GPIO_TypeDef* scl_gpio, uint16_t scl_pin) {
	HAL_GPIO_WritePin(scl_gpio, scl_pin, GPIO_PIN_SET);
}

void tm1637_scl_low(GPIO_TypeDef* scl_gpio, uint16_t scl_pin) {
	HAL_GPIO_WritePin(scl_gpio, scl_pin, GPIO_PIN_RESET);
}

void tm1637_sda_high(GPIO_TypeDef* sda_gpio, uint16_t sda_pin) {
	HAL_GPIO_WritePin(sda_gpio, sda_pin, GPIO_PIN_SET);
}

void tm1637_sda_low(GPIO_TypeDef* sda_gpio, uint16_t sda_pin) {
	HAL_GPIO_WritePin(sda_gpio, sda_pin, GPIO_PIN_RESET);
}

void tm1637_start_packet(GPIO_TypeDef* scl_gpio, uint16_t scl_pin, GPIO_TypeDef* sda_gpio, uint16_t sda_pin) {
	tm1637_scl_high(scl_gpio, scl_pin);
	tm1637_sda_high(sda_gpio, sda_pin);
	tm1637_sda_low(sda_gpio, sda_pin);
	tm1637_scl_low(scl_gpio, scl_pin);
}

void tm1637_end_packet(GPIO_TypeDef* scl_gpio, uint16_t scl_pin, GPIO_TypeDef* sda_gpio, uint16_t sda_pin) {
	tm1637_scl_low(scl_gpio, scl_pin);
	tm1637_sda_low(sda_gpio, sda_pin);
	tm1637_scl_high(scl_gpio, scl_pin);
	tm1637_sda_high(sda_gpio, sda_pin);
}

void tm1637_change_sda_mode(uint32_t mode, GPIO_TypeDef* sda_gpio, uint32_t sda_pin) {
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = sda_pin;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStruct.Mode = mode;
	HAL_GPIO_Init(sda_gpio, &GPIO_InitStruct);
}

// teste
void tm1637_display(void) {
}

uint8_t nums_to_segments(char num) {
	switch(num) {
	case '0':
		// 1111 1100 -> 0011 1111
		// 0011 1111
		//  3   f
		return 0x3f;
	case '1':
		// 0110 0000
		// 0000 0110
		//  0   6
		return 0x06;
	case '2':
		// 1101 1010
		// 0101 1011
		//  5   b
		return 0x5b;
	case '3':
		// 1111 0010
		// 0100 1111
		//  4   f
		return 0x4f;
	case '4':
		// 0110 0110
		// 0110 0110
		//  6   6
		return 0x66;
	case '5':
		// 1011 0110
		// 0110 1101
		//  6   d
		return 0x6d;
	case '6':
		// 1011 1110
		// 0111 1101
		//  7   d
		return 0x7d;
	case '7':
		// 1110 0000
		// 0000 0111
		//  0   7
		return 0x07;
	case '8':
		// 1111 1110
		// 0111 1111
		//  7   f
		return 0x7f;
	case '9':
		// 1111 0110
		// 0110 1111
		//  6   f
		return 0x6f;
	}
}

/*
void tm1637_data_out(uint8_t* data_buffer, GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) {
	for (uint8_t i = 0; i < PACKET_SIZE; i++ ) {

		tm1637_scl_high(GPIOx, GPIO_Pin);

		if (data_buffer[i] == GPIO_PIN_SET) {
			tm1637_sda_high(GPIOx, GPIO_Pin);
		} else {
			tm1637_sda_low(GPIOx, GPIO_Pin);
		}

		tm1637_scl_low(GPIOx, GPIO_Pin);
	}
}

void tm1637_transfer_command(uint8_t* command, GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) {
	uint8_t byte_data[8] = { 0 };

	for (uint8_t i = 0; i < PACKET_SIZE; i++) {
		byte_data[i] = (command[0] & (0x01 << i)) && 1;
	}

	tm1637_start_packet(GPIOx, GPIO_Pin);
	tm1637_data_out(byte_data, GPIOx, GPIO_Pin);

}
*/
