/**
 * @file commas_challenge.c
 * @author MK
 * @brief Format the integer values
 * @version 0.1
 * @date 21-03-2026
 *
 * @copyright Copyright (c) 2026
 *
 */
#include <stdio.h>
#include <stdint.h>
#include <string.h>

void convert2string(int value);

int main()
{
	int values[10] = {
			123, 1899, 48266, 123456, 9876543,
			10100100, 5, 500000, 99000111, 83};

	for (uint8_t i = 0; i < 10; i++)
	{
		convert2string(values[i]);
	}

	return (0);
}

// Convert the int value to string with commas separation
void convert2string(int value)
{
	char str[20] = {0};						// Original copy without commas
	char str_cpy[20] = {0};				// Duplicate copu with commas
	sprintf(str, "%d", value);		// copy the value as string in str
	uint8_t length = strlen(str); // calculate the number of digits in the number
	// If number of digits are is then 3...
	if (length > 3)
	{
		//... we need to insert commas
		int8_t num_of_commas = (length - 1) / 3; // number of commas needed
		/* * Index Trace Logic:
		 * i (Target): Moves every step to fill str_cpy from right to left.
		 * k (Source): Moves only when a digit is copied; stays still when ',' is inserted.
		 * comma_cnt: Tracks digits placed since last comma; triggers comma at 3, then resets.
		 */
		for (int8_t i = (length + num_of_commas) - 1, k = length - 1, comma_cnt = 0; k >= 0; k--, i--)
		{
			// copy only the last 3 digits
			if (k >= (length - 3))
			{
				str_cpy[i] = str[k];
				comma_cnt++;
				continue;
			}
			// insert comma in str_cpy
			if ((comma_cnt % 3 == 0) && (comma_cnt != 0))
			{
				str_cpy[i] = ',';
				k++;					 // this is needed otherwise we move ahead in str index tracking
				comma_cnt = 0; // reset the counter
				continue;
			}
			else
			{
				// after last 3 digits are copied, this section is used to copy the
				// remaining digits
				str_cpy[i] = str[k];
				comma_cnt++;
				continue;
			}
		}
		str_cpy[length + num_of_commas] = '\0'; // Null terminate for safety
		printf("%s\n", str_cpy);
	}
	else
	{
		// Print number directly as less than 3 digits
		printf("%s\n", str);
	}
}
