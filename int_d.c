#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * integ_printf - Simulated printf function with limited functionality.
 * @format: The format string containing conversion specifiers.
 * @...: The variable number of arguments to be formatted and printed.
 *
 */

void integ_printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%' && *(format + 1) == 'd')
		{
			int i = va_arg(args, int);

			printf("%d", i);
			format++;
		}
		else
		{
			putchar(*format);
		}
		format++;
	}
	va_end(args);
}
