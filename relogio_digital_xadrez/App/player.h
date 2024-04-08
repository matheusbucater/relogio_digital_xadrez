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
} players_t;

typedef struct {
	uint32_t minutes;
	uint32_t seconds;
} player_time_t;

typedef struct {
	players_t player;
	player_time_t start_time;
	player_time_t curr_time;
	display_t display;
} player_t;

void player_init(player_t *player, player_time_t start_time, players_t player_n, display_t display);
void player_start(player_t *player);
void player_stop(player_t *player);
int player_time_ended(player_t player);
void player_time_dec(player_t *player);
void player_display_curr(player_t player);

#endif /* PLAYER_H_ */
