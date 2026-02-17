/**
 * @file hailstone_challange.c
 * @author Madhav Kshirsagar (madhav.kshirsagar@siemens.com)
 * @brief
 *  - If n = 1, sequence is over
 *  - If n = even, next value is n/2
 *  - If n = odd, next value is (n*3)+1
 * Eventually sequnce terminates to n==1
 * @version 0.1
 * @date 31-08-2025
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <stdio.h>

void hailstone(int num);

void hailstone(int num)
{
  static int count = 0;
  count++;
  printf("%d ", num);
  // If num is 1 then end the sequence
  if (num == 1)
  {
    // This will break the recursion
    printf("\nHailstone count = %d\n", count);
    return;
  }
  // If the number is even
  if (num % 2 == 0)
  {
    num /= 2;
  }
  // Else the num is odd
  else
  {
    num = (num * 3) + 1;
  }
  // Recursive call
  hailstone(num);
}

int main(void)
{
  int num = 0;
  printf("Enter a number for hailstone: \n");
  scanf("%d", &num);
  hailstone(num);

  return 0;
}