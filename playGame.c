
#include <stdio.h>

#include "game.h"
#include "playGame.h"

/*
 * Controls the game logic from start to end
 */

void playGame( Game *game ) {

  // Declaring functions.
  void showGame ( Game *game );
  int makeMove( Game *game, char symbol );
  int winGame( Game *game, char symbol );
  int drawGame( Game *game );

  char symbols[2] = { 'X', 'O' };
  // Player 'X' plays first.
  int player = 0;

  printf("New game starting\n");
    
  // Loop to control loop.
  for ( game->turns=0; game->turns<9; game->turns++ ) {

    // Show board at beginnig and after each move.
    showGame( game );

    // Request a move from the next player and check it is valid.
    printf("Player %c: Enter your move as row column values:\n",symbols[player]);

    // If the move is valid update the board.
    if ( makeMove(game, symbols[player]) == 1 ) {
            
      // Test for win and if so, show board and exit loop.
      if ( winGame( game, symbols[player]) == 1 ) {
        showGame( game );
        printf("Player %c has won\n",symbols[player]);
        break;
      }

      // Change between players after each move.
      if ( player == 0 )
        player = 1;
      else
        player = 0;
    } else {
      printf("Move rejected. Please try again\n");
      game->turns -= 1;
    }
  }

  // Test for draw and if so, print appropriate message.
  if ( drawGame( game ) == 1 ) {

    printf("Match is drawn\n");
  }

  return;
}

/*
 * Display the game board - do not adjust the formatting
 */

void showGame( Game *game ) {

  printf("\n");
  printf("      0  1  2\n");
  printf("\n");
  printf(" 0    %c  %c  %c\n",game->board[0][0],game->board[0][1],game->board[0][2]);
  printf(" 1    %c  %c  %c\n",game->board[1][0],game->board[1][1],game->board[1][2]);
  printf(" 2    %c  %c  %c\n",game->board[2][0],game->board[2][1],game->board[2][2]);
  printf("\n");

  return;
}

/*
 * Read in the players chosen location
 * Check that the input is a valid empty square
 * If valid then update the board (return 1)
 * If invalid reject the move (return 0)
 */

int makeMove( Game *game, char symbol ) {

  // Pointer at the start of the board array.
  char *ptr = &game->board[0][0];
  int row, col, num;

  // Read the player's move from the keyboard.
  scanf("%d %d", &row, &col);

  // Test the chosen location is a valid empty space.
  if ( game->board[row][col] == '.' ) {
    num = row*3 + col;
    *(ptr +num) = symbol;
    return 1;   // Move accepted.
  } else {
    return 0;   // Move rejected.
  }
}

