#include "main.h"

/**
 * _isdigit - Check if a character is a digit
 * @w: The number to be checked
 * Return: 1 for a digit or 0 for any else
 */

int _isdigit(int w)
{
	if  (w >= 48 && w <= 57)
	{
	return (1);
	}
	return (0);
}
