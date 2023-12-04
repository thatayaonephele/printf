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
