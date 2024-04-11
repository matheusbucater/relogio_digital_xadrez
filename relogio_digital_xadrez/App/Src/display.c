/*
 * display.c
 *
 *  Created on: Apr 9, 2024
 *      Author: matheusbucater
 */

#include "display.h"
#include "main.h"
#include "tm1637.h"

tm1637_t display1;
tm1637_t display2;

void display_init(display_id dsp_id) {
	switch (dsp_id) {
		case DISPLAY1:
			tm1637_init(&display1, SCL1_GPIO_Port, SDA1_GPIO_Port, SCL1_Pin, SDA1_Pin);
			break;
		case DISPLAY2:
			tm1637_init(&display2, SCL2_GPIO_Port, SDA2_GPIO_Port, SCL2_Pin, SDA2_Pin);
			break;
		default:
			break;
	}
}

void display_start(display_id dsp_id) {
	switch(dsp_id) {
		case DISPLAY1:
			tm1637_display_on(display1);
			break;
		case DISPLAY2:
			tm1637_display_off(display2);
			break;
		default:
			break;
	}
}

void display_show(display_id dsp_id, int value) {
	switch(dsp_id) {
		case DISPLAY1:
			tm1637_display_decimal(display1, value);
			break;
		case DISPLAY2:
			tm1637_display_decimal(display2, value);
			break;
		default:
			break;
	}
}
