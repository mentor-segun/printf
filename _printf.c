#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - This function gives an output based on a format
 * @format: This is a character string
 *
 * Return: Number of characters that are printed
 */
int _printf(const char *format, ...)
{
	va_list ls_arg;
	int char_prt = 0;
	char c, *str;
	int length_str;
	if (format == NULL)
		return (-1);
	va_start(ls_arg, format);
	while (*format)
	{
		if (*format != '%' || *(format + 1) == '\0')
		{
			write(1, format, 1);
			char_prt++;
		}
		else if (*(format + 1) == '%')
		{
			write(1, "%%", 2);
			char_prt += 2;
			format++;
		}
		else if (*(format + 1) == 'c')
		{
			c = va_arg(ls_arg, int);
			write(1, &c, 1);
			char_prt++;
		}
		else if (*(format + 1) == 's')
		{
			str = va_arg(ls_arg, char*);
			str_len = 0;

			while (str[length_str])
				str_len++;
			write(1, str, length_str);
			char_prt += length_str;
		}
		format++;
	}
	va_end(ls_arg);
	return (char_prt);
}

#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len;
	int len2;
	unsigned int ui;
	void *addr;

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	ui = (unsigned int)INT_MAX + 1024;
	addr = (void *)0x7ffe637541f0;
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);
	_printf("Unsigned:[%u]\n", ui);
	printf("Unsigned:[%u]\n", ui);
	_printf("Unsigned octal:[%o]\n", ui);
	printf("Unsigned octal:[%o]\n", ui);
	_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	_printf("Address:[%p]\n", addr);
	printf("Address:[%p]\n", addr);
	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	_printf("Unknown:[%r]\n");
	printf("Unknown:[%r]\n");
	return (0);
}
