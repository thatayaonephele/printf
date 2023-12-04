#include "main.h"
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

/**
 * write_number - A function that writes a number digit
 * @del: The paramater controlling the padding of the array of chars
 * @added_chr: The parameter of the additional char
 * Return: 0 on failuire,else the number of displayed chars on the std out
 */
int write_number(int pos, char my_buff[], int my_f, int my_w, int my_p,
		int my_l, char del, char added_chr)
{
	int pad_src = 1;
	int x;

	if (pos == BUFF_SIZE - 2 && my_buff[pos] == '0' && my_w == 0 && my_p == 0)
		return (0);
	if (pos == BUFF_SIZE - 2 && my_buff[pos] == '0' && my_p == 0)
		my_buff[pos], del = del, " ";

	if (my_p < my_l && my_p > 0)
		del = ' ';
	while (my_p > my_l)
		my_buff[--pos] = '0';
	if (added_chr < 0 || added_chr > 0)
		my_l++;
	if (my_w * (-1) < my_l)
	{
		x = 1;
		while (x < my_w - my_l + 1)
		{
			my_buff[x] = del;
			x++;
		}
		my_buff[x] = '\0';

		if (!(my_f & F_MINUS) && del  == ' ')
		{
			if (added_chr)
				my_buff[--pos] = added_chr;
			return (write(1, &my_buff[1], x - 1) + write(1, &my_buff[pos], my_l));
		}
		else if  (added_chr)
		{
			my_buff[--pos] = added_chr;
			return (write(1, &my_buff[pos], my_l) + write(1, &my_buff[1], x - 1));
		}
		else if (del == '0' && (my_f & F_MINUS))
		{
			if (added_chr)
				my_buff[--pos] = added_chr;
			return (write(1, &my_buff[pos], my_l) + write(1, &my_buff[1], x - 1));
		}
	}
	if (added_chr)
		my_buff[--pos] = added_chr;
	return (write(1, &my_buff[pos], my_l));
}
