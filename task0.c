#include "main.h"

void print_buffer(char buffer[], int *buff_id);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
	int i, p = 0, pchars = 0;
	int flg, wdth, precision, size, buff_id = 0;
	va_list list;
	char buffer[BuffSize];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_id++] = format[i];
			if (buff_id == BuffSize)
				print_buffer(buffer, &buff_id);
			/* write(1, &format[i], 1);*/
			pchars++;
		}
		else
		{
			print_buffer(buffer, &buff_id);
			flg = get_flags(format, &i);
			wdth = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			p = handle_print(format, &i, list, buffer,
				flg, wdth, precision, size);
			if (p == -1)
				return (-1);
			pchars += p;
		}
	}

	print_buffer(buffer, &buff_id);

	va_end(list);

	return (pchars);
}
