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
	char *str;

	if (!format)
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
			if (!*format)
				break;

			switch (*format)
			{
			case 'c':
				putchar(va_arg(args, int));
				count++;
				break;
			case 's':
				str = va_arg(args, char*);

				if (!str)
					str = "(null)";

				while (*str)
				{
					putchar(*str++);
					count++;
				}
				break;

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
