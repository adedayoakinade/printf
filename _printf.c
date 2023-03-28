#include "main.h"
/**
 * print_string - print string
 * @str: input string
 * Return: number of character printed
 */
int print_string(char *str)
{
	int len = 0;

	while (str[len])
		len++;
	write(1, str, len);
	return (len);
}
/**
 * convert_to_string - convert int to string
 * @n: int
 * Return: length of string
 */
int convert_to_string(int n)
{
	int len = 0, m = n, l = 0;
	char *str;
	while (n)
	{
		len++;
		n /= 10;
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
 * _printf - printf like function
 * @format: format string
 * Return: number of characters printed excluding the null byte
 */
int _printf(const char *format, ...)
{
	int len, count = 0, n;

	va_list ap;

	char ch, *str;

	if (*format)
	{
		va_start(ap, format);
		while (*format)
		{
			if (*format == '%')
			{
				switch (*(format + 1)){
				case 'c':
					ch = va_arg(ap, int);
					write(1, &ch, 1);
					break;
				case 's':
					str = va_arg(ap, char*);
					len = print_string(str);
					count += len;
					break;
				case '%':
					ch = 37;
					write(1, &ch, 1);
					break;
				case 'd':
					n = va_arg(ap, int);
					len = convert_to_string(n);
					count += len;
					break;
				case 'b':
					n = va_arg(ap, int);
					len = convert_to_given_format(n, 2, 0);
					count += len;
					break;
				case 'o':
					n = va_arg(ap, int);
					len = convert_to_given_format(n, 8, 0);
					count += len;
					break;
				case 'X':
					n = va_arg(ap, int);
					len = convert_to_given_format(n, 16, 1);
					count += len;
					break;
				case 'x':
					n = va_arg(ap, int);
					len = convert_to_given_format(n, 16, 0);
					count += len;
					break;
				}
				if (*(format + 1) == ('c' || '%'))
					count++;
				format = format + 2;
			}
			ch = *format;
			write(1, &ch, 1);
			count++;
			format++;
		}
	}
	va_end(ap);
	return (count);
}
