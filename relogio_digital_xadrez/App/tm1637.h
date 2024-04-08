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
} display_t;


void tm1637Init(display_t display);
void tm1637DisplayDecimal(display_t display, int v, int displaySeparator);
void tm1637SetBrightness(display_t display, char brightness);

#endif /* TM1637_H_ */
