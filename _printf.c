#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * printf_char - print a character.
 * @args: the va_list containing the argument.
 * @count: The count of characters printed.
 *
 * Return: The number of characters printed.
 */

void print_char(va_list args, int *count)

{
	char c = va_arg(args, int);
	*count += _putchar(c);
}

/**
 * print_string - print a string
 *
 * @args: the va_list containing the argument
 * @count: the count of characters printed
 */
void print_string(va_list args, int *count)
{
	char *str = va_arg(args, char *);

	if (!str)
		str = "(null)";

	while (*str)
	{
		*count += _putchar(*str);
		str++;
	}
}
/**
 * _printf - Simulated printf function with limited functionality.
 * @format: The format string containing conversion specifiers.
 * @...: The variable number of arguments to be formatted and printed.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	if (!format)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			count += _putchar(*format);
		}
		else
		{
			format++;
			if (!*format)
				break;
			switch (*format)
			{
			case 'c':
				print_char(args, &count);
				break;
			case 's':
				print_string(args, &count);
				break;
			case '%':
				count += _putchar('%');
				break;
			default:
				count += _putchar('%');
				count += _putchar(*format);
				break;
			}
		}
		format++;
	}
	va_end(args);
	return (count);
}
