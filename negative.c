#include "main.h"
/**
 * convert_negative - convert negative int to
 * give format. example, %o
 * @upper: is uppercase or not
 * @n: negative int
 * @hex_oct: number of bits in one octal or hexadec
 * Return: length
 */
char *convert_negative(int n)
{
	int len, num = 0, one = 1, carry = 0, i = 0;

	char *str;

	str = malloc(33);
	if (str == NULL)
		return (NULL);
	for (len = 0; len < 32; len++)
		str[len] = 49;
	str[32] = '\0';
	i = 31;
	while (n && i >= 0)
	{
		if (n % 2 == 0)
			str[i] = 49;
		else
			str[i] = 48;
		n /= 2;
		i--;
	}
	for (i = 31; i >= 0; i--)
	{
		num = (str[i] - '0') + one + carry;
		if (num == 1)
		{
			str[i] = 49;
			break;
		}
		if (num == 2)
			str[i] = '0';
		if (num == 3)
			str[i] = 49;
		carry = 1;
		one = 0;
	}
	return (str);
}
char hex_value(int n, int upper)
{
	if (n < 10)
		return (n + '0');
	if (n > 10 && upper)
		return(n + 55);
	return (n + 87);
}
/**
 * convert_back_to_10 - provides real number
 * @m: number
 * @bits: group of bits. 2 for binary, 3 for octal
 * and 4 for hexadecimal
 * @upper: 1 for uppercase hexadecimal. 0 otherwise
 * Return: converted string
 */
char *convert_back_to_10(int m, int bits, int upper)
{
	int n, dec, num, base, i, len, j;
	char *str, *p;
	str = convert_negative(m);
	if (bits == 2)
		return (str);
	p = malloc(12);
	if (p == NULL)
		exit(1);
	len = 31;
	i = 10;
	for (j = 0; j < 11; j++)
		p[j] = '0';
	p[11] = '\0';
	while (len >= 0 && i >= 0)
	{
		num = 0;
		if (len >= 2)
			n = bits - 1;
		else
			n = bits - 2;
		while (n >= 0)
		{
			num = num * 10 + (str[len - n] - '0');
			n--;
		}
		dec = 0;
		base = 1;
		while (num)
		{
			dec += (num % 10) * base;
			num /= 10;
			base = base * 2;
		}
		p[i] = hex_value(dec, upper);
		i--;
		len -= bits;
	}
	free(str);
	return (p);
}
/**
 * unsigned_int - prints unsigned int
 * @n: number to print
 * Return: unsigned type of number
 */
unsigned int unsigned_int(int n)
{
	unsigned int m = 1, i, number, num = 0;
	int l, len;

	char *str;
	if (n >= 0)
		return ((unsigned int)n);
	number = -n;
	for (i = 0; i < 32; i++)
		m = m * 2;
	num = m - number;
	while (num)
	{
		len++;
		num /= 10;
	}
	l = len;
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		exit(1);
	str[len] = '\0';
	while (len - 1 >= 0 && m)
	{
		str[len - 1] = (m % 10) + '0';
		len--;
		m /= 10;
	}
	write(1, str, l);
	free(str);
	return (l);
}
/**
 * _strlen - provides string length
 * @str: string
 * Return: length
 */
int _strlen(char *str)
{
	int len = 0;

	while(str[len])
		len++;
	return (len);
}
/**
 * convert_num - convert it to given format
 * @n: number
 * @bits: number of bits. 2, 3 0r 4
 * @upper: uppercase hex 1. 0 otherwise
 * Return: length of string number
 */
int convert_num(int n, int bits, int upper)
{
	char *ptr, *p;

	int i = 0, j, len;

	ptr = convert_back_to_10(n, bits, upper);
	len = _strlen(ptr);
	while (i < len && ptr[i] == '0')
		i++;
	if (i == len)
		return (0);
	p = malloc(len - i);
	for (j = 0; j < len - i; j++)
		p[j] = ptr[i + j];
	len = _strlen(p);
	write(1, p, len);
	free(ptr);
	free(p);
	return (len);
}
