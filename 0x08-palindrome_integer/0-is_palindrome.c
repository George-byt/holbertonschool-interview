#include "palindrome.h"
/**
 * is_palindrome - C program that checks if a number is palindrome.
 * @n: Number to be checked
 * Return: 1 if the number is palindrome, 0 if the number is no palindrome.
 */
int is_palindrome(unsigned long n)
{
unsigned long result = 0, q, rem;
q = n;
while (q != 0)
{
rem = q % 10;
result = result * 10 + rem;
q = q / 10;
};
if (n == result)
{
return (1);
}
else
{
return (0);
};
}
