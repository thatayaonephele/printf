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
/**
 *display_ptr - A function that prints a pointer variable type value
 *@my_t: The parameter handling the list of args
 *@my_buff: The parameter that handles the array of chars
 *@my_f: The parameter handling the active flags
 *@my_w:The parameter handling the width
 *@my_p:The specification parameter handling the precision
 *@my_s: The size type specification parameter to be casted
 *Return: The number of ptr variable char types
 */
int display_ptr(va_list my_t, char my_buff[],
		int my_f, int my_w, int my_p, int my_s)
{
	char added_chr = 0, del = ' ';
	int pos = BUFF_SIZE - 2, my_l = 2, pad_src = 1;
	unsigned long n;
	char lambda_func[] = "0123456789abcdef";
	void *ptr_add = va_arg(my_t, void *);

	UNUSED(my_w);
	UNUSED(my_s);

	if (ptr_add == NULL)
		return (write(1, "(nil)", 5));
	my_buff[BUFF_SIZE - 1] = '\0';
	UNUSED(my_p);
	n = (unsigned long)ptr_add;
	while (n > 0)
	{
		my_buff[pos--] = lambda_func[n % 16];
		n = n / 16;
		my_l++;
	}
	if ((my_f & F_ZERO) && !(my_f & F_MINUS))
	del = '0';
	if (my_f & F_PLUS)
		added_chr = '+', my_l++;
	else if (my_f & F_SPACE)
		added_chr = ' ', my_l++;
	pos++;
	return (write_pointer(my_buff, pos, my_l, my_w,
				my_f, del, added_chr, pad_src));
}
