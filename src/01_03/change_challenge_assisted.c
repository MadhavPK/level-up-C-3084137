/**
 * @brief make change using fewest number of coins
 * Coins available are Quarter, Dime, Nickel and Penny
 * Quarter  - 25 cents
 * Dime     - 10 cents
 * Nickel   - 5 cents
 * Penny    - 1 cent
 * Given a specific dollar amount calculate the way to make change
 * using fewest number of coins
 * Example: 98 cents = 3 Quarters, 2 Dimes, 3 Pennies
 * For challange use these amounts
 * 0.49
 * 1.27
 * 0.75
 * 1.31
 * 0.83
 *
 */
#include <stdio.h>

int main(void)
{
  float amount_to_convert[] = {0.49, 1.27, 0.75, 1.31, 0.83};
  int count = 0;
  int coins = 0;
  int quarters = 0;
  int dimes = 0;
  int nickels = 0;
  int pennies = 0;

  /* Loop through all the amount to convert */
  for (count = 0; count < 5; count++)
  {
    /* Initialize the coins */
    quarters = 0;
    dimes = 0;
    nickels = 0;
    pennies = 0;

    printf("Making change for: $%.2f\n", amount_to_convert[count]);
    /* Convert the value to integer so that we don't have to deal with
    discrepancy of float accuracy, as we see in the change_challenge.c
    */
    coins = amount_to_convert[count] * 100;
    /* quarters */
    while (coins >= 25)
    {
      quarters++;
      coins -= 25;
    }
    /* dimes */
    while (coins >= 10)
    {
      dimes++;
      coins -= 10;
    }
    /* nickels */
    while (coins >= 5)
    {
      nickels++;
      coins -= 5;
    }
    /* pennies */
    pennies = coins;
    printf("Quarters = %d\n", quarters);
    printf("Dimes = %d\n", dimes);
    printf("Nickels = %d\n", nickels);
    printf("Pennies = %d\n", pennies);
  }

  return 0;
}