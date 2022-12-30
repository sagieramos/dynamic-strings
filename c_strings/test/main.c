#include <stdio.h>
#include "c_strings.h"

char *x = "Stanley Osagie ";
char *y = "Ramos";
char *i;
char *j;

int main(void)
{	
	printf("enter your name:\n");
	char a[40];
	scanf("%s", a);
	char *test = concatstr(x, a);
	printf("concatenate: %s\n", test);
	free(test);
	return 0;
}	
