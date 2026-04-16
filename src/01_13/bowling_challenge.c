/**
 * @file bowling_challenge.c
 * @author MK
 * @brief challenge 13: bowling challenge
 * @version 0.1
 * @date 01-04-2026
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// This structure keeps the score
typedef struct
{
  char throw1;
  char throw2;
  uint8_t pins_dropped1;
  uint8_t pins_dropped2;
  uint16_t score;
} roll_frame;

uint8_t rollBall(uint8_t num_pins);
void playGame(roll_frame *game);

int main(void)
{
  roll_frame game = {0};

  srand((unsigned)time(NULL));

  playGame(&game);

  // score
  printf("|%c|%c|\n", game.throw1, game.throw2);
  printf("|%d|\n", game.score);

  return 0;
}

// Play the game which involved rolling the ball twice or once if the 1st one
// roll is strike
void playGame(roll_frame *game)
{
  game->pins_dropped1 = rollBall(10);

  // The 1st roll is strike
  if (game->pins_dropped1 == 10)
  {
    game->throw1 = 'X';      // 1st throw is strike
    game->throw2 = ' ';      // 2nd throw is unknown
    game->pins_dropped2 = 0; // 2nd theow is init to 0
    game->score = game->pins_dropped1 + game->pins_dropped2;
  }
  else
  {
    // if the 1st roll dropped 0 pins
    if (game->pins_dropped1 == 0)
    {
      game->throw1 = '-'; // miss
    }
    else
    {
      // Store the number as character
      game->throw1 = game->pins_dropped1 + '0';
    }

    // Roll the ball with number for remaining pins
    game->pins_dropped2 = rollBall(10 - game->pins_dropped1);
    // Score will never be > 10
    game->score = game->pins_dropped1 + game->pins_dropped2;
    if (game->score == 10)
    {
      // Spare
      game->throw2 = '/';
    }
    else
    {
      // if the 2nd roll dropped 0 pins
      if (game->pins_dropped2 == 0)
      {
        game->throw2 = '-'; // miss
      }
      else
      {
        // Store the number as character
        game->throw2 = game->pins_dropped2 + '0';
      }
    }
  }
}

// simulate the roll of the ball. Return value is number of pins dropped.
uint8_t rollBall(uint8_t num_pins)
{
  // give a random number of pins dropped between 0-num_pins
  return (rand() % (num_pins + 1));
}