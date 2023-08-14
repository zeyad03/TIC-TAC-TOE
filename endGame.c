
#include <stdio.h>

#include "game.h"
#include "endGame.h"

/*
 * Functions in this module check for wins and draws
 */

// test all possible ways the game can be won for one player
int winGame( Game *game, char symbol ) {

  // Declaring functions.
  int diagonal( Game *game, char symbol );
  int vertical( Game *game, char symbol );
  int horizontal( Game *game, char symbol );

  if ( diagonal( game, symbol ) == 1 )
    return 1;   // Game won diagonally.
  else if ( vertical( game, symbol ) == 1)
    return 1;   // Game won vertically.
  else if ( horizontal( game, symbol ) == 1)
    return 1;   // Game won horizontally.
  else
    return 0;   // Continue.
}

// test for a draw
int drawGame( Game *game ) {

  if ( game->turns < 9 ) {
    return 0;   // Return 0 if there still places.
  } else {
    return 1;   // Return 1 if all places have been used.
  }
}

// Check for win diagonally.
int diagonal( Game *game, char symbol ) {
  
  // Pointer at the start of board array.
  char *ptr = &game->board[0][0];

  // Check both diagonals.
  if ( (*ptr == symbol && *(ptr +4) == symbol && *(ptr +8) == symbol)
    || (*(ptr +2) == symbol && *(ptr +4) == symbol 
    && *(ptr +6) == symbol) )
    return 1; // Return 1 if true.
  else
    return 0; // Continue.
}

// Check for win vertically.
int vertical( Game *game, char symbol ) {

  // Pointer at the start of the board array.
  char *ptr = &game->board[0][0];
  int col;

  // Iterate over columns.
  for ( col=0; col<3; col++ ) {
    if ( *(ptr +col) == symbol && *(ptr +(3+col)) == symbol
      && *(ptr +(6+col)) == symbol )
      return 1; // Return 1 if true.
  }

  return 0; // Continue.
}

// Check for win horizontally.
int horizontal( Game *game, char symbol ) {

  // Pointer at the start of the board array.
  char *ptr = &game->board[0][0];
  int row;

  // Iterate over rows.
  for ( row=0; row<3; row++ ) {
    if ( *(ptr + 3*row) == symbol && *(ptr +(3*row +1)) == symbol
      && *(ptr +(3*row +2)) == symbol )
      return 1; // Return 1 if true.
  }

  return 0; // Continue.
}
