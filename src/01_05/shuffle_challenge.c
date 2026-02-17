/**
 * @file shuffle_challange.c
 * @author Madhav Kshirsagar (madhav.kshirsagar@siemens.com)
 * @brief
 *  - Shuffle an array of alphabets A-Z
 *  - Output the number of perfect shuffles required to restore the array back
 * to its original order
 *
 * @version 0.1
 * @date 31-08-2025
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <stdio.h>
#include <string.h>

#define DECKSIZE 26
#define HALFDECK DECKSIZE / 2 // Half the deck size
#define DECKLEN DECKSIZE + 1

int main(void)
{
  char cards[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char shuffled[DECKLEN] = {0};
  char deck[DECKLEN] = {0};
  int count = 0;
  int s, d = 0;
  strcpy(deck, cards);
  while (1)
  {
    // s - skips, d - increments
    for (d = 0, s = 0; d < HALFDECK; d++, s += 2)
    {
      shuffled[s] = deck[d];
      shuffled[s + 1] = deck[d + HALFDECK];
    }
    shuffled[s] = '\0';
    count++;
    printf("%2d: %s\n", count, shuffled);
    if (strcmp(cards, shuffled) == 0)
    {
      break;
    }
    strcpy(deck, shuffled);
  }

  printf("Deck restored after %d iterations\n", count);
  return 0;
}