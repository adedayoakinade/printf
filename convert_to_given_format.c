#include "main.h"
/**
 * convert_to_given_format - convert inputs according
 * to format specifiers.
 * @n: input number
 * @format: base number
 * @is_upper_hex: 1 for upper hex and 0 for lower.
 * Return: lenght of string
 */
int convert_to_given_format(int n, int format, int is_upper_hex)
{
	int len = 0, m = n, l = 0;

	char *str;
	while (n)
	{
		len++;
		n /= format;
	}
	l = len;
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		exit(1);
	str[len] = '\0';
	while (len - 1 >= 0 && m)
	{
		if (format != 16)
		{
			str[len - 1] = (m % format) + '0';
			m /= format;
			len--;
		}
		else if (format == 16 && m)
		{
			if (m % format < 10)
				str[len - 1] = (m % format) + '0';
			else if (m % format > 10 && is_upper_hex)
				str[len - 1] = (m % format) + 55;
			else
				str[len - 1] = (m % format) + 87;
			m /= format;
			len--;
		}
	}
	write(1, str, l);
	free(str);
	return (l);
}
