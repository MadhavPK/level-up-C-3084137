#include <stdio.h>
#include <string.h>

void center_text(int width, char *text)
{
	int number_of_spaces_added = 0;
	int size_of_text = strlen(text);
	// If the size of text is less than console width then
	// text can be displayed in one line...
	if (size_of_text < width)
	{
		//...add spaces
		number_of_spaces_added = (width - size_of_text) / 2;
		for (int i = 0; i < number_of_spaces_added; i++)
		{
			printf(" ");
		}
		// print the text
		printf("%s\n", text);
		return;
	}
	else
	{
		//... else the size of text is greater than width of console
		// and the text will not fit the row
		char split_text[size_of_text - width];

		// First print all the text and fill up the row
		for (int i = 0; i < width; i++)
		{
			printf("%c", text[i]);
		}
		printf("\n");
		// Then, you split the remaining part of text an dstore it
		for (int i = 0; i < (size_of_text - width); i++)
		{
			split_text[i] = text[width + i];
		}
		// call this funtion with width of 80 and splited stiring as text recusrsively
		center_text(80, split_text);
	}
}

int main()
{
	/* some sample text to center */
	char *title[] = {
			"March Sales",
			"My First Project",
			"Centering output is so much fun!",
			"This title is very long, just to see whether the code can handle such a long title"};
	int x;

	/* output each of the strings, centered */
	for (x = 0; x < 4; x++)
	{
		/* assume the screen width to be 80 characters */
		center_text(80, title[x]);
	}

	return (0);
}
