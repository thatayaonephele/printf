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
int display_char(va_list my_t, char my_buff[], int my_f,
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
	int my_l = 0, x;

	UNUSED(my_buff);
	UNUSED(my_f);
	UNUSED(my_w);
	UNUSED(my_p);
	UNUSED(my_s);

	if (s == NULL)
	{
		s = "(null)";
		if (my_p >= 6)
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
			write(1, &s[0], my_l);
			x = my_w - my_l;
			while (x > 0)
			{
				write(1, " ", 1);
				x--;
			}
			return (my_w);
		}
		else
		{
			x = my_w - my_l;
			while (x > 0)
			{
				write(1, " ", 1);
				x--;
			}
			write(1, &s[0], my_l);
			return (my_w);
		}
	}
	return (write(1, s, my_l));
}
/**
 * handle_buff -A fucntion that displays the buffer content if available
 * @my_buff: The parameter housing the array of char characters
 * @buff_pos: The parameter for handling the index position of the buffer
 * Return:Nothing (void funciton)
 */
void handle_buff(char my_buff[], int *buff_pos)
{
	if ((*buff_pos * (-1) < 0))
		write(1, &my_buff[0], *buff_pos);
	*buff_pos = 0;
}
