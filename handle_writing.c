#include "main.h"
/**
 *write_chr_handler - A function that prints strings, followed by a new line
 *@my_buff: The buffer of array type responsible for printing
 *@chr: The char parameter types to be handled
 *@my_f: The parameter handling the active flags
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
 *write_number - A function that writes a number digit
 *@del: The paramater controlling the padding of the array of chars
 *@added_chr: The parameter of the additional char
 *@my_w: The parameter handling the width
 *@my_f: The parameter handling the active flags *@my_l: The length
 number parameter
 *@pos: The index parameter of the the buffer
 *@my_p: The specification parameter handling the precision
 *@my_buff: The buffer of array type responsible for printing
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
		my_buff[pos] = del = ' ';

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
		my_buff[--pad_src] = added_chr;
	return (write(1, &my_buff[pad_src], x - pad_src) + write(1,
				&my_buff[pos], my_l - (1 - pad_src)));
}
/**
 *write_num -A function displaying an array of strings,followed by a new line
 *@my_buff: The buffer of array type responsible for printing
 *@my_f: The parameter handling the active flags
 *@my_w: The parameter handling the width
 *@pos: The index parameter of the the buffer
 *@my_p: The specification parameter handling the precision
 *@my_s: The specifier parameter handling the size
 *@smaller_than_zero: List of arguments parameter
 *Return: The number of chars printed to stdout on success,else 0 on failuire
 */
int write_num(int smaller_than_zero, int pos, char my_buff[],
		int my_f, int my_w, int my_p, int my_s)
{
	char added_chr = 0, del = ' ';
	int my_len = BUFF_SIZE - pos - 1;

	UNUSED(my_s);
	if (!(my_f & F_MINUS) && (my_f & F_ZERO))
		del = '0';
	if (my_f & F_SPACE)
		added_chr = ' ';
	else if (smaller_than_zero)
		added_chr = '-';
	else if (my_f & F_PLUS)
		added_chr = '+';
	return (write_number(pos, my_buff, my_f, my_w, my_p, my_len, del, added_chr));
}

/**
 *handle_ptr - A function that prints the memory address of a pointer variable
 *@my_buff: The buffer parameter that handles the array of chars
 *@pos: The positional index src for where num commences
 *@my_l:  The argument list parameter to be evaluated
 *@my_w: The parameter handling the width
 *@my_f: The parameter handling the active flags
 *@del: The padding char parameter
 *@added_chr: The char parameter for handling the added char
 *@pad_src: Index at which padding should start
 *Return: Number of written chars.
 */
int handle_ptr(char my_buff[], int pos, int my_l,
		int my_w, int my_f, char del, char added_chr, int pad_src)
{
	int x;

	if (my_w * (-1) < my_l)
	{
		x = 3;
		while (x < my_w - my_l + 3)
		{
			my_buff[x] = del;
			x++;
		}
		my_buff[x] = '\0';
		if (del == ' ' && my_f & F_MINUS)
		{
			my_buff[--pos] = 'x';
			my_buff[--pos] = '0';
			if (added_chr)
				my_buff[--pos] = added_chr;
			return (write(1, &my_buff[pos], my_l) + write(1, &my_buff[3], x - 3));
		}
		else if (!(my_f & F_MINUS) && del == '0')
		{
			if (added_chr)
				my_buff[--pad_src] = added_chr;

			my_buff[1] = '0';
			my_buff[2] = 'x';
			return (write(1, &my_buff[pad_src], x - pad_src) +
					write(1, &my_buff[pos],
						my_l - (1 - pad_src) - 2));
		}
		else if (!(my_f & F_MINUS) && del == ' ')
		{
			my_buff[--pos] = 'x';
			my_buff[--pos] = '0';
			if (added_chr)
				my_buff[--pos] = added_chr;
			return (write(1, &my_buff[3], x - 3) +
					write(1, &my_buff[pos], my_l));
		}
	}
	my_buff[--pos] = 'x';
	my_buff[--pos] = '0';
	if (added_chr)
		my_buff[--pos] = added_chr;
	return (write(1, &my_buff[pos], BUFF_SIZE - pos - 1));
}
