#include "main.h"
/**
 *display_char - A function that prints a char,followed by a new line.
 *@my_buff: The buffer of array type responsible for printing
 *@my_f:  The parameter handling the active flags
 *@my_p: The specification parameter handling the precision
 *@my_s: The specifier parameter handling the size
 *@my_t: Arguments to be printed
 *@my_w: The parameter handling the width
 *Return:The counted amount of chars displayed
 */
int display_chr(va_list my_t, char my_buff[], int my_f,
		int my_w, int my_p, int my_s)
{
	char chr = va_arg(my_t, int);

	return (write_chr_handler(chr, my_buff, my_f, my_w, my_p, my_s));
}

/**
 *display_percent - A function that displays the percent sign
 *@my_buff: The buffer of array type responsible for printing
 *@my_f: The parameter handling the active flags
 *@my_p: The specification parameter handling the precision
 *@my_s: The specifier parameter handling the size
 *@my_w: The parameter handling the width
 *@my_t: The parameter that displays a list of arguments
 *Return: The ampesent sign
 */
int display_percent(va_list my_t, char my_buff[],
		int my_f, int my_w, int my_p, int my_s)
{
	UNUSED(my_t);
	UNUSED(my_buff);
	UNUSED(my_f);
	UNUSED(my_w);
	UNUSED(my_p);
	UNUSED(my_s);
	return (write(1, "%%", 1));
}
/**
 *display_string - A function that prints strings
 *@my_buff: The buffer of array type responsible for printing
 *@my_f: The parameter handling the active flags
 *@my_p: The specification parameter handling the precision
 *@my_s: The specifier parameter handling the size
 *@my_t: The list of arguments to be printed
 *@my_w: The parameter handling the width
 *Return: The output of the array of strings to be displayed
 */
int display_string(va_list my_t, char my_buff[], int my_f,
		int my_w, int my_p, int my_s)
{
	char *s = va_arg(my_t, char *);
	int my_l = 0, x, z = 6, y = 1;

	UNUSED(my_buff);
	UNUSED(my_f);
	UNUSED(my_w);
	UNUSED(my_p);
	UNUSED(my_s);

	if (s == NULL)
	{
		s = "(null)";
		if (my_p >= z)
			s = "      ";
	}
	while (s[my_l] != '\0')
		my_l++;
	if (my_p < my_l  && my_p >= 0)
		my_l = my_p;
	if (my_w * (-1) < my_l)
	{
		if (my_f & F_MINUS)
		{
			write(y, &s[0], my_l);
			x = my_w - my_l;
			while (x > 0)
			{
				write(y, " ", y);
				x--;
			}
			return (my_w);
		}
		else
		{
			x = my_w - my_l;
			while (x > 0)
			{
				write(y, " ", y);
				x--;
			}
			write(y, &s[0], my_l);
			return (my_w);
		}
	}
	return (write(y, s, my_l));
}
/**
 * handle_buff -A fucntion that displays the buffer content if available
 * @my_buff: The parameter housing the array of char characters
 * @buff_pos: The parameter for handling the index position of the buffer
 * Return:Nothing (void funciton)
 */
void handle_buff(char my_buff[], int *buff_pos)
{
	int y = 1;

	if ((*buff_pos > 0) is true)
		write(y, &my_buff[0], *buff_pos);
	*buff_pos = 0;
}
/**
 *disp_binary - A function that prints an unsigned binary number
 *@my_t:The parameter handling the list of args
 *@my_buff:The parameter that handles the array of chars
 *@my_f: The parameter handling the active flags
 *@my_w:The parameter handling the width
 *@my_p: The specification parameter handling the precision
 *@my_s:The size type specification parameter to be casted
 *Return: The numbers of unsigned chars printed to the stdout
 */
int disp_binary(va_list my_t, char my_buff[],
		int my_f, int my_w, int my_p, int my_s)
{
	unsigned int lin, mui, x, total;
	int pos, y = 1;
	unsigned int a[32];

	UNUSED(my_buff);
	UNUSED(my_f);
	UNUSED(my_w);
	UNUSED(my_p);
	UNUSED(my_s);
	lin = va_arg(my_t, unsigned int);
	mui = INT_MAX;
	a[0] = lin / mui;
	x = 1;

	while (x < 32)
	{
		mui = mui / 2;
		a[x] = (lin / mui) % 2;
		x++;
	}
	x = 0;
	total = 0;
	pos = 0;
	while (x < 32)
	{
		total = total + a[x];
		if (total || (x <= 32 && x >= 29))
		{
			char k = '0' + a[x];

			write(y, &k, y);
			pos++;
		}
		x++;
	}
	return (pos);
}
