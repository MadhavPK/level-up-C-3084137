#include <stdio.h>
#include <stdlib.h>
#define LENGTH 50

char left_str[LENGTH] = {0};
char right_str[LENGTH] = {0};
char mid_str[LENGTH] = {0};

int size_of_string(char *s);
char *left(char *s, int len);
char *right(char *s, int len);
char *mid(char *s, int offset, int len);

// Calculate the size of the string
int size_of_string(char *s)
{
	int size_of_str = 0;
	for (char *str = s; *str != '\0'; str++)
	{
		size_of_str++;
	}
	size_of_str++; // to account for the NULL char
	printf("size of string = %d\n", size_of_str);
	return size_of_str;
}

// Function to return the left most len characters of the string
char *left(char *s, int len)
{
	// sending the left most len number of characters
	for (int i = 0; i < len; i++)
	{
		*(left_str + i) = *(s + i);
	}
	return left_str;
}

// Function to return the right most len characters of the string
char *right(char *s, int len)
{
	int size_of_str = 0;
	size_of_str = size_of_string(s);
	for (int i = 0; i < len; i++)
	{
		*(right_str + i) = *(s + ((size_of_str - len) + i));
	}
	return right_str;
}

// Function to return the mid characters of the string
char *mid(char *s, int offset, int len)
{
	int size_of_str = 0;
	size_of_str = size_of_string(s);

	for (int i = offset; i < (offset + len); i++)
	{
		*(mid_str + (i - offset)) = *(s + i);
	}
	return mid_str;
}

int main()
{
	char string[] = "Once upon a time, there was a string";

	printf("Original string: %s\n", string);
	printf("Left %d characters: %s\n", 16, left(string, 16));
	printf("Right %d characters: %s\n", 18, right(string, 18));
	printf("Middle %d characters: %s\n", 11, mid(string, 13, 11));

	return (0);
}
