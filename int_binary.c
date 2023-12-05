#include "main.h"
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
		my_num[x--] = (my_num % 10) + '0';
		my_num = my_num / 10;
	}
	x++;
	return (write_num(smaller_than_zero, x, my_buff, my_f, my_w, my_p, my_s));
}
