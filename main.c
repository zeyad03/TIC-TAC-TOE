
#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "playGame.h"
#include "initGame.h"

/*
 * main function: program entry point
 */

int main( int argc, char *argv[] ) {
  
  void playGame( Game *game );
  // Pointer for the game structure.
  Game *game;

  // Allocate memory and assign starting values to structure.
  game = initGame( 3, 3 );

  // Start playing the game.
  playGame( game );

  free(game); // Free heap memory that was used.

  return 0;
}

