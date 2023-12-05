#include "main.h"
/**
 *handle_flags - A function that calculates the active flags
 *@format: The formated string paramter to be evaluated
 *@x: The flag parameter to be evaluated
 *Return: The active flag number digit on success
 */
int handle_flags(const char *format, int *x)
{
	int z = *x + 1, y = 0, my_f = 0;
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};

	while (format[z] != '\0')
	{
		while (FLAGS_CH[y] != '\0')
		{
			if (format[z] == FLAGS_CH[y])
			{
				my_f = my_f | FLAGS_ARR[y];
				break;
			}
			y++;
		}
		if (FLAGS_CH[y] == 0)
			break;
		z++;
	}
	*x = z - 1;
	return (my_f);
}

/**
 * handle_print - A function that displays args based on their respective types
 * @fmt: A format string parameter to handle the list of arguments
 * @my_l: The argument list parameter to be evaluated
 * @pos: The index parameter of the buffer
 * @my_buff: The parameter that handles the array of chars
 * @my_f: A parameter that evaluates the active flags
 * @my_w: A parameter that handles the width of the array of strings
 * @my_p: The precision specificiation parameter
 * @my_s: The size specification parameter
 * Return: 1 on sucess, else -1 on failuire
*/

int handle_print(const char *fmt, int *pos, va_list my_l, char my_buff,
		int my_f, int my_w, int my_p, int my_s)
{
	int x, y, chr_out = -1;
	fmt_t fmt_types[] = {
		{'c', display_chr},
		{'s', display_string},
		{'%', display_percent},
		{'i', display_int},
		{'d', display_int},
		{'\0', NULL}
	};

	x = 0;
	while (fmt_types[x].fmt != '\0')
	{
		if (fmt[*pos] == '\0')
			return (-1);

		y = y + write(1, "%%", 1);
		if (my_w)
		{
			--(*pos);
			while (fmt[*pos] != ' ' && fmt[*pos])
			{
				--(*pos);
				if (fmt[*pos] == ' ')
					--(*pos);
				return (1);
			}
		}
		else if (fmt[*pos - 1] == ' ')
			y = y + write(1, "", 1);
		y = y + write(1, &fmt[*pos], 1);
		return (y);
	}
	return (chr_out);
}
/**
 *handle_size - A function that handles the casting size args
 *@format:  A format string parameter to handle the list of arguments
 *@x: The argument parameter as a list specification
 *Return: The precision value based on the specified sizing
 */
int handle_size(const char *format, int *x)
{
	int my_s = 0;
	int z = *x + 1;

	if (format[z] == 'h')
		my_s = S_SHORT;
	else if (format[z] == 'h')
		my_s = S_LONG;
	if (my_s != 0)
		*x = z;
	else
		*x = z - 1;
	return (my_s);
}
/**
 *handle_width - À function that handles the width of the stdout printing
 *@format:  A format string parameter to handle the list of arguments
 *@x: The argument parameter as a list specification
 *@my_l: The argument list parameter to be evaluated
 *Return: The desired width for printing specification
 */
int handle_width(const char *format, int *x, va_list my_l)
{
	int my_w = 0;
	int z  = *x + 1;

	while (format[z] != '\0')
	{
		if (format[z] == '*')
		{
			z++;
			my_w = va_arg(my_l, int);
			break;
		}
		else if  (check_if_digit(format[z]))
		{
			my_w *= 10;
			my_w = my_w + format[z] - '0';
		}
		else
			break;
		z++;
	}
	*x = z - 1;
	return (my_w);
}

/**
 *handle_precision - A function that handles the precision for printing
 *@format:  A format string parameter to handle the list of arguments
 *@x: The argument parameter as a list specification
 *@my_l: The argument list parameter to be evaluated
 *Return: The desired precision for printing specification
 */
int handle_precision(const char *format, int *x, va_list my_l)
{
	int z = *x + 1;
	int my_p = -1;

	if (format[z] != '.')
		return (my_p);
	my_p = 0;
	z += 1;
	while (format[z] != '\0')
	{
		if (format[z] == '*')
		{
			z++;
			my_p = va_arg(my_l, int);
		}
		else if (check_if_digit(format[z]))
		{
			my_p *= 10;
			my_p += format[z] - '0';
			break;
		}
		else
			break;
		z++;
	}
	*x = z - 1;
return (my_p);
}
