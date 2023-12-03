#include "main.h"

/***WRITE_CHR_HANDLER***/
/**
 *write_chr_handler - A function that prints strings, followed by a new line.
 *@my_buff: The buffer of array type responsible for printing
 *@chr: The char parameter types to be handled
 *@my_f:  The parameter handling the active flags
 *@my_p: The specification parameter handling the precision
 *@my_s: The specifier parameter handling the size
 *@my_w: The parameter handling the width
 * Return: The printed numbet amount of chars
 */
int write_chr_handler(char chr, char my_buff[], int my_f,
		int my_w, int my_p, int my_s)
{
	int x = 0;
	char del = ' ';

	UNUSED(my_p);
	UNUSED(my_s);

	if (my_f & F_ZERO)
		del = '0';

	my_buff[x++] = chr;
	my_buff[x] = '\0';

	if (!(my_w <= 1))
	{
		my_buff[BUFF_SIZE - 1] = '\0';
		x = 0;
		while (x < my_w - 1)
		{
		my_buff[BUFF_SIZE - x - 2] = del;
		if ((my_f & F_MINUS))
			return (write(1, &my_buff[0], 1) + write(1,
						&my_buff[BUFF_SIZE - x - 1],
						my_w - 1));
		else
			return (write(1, &my_buff[BUFF_SIZE - x - 1], my_w - 1
						+ write(1, &my_buff[0], 1)));
		x++;
		}
	}
	return (write(1, &my_buff[0], 1));
}
