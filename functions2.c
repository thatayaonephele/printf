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
