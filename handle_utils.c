#include "main.h"
/**
 * cast_num_size - Casts a number to a specified size
 * @my_num: The parameter to be converted to specified casted size
 * @my_s: The integer size controling the casting paramter
 * Return: The converted casted number at its specified value
 */
long cast_num_size(long my_num, int my_s)
{
	if (my_s == S_LONG)
		return (my_num);
	else if (my_s == S_SHORT)
		return ((short)my_num);
	return ((int)my_num);
}
/**
 * *print_check -Function that verfies eligibilty of a parameter's print status
 *@chr: The char parameter to be verified
 *Return: 1 on Success, else 0 on failuire
 */
int print_check(char chr)
{
	if (!(chr < 127  && chr >= 32))
		return (0);
	return (1);
}
/**
 *check_if_digit - A function that checks if a parameter is a digit
 *@chr: The char parameter to be verified
 *Return: o if c is not a digit, else 1 on success
 */
int check_if_digit(char chr)
{
	if (chr <= '9' && chr >= '0')
		return (1);
	return (0);
}
/**
 *handle_hex_code - A function that adds ascci into the buffer hexadecimal code
 *@my_buff:The parameter that handles the array of chars
 *@pos: The posional index src for appening ascii code
 *@ascii_code: The ascci code parameter to be appended
 *Return: Always Success(3)
 */
int handle_hex_code(char ascii_code, char my_buff[], int pos)
{
	char my_lambda[] = "0123456789ABCDEF";

	if (ascii_code * (-1) > 0)
		ascii_code  =  ascii_code * (-1);
	my_buff[pos++] = '\\';
	my_buff[pos++] = 'x';
	my_buff[pos++] = my_lambda[ascii_code / 16];
	my_buff[pos] = my_lambda[ascii_code % 16];
	return (3);
}
