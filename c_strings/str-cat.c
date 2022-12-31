#include "c_strings.h"
#include <unistd.h>

/**
*concatstr - A function that concatenate unknown length/size of
*two strings.
*
*@str1: a string
*@str2: another string
*
*Return: pointer to str.
*/

char *concatstr(char *str1, char *str2)
{
	size_t c, d, i, j;

	c = 0;
	d = 0;
	i = 0;
	j = 0;

	while (*(str1 + c) != '\0')
		c++;
	while (*(str2 + d) != '\0')
		d++;
	char *str = (char *)malloc(((c + d) * sizeof(char)) + 1);

	if (str == NULL)
	{
		write(1, "Memory not allocated.\n", 22);
		exit(0);
	}
	else
	{
		while (i < c)
		{
			*(str + i) = *(str1 + i);
			i++;
		}
		while (j < d)
		{
			*(str + i) = *(str2 + j);
			j++;
			i++;
		}
	*(str + i) = '\0';
	}

	return (str);
}
