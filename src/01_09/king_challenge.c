/**
 * @file king_challenge.c
 * @author MK
 * @brief
 * @version 0.1
 * @date 20-02-2026
 *
 * @copyright Copyright (c) 2026
 *
 */
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>

#define NUM_OF_ROWS 8
#define NUM_OF_COLS 8
#define KING 'K'
#define EMPTY_CELL '.'

typedef enum
{
  UP = 0,
  DOWN,
  LEFT,
  RIGHT,
  UP_LEFT,
  UP_RIGHT,
  DOWN_RIGHT,
  DOWN_LEFT,
  NO_MOVE,
  TOTAL_MOVES
} move_dir_t;

// Create the chess board
char chess_board[NUM_OF_ROWS][NUM_OF_COLS];

void print_chess_board(void);

int main(void)
{
  // Variables to track the position of the king
  uint8_t king_r = 0, king_c = 0;
  // initialize the RNG with seed as current time
  srand((unsigned)time(NULL));

  // initialize the chess board
  for (uint8_t r = 0; r < NUM_OF_ROWS; r++)
  {
    for (uint8_t c = 0; c < NUM_OF_COLS; c++)
    {
      chess_board[r][c] = EMPTY_CELL;
    }
  }
  print_chess_board();

  printf("\nStarting position\n");
  // place the king at 4R, 5C: sub 1 since index starts with 0
  king_r = 3;
  king_c = 4;
  chess_board[king_r][king_c] = KING;
  print_chess_board();

  // Tracking the move
  move_dir_t move_dir = UP;

  // Run the loop infinite times
  for (uint8_t times_played = 0;; times_played++)
  {
    printf("\nTimes Played = %d\n", times_played);
    // Get the move
    move_dir = rand() % TOTAL_MOVES;

    // make the move
    switch (move_dir)
    {
    case UP:
      printf("UP\n");
      // Only the row changes
      king_r = king_r - 1;
      break;

    case DOWN:
      printf("DOWN\n");
      // Only the row changes
      king_r = king_r + 1;
      break;

    case LEFT:
      printf("LEFT\n");
      // Only the col changes
      king_c = king_c - 1;
      break;

    case RIGHT:
      printf("RIGHT\n");
      // Only the col changes
      king_c = king_c + 1;
      break;

    case UP_LEFT:
      printf("UP_LEFT\n");
      king_r = king_r - 1;
      king_c = king_c - 1;
      break;

    case UP_RIGHT:
      printf("UP_RIGHT\n");
      king_r = king_r - 1;
      king_c = king_c + 1;
      break;

    case DOWN_RIGHT:
      printf("DOWN_RIGHT\n");
      king_r = king_r + 1;
      king_c = king_c + 1;
      break;

    case DOWN_LEFT:
      printf("DOWN_LEFT\n");
      king_r = king_r + 1;
      king_c = king_c - 1;
      break;

    case NO_MOVE:
      printf("NO_MOVE\n");
      break;

    default:
      break;
    }

    printf("king_r = %d, king_c = %d\n", king_r, king_c);
    // The col or row is out of bounds i.e. out of 0 - 7
    if ((king_c >= NUM_OF_COLS) || (king_r >= NUM_OF_ROWS))
    {
      printf("\nThe king is out of the chess board!\n");
      printf("King is out of the board after %d plays!\n", times_played);
      break;
    }

    chess_board[king_r][king_c] = KING;
    print_chess_board();
  }
  return 0;
}

void print_chess_board(void)
{
  printf("***********************************************************\n");
  // initialize the chess board
  for (uint8_t r = 0; r < NUM_OF_ROWS; r++)
  {
    for (uint8_t c = 0; c < NUM_OF_COLS; c++)
    {
      printf("%c ", chess_board[r][c]);
    }
    printf("\n");
  }
}