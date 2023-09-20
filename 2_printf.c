#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - Custom printf function that handles specific format specifiers.
 * @format: A format string containing format specifiers.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	int count = 0;
	int num;

	unsigned int num;
	unsigned int mask;

	char *str;
    
	while (*format)
	{
	if (*format == '%')
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
	str = va_arg(args, char*);
	while (*str)
	{
	_putchar(*str);
	str++;
	count++;
	}
	}
	break;
	case 'd':
	case 'i':

	{
	num = va_arg(args, int);
	printf("%d", num);
	count++;
	}
	break;
	case 'b':

	{
	num = va_arg(args, unsigned int);
	mask = 1 << (sizeof(unsigned int) * 8 - 1);
                        
	while (mask > 0)
	{
	_putchar((num & mask) ? '1' : '0');
	mask >>= 1;
	count++;
	}
	}
	break;
	case '%':

	_putchar('%');
	count++;
	break;
	default:

	break;
	}
	}
		else 
	{

	_putchar(*format);
	count++;
	}
	format++;
	}

	va_end(args);
	return (count);
}
