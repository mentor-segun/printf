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
