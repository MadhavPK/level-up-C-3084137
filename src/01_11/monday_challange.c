/**
 * @file monday_challenge_2.c
 * @author MK
 * @brief
 * @version 0.1
 * @date 25-02-2026
 *
 * @copyright Copyright (c) 2026
 *
 */
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

bool leapYear(int year);

int main(void)
{
  time_t now;
  int num_days_months[] = {
      31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  char *month_names[] = {
      "January", "February", "March", "April", "May", "June",
      "July", "August", "September", "October", "Novemeber",
      "December"};

  char *week_days[] = {
      "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday",
      "Friday", "Saturday"};

  struct tm *today;

  int monday;
  // flag to check if the next monday is in next month
  int mflag;

  time(&now);
  today = localtime(&now);

  // Today's info
  printf("Today: %s, %s %d, %d\n",
         week_days[today->tm_wday],
         month_names[today->tm_mon],
         today->tm_mday,
         today->tm_year + 1900);

  // Leap year adjustment
  num_days_months[1] = leapYear(today->tm_year + 1900);

  monday = (1 - today->tm_wday);
  if (monday < 1)
  {
    monday += 7 + today->tm_mday;
  }
  else
  {
    monday += today->tm_mday;
  }

  // Check if next monday is in the next month
  mflag = today->tm_mon;
  if (monday > num_days_months[today->tm_mon])
  {
    monday -= num_days_months[today->tm_mon];
    mflag++;
    mflag %= 12; // flip back to January
  }

  printf("Next Monday will be the %d of %s\n",
         monday,
         month_names[mflag]);

  return 0;
}

// Check if the year is leap year
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
  if (is_leap_year == true)
  {
    return 29;
  }
  else
  {
    return 28;
  }
}