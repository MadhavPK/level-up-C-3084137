/**
 * @file golden_challenge.c
 * @author MK
 * @brief creating golden ratio
 * @version 0.1
 * @date 28-04-2026
 *
 * @copyright Copyright (c) 2026
 *
 */
#include <stdio.h>

float golden_ratio(int iterations)
{
  float ratio = 0;
  if (iterations > 0)
  {
    ratio = 1.0 + (1.0 / golden_ratio(iterations - 1));
  }
  else
  {
    ratio = 1;
  }
  return ratio;
}

int main(void)
{
  float ratio = 0;
  int iterations = 500;
  ratio = golden_ratio(iterations);
  printf("Ratio = %f\n", ratio);

  return 0;
}