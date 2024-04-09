/*
 * display.h
 *
 *  Created on: Apr 9, 2024
 *      Author: matheusbucater
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

typedef enum {
	DISPLAY1 = 0,
	DISPLAY2
} display_id;

void display_init(display_id dsp_id);
void display_show(display_id dsp_id, int value);

#endif /* DISPLAY_H_ */
