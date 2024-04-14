/*
 * tm1637.c
 *
 *  Created on: Apr 11, 2024
 *      Author: coppolimeros
 */

// tm1637 datasheet - https://github.com/revolunet/tm1637/blob/master/datasheet-en.pdf

#include "tm1637.h"
#include "timer.h"

void tm1637_clk_high(tm1637_t tm1637);
void tm1637_clk_low(tm1637_t tm1637);
void tm1637_dio_high(tm1637_t tm1637);
void tm1637_dio_low(tm1637_t tm1637);
void tm1637_start_transfer(tm1637_t tm1637);
void tm1637_stop_transfer(tm1637_t tm1637);
void tm1637_dio_input(tm1637_t tm1637);
void tm1637_dio_output(tm1637_t tm1637);
ack_status tm1637_ack(tm1637_t tm1637);
void tm1637_write_byte(tm1637_t tm1637, uint8_t byte);


const char segments[] = {
    0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f // 0 - 9
};

void tm1637_init(tm1637_t* tm1637, GPIO_TypeDef* clk_port, GPIO_TypeDef* dio_port, uint16_t clk_pin, uint16_t dio_pin) {
	tm1637->clk_port = clk_port;
	tm1637->dio_port = dio_port;
	tm1637->clk_pin = clk_pin;
	tm1637->dio_pin = dio_pin;
}

void tm1637_display_decimal(tm1637_t tm1637, int decimal) {
	// from the datasheet:
	// Write SRAM data in address auto increment 1 mode.
	// Start > Command1 > ACK > Stop > Start > Command2 > ACK > Data1 > ACK > Data2 > ACK >  ... > ACK > DataN > ACK > Stop > Start > Command3 > ACK > Stop
	// ps.: the datasheet dont mention the second-last Stop (but it makes senses to be there >_<)

	// Command1: Set data
	// Command2: Set address
	// Data1~N:  Transfer data display
	// Command3: Control display


    unsigned char digits[4];
    for (int i = 0; i < 4; ++i) {
        digits[i] = segments[decimal % 10];
        decimal /= 10;
    }

	// Command1
	tm1637_start_transfer(tm1637);
	tm1637_write_byte(tm1637, WRITE_DATA);
	if (tm1637_ack(tm1637) == ACK_ERROR) return;
	tm1637_stop_transfer(tm1637);

	// Command2
	tm1637_start_transfer(tm1637);
	tm1637_write_byte(tm1637, DISP_ADDR);
	if (tm1637_ack(tm1637) == ACK_ERROR) return;

	// Data4 (4 digit display)
	for (int i = 0; i < 4; i++) {
		tm1637_write_byte(tm1637, digits[3-i]);
		if (tm1637_ack(tm1637) == ACK_ERROR) return;
	}
	tm1637_stop_transfer(tm1637);
}

void tm1637_display_on(tm1637_t tm1637) {
	tm1637_start_transfer(tm1637);
	tm1637_write_byte(tm1637, DISPLAY_ON);
	if (tm1637_ack(tm1637) == ACK_ERROR) return;
	tm1637_stop_transfer(tm1637);
}

void tm1637_display_off(tm1637_t tm1637) {
	tm1637_start_transfer(tm1637);
	tm1637_write_byte(tm1637, DISPLAY_ON);
	if (tm1637_ack(tm1637) == ACK_ERROR) return;
	tm1637_stop_transfer(tm1637);
}


void tm1637_write_byte(tm1637_t tm1637, uint8_t byte) {
	for (int i = 0; i < 8; i++) {
		tm1637_clk_low(tm1637);

		if (byte & 0x01) tm1637_dio_high(tm1637);
		else tm1637_dio_low(tm1637);

		tm1637_clk_high(tm1637);

		byte >>= 1;
	}
}


void tm1637_start_transfer(tm1637_t tm1637) {
	tm1637_clk_high(tm1637);
	tm1637_dio_high(tm1637);
	tm1637_dio_low(tm1637);
}

void tm1637_stop_transfer(tm1637_t tm1637) {
	tm1637_clk_high(tm1637);
	tm1637_dio_low(tm1637);
	tm1637_dio_high(tm1637);
}

ack_status tm1637_ack(tm1637_t tm1637) {
	tm1637_dio_input(tm1637);
	GPIO_PinState ack = GPIO_PIN_SET;
	ack = HAL_GPIO_ReadPin(tm1637.dio_port, tm1637.dio_pin);
	tm1637_dio_output(tm1637);
	if (ack == GPIO_PIN_SET) {
		return ACK_ERROR;
	}

	return ACK_OK;
}

void tm1637_dio_input(tm1637_t tm1637) {
	GPIO_InitTypeDef GPIO_InitStruct = { 0 };
	GPIO_InitStruct.Pin = tm1637.dio_pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
	GPIO_InitStruct.Pull = GPIO_NOPULL;

	HAL_GPIO_Init(tm1637.dio_port, &GPIO_InitStruct);
	timer_delay_us(TIM_DELAY, 4);
}

void tm1637_dio_output(tm1637_t tm1637) {
	GPIO_InitTypeDef GPIO_InitStruct = { 0 };
	GPIO_InitStruct.Pin = tm1637.dio_pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;

	HAL_GPIO_Init(tm1637.dio_port, &GPIO_InitStruct);
	timer_delay_us(TIM_DELAY, 4);
}

void tm1637_clk_high(tm1637_t tm1637) {
	HAL_GPIO_WritePin(tm1637.clk_port, tm1637.clk_pin, SET);
	timer_delay_us(TIM_DELAY, 4);
}
void tm1637_clk_low(tm1637_t tm1637) {
	HAL_GPIO_WritePin(tm1637.clk_port, tm1637.clk_pin, RESET);
	timer_delay_us(TIM_DELAY, 4);
}
void tm1637_dio_high(tm1637_t tm1637) {
	HAL_GPIO_WritePin(tm1637.dio_port, tm1637.dio_pin, SET);
	timer_delay_us(TIM_DELAY, 4);
}
void tm1637_dio_low(tm1637_t tm1637) {
	HAL_GPIO_WritePin(tm1637.dio_port, tm1637.dio_pin, RESET);
	timer_delay_us(TIM_DELAY, 4);
}
