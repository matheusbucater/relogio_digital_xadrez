/*
 * tm1637.h
 *
 *  Created on: Apr 3, 2024
 *      Author: matheusbucater
 */

#ifndef TM1637_H_
#define TM1637_H_

#define GPIOx GPIOB

// Display Address
#define C0H          0xC0
#define C1H          0xC1
#define C2H          0xC2
#define C3H          0xC3
#define C4H          0xC4
#define C5H          0xC5

// Commands
#define DISPLAY_ON   0x88
#define DISPLAY_OFF  0x80
#define FIX_ADDRESS  0x44
#define AUTO_ADDRESS 0x40

#define PACKET_SIZE  0x08
#define N_SEGMENTS   0x04

#endif /* TM1637_H_ */
