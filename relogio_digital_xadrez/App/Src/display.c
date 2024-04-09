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
			tm1637Init(&display1, SCL1_GPIO_Port, SDA1_GPIO_Port, SCL1_Pin, SDA1_Pin);
			break;
		case DISPLAY2:
			tm1637Init(&display2, SCL2_GPIO_Port, SDA2_GPIO_Port, SCL2_Pin, SDA2_Pin);
			break;
		default:
			break;
	}
}

void display_start(display_id dsp_id) {
	switch(dsp_id) {
		case DISPLAY1:
			tm1637SetBrightness(display1, 8);
			break;
		case DISPLAY2:
			tm1637SetBrightness(display2, 8);
			break;
		default:
			break;
	}
}

void display_show(display_id dsp_id, int value) {
	switch(dsp_id) {
		case DISPLAY1:
			tm1637DisplayDecimal(display1, value, 1);
			break;
		case DISPLAY2:
			tm1637DisplayDecimal(display2, value, 1);
			break;
		default:
			break;
	}
}
