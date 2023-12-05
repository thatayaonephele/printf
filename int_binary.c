#include "main.h"
/**
 *handle_unsgnd - A function that writes a number of unsignd type
 *@smaller_than_zero: A parameter verifying if number is pos or neg
 *@pos: The positional index src for where num commences
 *@my_buff: The buffer parameter that handles the array of chars
 *@my_f: The parameter handling the active flags
 *@my_w: The parameter handling the width
 *@my_p: The specification parameter handling the precision
 *@my_s: The size type specification parameter to be casted
 *Return: Number of written chars.
 */
int handle_unsgnd(int smaller_than_zero, int pos,
		char my_buff[], int my_f, int my_w, int my_p, int my_s)
{
	int my_l = BUFF_SIZE - pos - 1, x = 0;
	char del = ' ';

	UNUSED(smaller_than_zero);
	UNUSED(my_s);
	if (pos == BUFF_SIZE - 2 && my_buff[pos] == '0' && my_p == 0)
		return (0);
	if (my_p < my_l  && my_p > 0)
		del = ' ';
	for (; my_p > my_l; my_l++)
		my_buff[--pos] = '0';
	if (!(my_f & F_MINUS) && (my_f & F_ZERO))
		del = '0';
	if (my_w * (-1) < my_l)
	{
		x = 0;
		while (x < my_w - my_l)
		{
			my_buff[x] = del;
			x++;
		}
		my_buff[x] = '\0';
		if (!(my_f & F_MINUS))
			return (write(1, &my_buff[0], x) + write(1, &my_buff[pos], my_l));
		else
			return (write(1, &my_buff[pos], my_l) + write(1, &my_buff[0], x));
	}
	return (write(1, &my_buff[pos], my_l));
}
/**
 * display_int- A funciton that prints integers to the stdout
 *@my_f:A parameter that evaluates the active flags
 *@my_buff:The parameter that handles the array of chars
 *@my_p:The precision specificiation parameter
 *@my_s:The size type specification parameter to be casted
 *@my_t:The argument list parameter
 *@my_w:A parameter that handles the width of the array of strings
 *Return: The integer to be displayed on the stdout
 */
int display_int(va_list my_t, char my_buff[], int my_f,
		int my_w, int my_p, int my_s)
{
	int tmp = 2, smaller_than_zero = 0;
	int x;
	unsigned long my_num;
	long lin = va_arg(my_t, long), my_const = 0;

	x = BUFF_SIZE - tmp;
	lin = cast_num_size(lin, my_s);

	if (lin == my_const)
		my_buff[x--] = '0';
	my_buff[BUFF_SIZE - 1] = '\0';
	my_num = (unsigned long)lin;

	if (lin * (-1) > 0)
	{
		my_num = (unsigned long)((-1) * lin);
		smaller_than_zero = 1;
	}
	while (my_num > 0)
	{
		my_buff[x--] = (my_num % 10) + '0';
		my_num = my_num / 10;
	}
	x++;
	return (write_num(smaller_than_zero, x, my_buff, my_f, my_w, my_p, my_s));
}
/**
 *display_unsgnd - A function that displays a number of unsigned type
 *@my_t:The parameter handling the list of args
 *@my_buff: The parameter that handles the array of chars
 *@my_f: The parameter handling the active flags
 *@my_w: The parameter handling the width
 *@my_p: The specification parameter handling the precision
 *@my_s: The size type specification parameter to be casted
 *Return: The number of unsigned chars to stdout
 */
int display_unsgnd(va_list my_t, char my_buff[],
		int my_f, int my_w, int my_p, int my_s)
{
	unsigned long int my_num = va_arg(my_t, unsigned long int);
	int x = BUFF_SIZE - 2;

	my_num = num_size_unsgnd(my_num, my_s);
	if (my_num == 0)
		my_buff[x--] = '0';
	my_buff[BUFF_SIZE - 1] = '\0';
	while (my_num > 0)
	{
		my_buff[x--] = (my_num % 10) + '0';
		my_num /= 10;
	}
	x++;
	return (handle_unsgnd(0, x, my_buff, my_f, my_w, my_p, my_s));
}
/**
 * octal_disp - A function that displays an octal notation number
 * @my_t:The parameter handling the list of args
 * @my_buff: The parameter that handles the array of chars
 * @my_f: The parameter handling the active flags
 * @my_w:The parameter handling the width
 * @my_p:The specification parameter handling the precision
 * @my_s: The size type specification parameter to be casted
 * Return: The number in octal format
 */
int octal_disp(va_list my_t, char my_buff[],
		int my_f, int my_w, int my_p, int my_s)
{
	unsigned long int my_num = va_arg(my_t, unsigned long int);
	unsigned long int init_num = my_num;
	int x = BUFF_SIZE - 2;

	UNUSED(my_w);
	my_num = num_size_unsgnd(my_num, my_s);
	if (my_num == 0)
		my_buff[x--] = '0';
	my_buff[BUFF_SIZE - 1] = '\0';
	while (my_num > 0)
	{
		my_buff[x--] = (my_num % 8) + '0';
		my_num /= 8;
	}
	if (my_f & F_HASH && init_num != 0)
		my_buff[x--] = '0';
	x++;
	return (handle_unsgnd(0, x, my_buff, my_f, my_w, my_p, my_s));
}
