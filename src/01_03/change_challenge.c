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
#define QUARTER 0.25F
#define DIME 0.10L
#define NICKEL 0.05F
#define PENNY 0.01L

int main(void)
{
  float amount_to_convert = 0;
  int quarter = 0;
  int dime = 0;
  int nickel = 0;
  int penny = 0;
  int count = 0;

  printf("Amount to convert: ");
  scanf("%f", &amount_to_convert);

  while (amount_to_convert != 0.00)
  {
    count++;
    printf("amount to convert = %f\n", amount_to_convert);
    if (amount_to_convert >= 0.25)
    {
      quarter = (int)(amount_to_convert / QUARTER);
      amount_to_convert -= (quarter * QUARTER);
    }
    else if (amount_to_convert >= 0.10)
    {
      dime = (int)(amount_to_convert / DIME);
      amount_to_convert -= (dime * DIME);
    }
    else if (amount_to_convert >= 0.05)
    {
      nickel = (int)(amount_to_convert / NICKEL);
      amount_to_convert -= (nickel * NICKEL);
    }
    else if (amount_to_convert >= 0.01)
    {
      penny = (int)(amount_to_convert / PENNY);
      amount_to_convert -= (penny * PENNY);
    }
    if (count == 10)
    {
      break;
    }
  }
  printf("Quarters = %d\n", quarter);
  printf("Dimes = %d\n", dime);
  printf("Nickels = %d\n", nickel);
  printf("Pennies = %d\n", penny);

  return 0;
}