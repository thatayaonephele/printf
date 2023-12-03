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
