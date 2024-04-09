/*
 * tm1637.h
 *
 *  Created on: Apr 8, 2024
 *      Author: matheusbucater
 */

#ifndef TM1637_H_
#define TM1637_H_

#include "stdint.h"
#include "stm32f4xx_hal.h"


typedef struct {
	GPIO_TypeDef* clk_port;
	GPIO_TypeDef* dio_port;
	uint16_t clk_pin;
	uint16_t dio_pin;
} tm1637_t;


void tm1637Init(tm1637_t* display, GPIO_TypeDef* clk_port, GPIO_TypeDef* dio_port, uint16_t clk_pin, uint16_t dio_pin);
void tm1637DisplayDecimal(tm1637_t display, int v, int displaySeparator);
void tm1637SetBrightness(tm1637_t display, char brightness);

#endif /* TM1637_H_ */
