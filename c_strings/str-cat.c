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

buff bdecorder(const char *buffer)
	{
		buff temp;
		unsigned int i, j = 0, k;
		float data;
		unsigned short index;
		char indexstr[3];
	
		for (i = 0; *(buffer + i) != '%'; i++)
			*(indexstr + i) = *(buffer + i);

		while(*(buffer + i + j) != '\0')
			j++;

		char *datastr = (char *)malloc(j);
		
		if (datastr == NULL)
		{
			write(1, "Memory not allocated.\n", 22);
			exit(0);
		}
	
		for(k = 0; k < j; k++)
			*(datastr + k) = *(buffer + k + i + 1);

		*(datastr + j - 1) = '\0';

		data = atof(datastr);
		index = atoi(indexstr);
		
		free(datastr);

		temp.value = data;
		temp.index = index;
		
		return (temp);
	}

char *test = "34%887.78";
buff buf;

void runComm(char *string)
{
	buf = bdecorder(string);
}
