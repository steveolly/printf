#ifndef MAIN_H
#define MAIN_H

typedef struct format
{
	char *id;
	int (*f)();
}match;

int _printf(const char *format, ...);
int _putchar(char c);
void integ_printf(const char *format, ...);
int printf_char(va_list val);
int printf_string(va_list val);
int _strlenc(const char *str);
int _strlen(char *str);
int print_37(void);
int print_dec(va_list args);
int print_int(va_list args);

#endif
