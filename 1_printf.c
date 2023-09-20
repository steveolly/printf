#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
    
	int count = 0;
    
	char *str;

	while (*format)
	{
	if (*format == '%')
	{
	format++;
	switch (*format)
	{
	case 'c':
		_putchar(va_arg(args, int));
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

