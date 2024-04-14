/*
 * tm1637.h
 *
 *  Created on: Apr 11, 2024
 *      Author: coppolimeros
 */

#ifndef INC_TM1637_H_
#define INC_TM1637_H_

#include "main.h"

#define WRITE_DATA  0x40 // automatic address adding
#define DISPLAY_ON  0x88
#define DISPLAY_OFF 0x80
#define DISP_ADDR   0xC0  // C0H

typedef struct {
	GPIO_TypeDef* clk_port;
	GPIO_TypeDef* dio_port;
	uint16_t clk_pin;
	uint16_t dio_pin;
} tm1637_t;

typedef enum {
	ACK_OK = 0, // Peripheral lowered SDA
	ACK_ERROR // Peripheral didnt lowered SDA
} ack_status;

void tm1637_init(tm1637_t* tm1637, GPIO_TypeDef* clk_port, GPIO_TypeDef* dio_port, uint16_t clk_pin, uint16_t dio_pin);
void tm1637_display_decimal(tm1637_t tm1637, int v);
void tm1637_display_on(tm1637_t tm1637);
void tm1637_display_off(tm1637_t tm1637);

#endif /* INC_TM1637_H_ */
