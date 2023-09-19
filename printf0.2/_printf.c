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
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

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
		count += printf("%s", va_arg(args, char *));
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

int main(void)
{
	int n;

	n = _printf("Hello, %s! %c is awesome.%%%s\n", "world", 'C', "Have a nice day");
	printf("Number of characters printed: %d\n", n);

	return (0);
}
