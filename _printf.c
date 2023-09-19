#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - Simulated printf function with limited functionality.
 * @format: The format string containing conversion specifiers.
 * @...: The variable number of arguments to be formatted and printed.
 *
 * Return: The number of characters printed.
 */

int _printf(const char *format, ...);
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format)
	{
	if (*format != '%')
	{
		putchar(*format);
	count++;
	}
	else
	{
		format++;
		switch (*format)
	{
	case 'c':
	putchar(va_arg(args, int));
		count++;
		break;
	case 's':
	{
		char *str = va_arg(args, char*);
		int j = 0;

		for (j = 0; str[j]; j++)
		{
			putchar(str[j]);
			count++;
		}
		break;
	}
	case '%':
		putchar('%');
		count++;
		break;
	default:
		putchar('%');
		putchar(*format);
		count += 2;
		break;
		}
	}
	format++;
	}

	va_end(args);
	return (count);
}

/**
 * main - main function.
 *
 * Return: 0
 */

int main(void)
{
	_printf("Hello, %s!\n", "Have a nice day");
	_printf("%c is awesome.\n", 'C');
	_printf("%%%s\n", "Have a nice day");

	return (0);
}
