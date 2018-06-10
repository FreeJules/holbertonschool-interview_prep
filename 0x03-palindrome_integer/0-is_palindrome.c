#include "palindrome.h"
/**
 * is_palindrome - checks whether or not a given integer is a palindrome
 * @n: the number to be checke
 *
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long tmp = n;
	unsigned long reversed_n = 0;

	while (tmp > 0)
	{
		reversed_n = reversed_n * 10 + tmp % 10;
		tmp = tmp / 10;
	}
	if (n == reversed_n)
		return (1);
	return (0);
}
