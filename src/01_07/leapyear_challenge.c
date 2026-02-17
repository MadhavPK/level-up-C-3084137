/**
 * @file leapyear_challange.c
 * @author Madhav Kshirsagar (madhav.kshirsagar@siemens.com)
 * @brief
 *  Writing a leap year function
 *  - The year is evenly divisible by 4
 *  - unless the year is also evenly divisible by 100, in which case it is not
 *    leap year
 *  - unless the same year is also divisible by 400, in which case it's a leap
 *    leap year
 * @version 0.1
 * @date 07-09-2025
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdbool.h>

bool leapYear(int year)
{
  bool is_leap_year = false;

  if (year % 4 == 0)
  {
    is_leap_year = true;
    if (year % 100 == 0)
    {
      is_leap_year = false;
      if (year % 400 == 0)
      {
        is_leap_year = true;
      }
    }
  }
  return is_leap_year;
}

int main(void)
{
  bool is_leap_year = false;

  for (int i = 1582; i < 2101; i++)
  {
    is_leap_year = leapYear(i);
    if (true == is_leap_year)
    {
      printf("The year %d is leap year\n", i);
    }
  }

  return 0;
}