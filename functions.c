#include "main.h"
/**
 *handle_flags - A function that calculates the active flags
 *@format: The formated string paramter to be evaluated
 *@x: The flag parameter to be evaluated
 *Return: The active flag number digit on success
 */
int handle_flags(const char *format, int *x)
{
	int z = *x + 1, y = 0, my_f = 0;
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};

	while (format[z] != '\0')
	{
		while (FLAGS_CH[y] != '\0')
		{
			if (format[z] == FLAGS_CH[y])
			{
				my_f = my_f | FLAGS_ARR[y];
				break;
			}
			y++;
		}
		if (FLAGS_CH[y] == 0)
			break;
		z++;
	}
	*x = z - 1;
	return (my_f);
}

