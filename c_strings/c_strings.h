#ifndef _c_strings_
#define _c_strings_

typedef struct buftable
	{
		float value;
		int index;
	}buftable;

buftable bdecorder(const char *buffer);
void bufdec(char *string, buftable *self);
char *concatstr(char *str1, char *str2);

#endif
