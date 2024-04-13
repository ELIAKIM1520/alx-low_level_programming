#include "main.h"
/**
  * print_most_numbers - prints from 0 -9 and not 2 and 4
  * Return: void
  */
void print_most_numbers(void)
{
	int i = 48;

	for (i = 48; i <= 57; i++)
	{
		if (i != 50 && i != 52)
		{
			_putchar(i);
		}
	}
	_putchar('\n');
}
