#include "main.h"
/**
 *disp_hexadecimal - A function that displays a hexadecimal unsigned number
 *@my_t: The parameter handling the list of args
 *@my_buff:The parameter that handles the array of chars
 *@my_f: The parameter handling the active flags
 *@my_w: The parameter handling the width
 *@my_p: The specification parameter handling the precision
 *@my_s: The size type specification parameter to be casted
 *Return: the hexadecimal unsigned numbers
 */
int disp_hexadecimal(va_list my_t, char my_buff[],
	int my_f, int my_w, int my_p, int my_s)
{
	return (hexa_display(my_t, "0123456789abcdef", my_buff,
	my_f, 'x', my_w, my_p, my_s));
}
/**
*hexa_display - A function that prints low & upp case hexa chars
 *@my_t: The parameter handling the list of args
 *@lambda_func: Array of values to map the number to
 *@my_buff:The parameter that handles the array of chars
 *@my_f:  The parameter handling the active flags
 *@chr_f: The parameter calculating the active flags when printing
 *@my_w: The parameter handling the width
 *@my_p: The specification parameter handling the precision
 *@my_s: The size type specification parameter to be casted
 *Return: The lower and upper case hexadecimal chars
 */
int hexa_display(va_list my_t, char lambda_func[], char my_buff[],
		int my_f, char chr_f, int my_w, int my_p, int my_s)
{
	int x = BUFF_SIZE - 2;
	unsigned long int my_num = va_arg(my_t, unsigned long int);
	unsigned long int init_num = my_num;

	UNUSED(my_w);
	my_num = num_size_unsgnd(my_num, my_s);
	if (my_num == 0)
		my_buff[x--] = '0';
	my_buff[BUFF_SIZE - 1] = '\0';
	while (my_num > 0)
	{
		my_buff[x--] = lambda_func[my_num % 16];
		my_num = my_num / 16;
	}
	if (my_f & F_HASH && init_num != 0)
	{
		my_buff[x--] = chr_f;
		my_buff[x--] = '0';
	}
	x++;
	return (handle_unsgnd(0, x, my_buff, my_f, my_w, my_p, my_s));
}
/**
 *uppcase_hex - A function that displays unsigned upper hexadecimal  numbers
 *@my_t:The parameter handling the list of args
 *@my_buff: The parameter that handles the array of chars
 *@my_f: The parameter handling the active flags
 *@my_w: The parameter handling the width
 *@my_p: The specification parameter handling the precision
 *@my_s:The size type specification parameter to be casted
 *Return: The unsigned upper hexadecimal  char numbers
 */
int uppcase_hex(va_list my_t, char my_buff[],
		int my_f, int my_w, int my_p, int my_s)
{
	return (hexa_display(my_t, "0123456789ABCDEF", my_buff,
	my_f, 'X', my_w, my_p, my_s));
}
