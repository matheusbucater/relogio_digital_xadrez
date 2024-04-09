/*
 * player.h
 *
 *  Created on: Apr 8, 2024
 *      Author: matheusbucater
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "stdint.h"
#include "tm1637.h"

typedef enum{
	PLAYER1 = 0,
	PLAYER2
} player_id;

typedef struct {
	uint32_t minutes;
	uint32_t seconds;
} player_time_t;

typedef struct {
	player_id player;
	player_time_t start_time;
	player_time_t curr_time;
	display_t display;
} player_t;

void player_init(player_t *player, player_time_t start_time, player_id plr_id, display_t display);
void player_time_restart(player_t *player);
int  player_time_ended(player_t player);
void player_time_dec(player_t *player);
void player_display_curr(player_t player);

#endif /* PLAYER_H_ */
