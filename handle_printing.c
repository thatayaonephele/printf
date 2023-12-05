#include "main.h"
/**
 * _printf - A function that prints the desired function
 * @format: The format type parameter of  the function
 * Return: The printed chars on  success,else -1 on failuire
 */
int _printf(const char *format, ...)
{
	char my_buff[BUFF_SIZE];
	int x = 0, output = 0, char_out = 0, buff_pos = 0, my_s;
	int my_p, my_w, my_f;
	va_list my_l;

	if (format == NULL)
		return (-1);
	va_start(my_l, format);
	while (format && format[x] != '\0')
	{
		if (format[x] == '%')
		{
			handle_buff(my_buff, &buff_pos);
			my_f = handle_flags(format, &x);
			my_w = handle_width(format, &x, my_l);
			my_p = handle_precision(format, &x, my_l);
			my_s = handle_size(format, &x);
			++x;
			output = handle_print(format, &x, my_l, my_buff,
					my_f, my_w, my_p, my_s);
			if (output == -1)
				return (-1);
			char_out = char_out + output;
		}
		else
		{
			my_buff[buff_pos++] = format[x];
			if (buff_pos == BUFF_SIZE)
				handle_buff(my_buff, &buff_pos);
			char_out++;
		}
		x++;
	}
	handle_buff(my_buff, &buff_pos);
	va_end(my_l);
	return (char_out);
}
