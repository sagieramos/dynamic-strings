#include "c_strings.h"
#include <unistd.h>
#include <stdlib.h>

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

buftable bdecorder(const char *buffer)
{
	buftable temp = {0};
	unsigned int i = 0, j = 0, k;

	while (buffer[i] != '%')
		i++;

	while (buffer[i + j] != '\0')
		j++;
	char datastr[j];

	for (k = 0; k < j; k++)
		datastr[k] = buffer[k + i + 1];

	datastr[j - 1] = '\0';
	temp.index = strtol(buffer, NULL, 10);
	temp.value = strtod(datastr, NULL);

	return (temp);
}

/**
*bufdec - Buffer Decoder.
*Alowable format foo%bar.
*
*@string: buffer text.
*@self: pointer to a struct.
*
*return: terminate function.
*/

void bufdec(char *string, buftable *self)
{
	int i = 0, j = 0;

	while (string[i] != '\0')
	{
		if (string[i] == '%')
			j++;
		i++;
	}
	if (j != 1)
		return;
	if (string[0] == '%' || string[i - 1] == '%')
		return;
	*self = bdecorder(string);
}
