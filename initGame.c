
#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "initGame.h"

/*
 * Intialise game data for a new game
 */

Game *initGame( int boardSize, int winLength ) {

  // Allocate the Game data structure.
  Game *game = malloc(sizeof(Game));
  // Pointer at the start of the board array.
  char *ptr = &game->board[0][0];
  int pos;

  // Intialise the Game data sturcture values to '.' (unused location).
  for ( pos=0; pos<boardSize*boardSize; pos++ ) {
    *(ptr +pos) = '.';
  }

  return game;
}


