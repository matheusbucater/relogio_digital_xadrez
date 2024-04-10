/*
 * buzzer.h
 *
 *  Created on: Apr 10, 2024
 *      Author: matheusbucater
 */

#ifndef INC_BUZZER_H_
#define INC_BUZZER_H_

typedef enum {
	BUZZ_STOP = 0,
} buzzer_id;

void buzzer_brr_ms(buzzer_id buzz_id);

#endif /* INC_BUZZER_H_ */
