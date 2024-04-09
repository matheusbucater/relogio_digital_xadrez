/*
 * game.h
 *
 *  Created on: Apr 8, 2024
 *      Author: matheusbucater
 */

#ifndef GAME_H_
#define GAME_H_

#include "player.h"

typedef enum {
	STOPPED = 0,
	ACTIVE
} game_state_t;

typedef struct {
	game_state_t state;
	player_t player1;
	player_t player2;
	player_id active_player;
} game_t;

void game_init(game_t *game, player_t player1, player_t player2);
void game_start(game_t *game);
void game_stop(game_t *game);
void game_change_active_player(game_t *game, player_id player);
void game_update(game_t *game);

#endif /* GAME_H_ */
