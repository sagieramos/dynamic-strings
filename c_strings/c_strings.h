#ifndef _c_strings_
#define _c_strings_

typedef struct buff
	{
		float value;
		int index;
	}buff;

extern buff buf;
buff bdecorder(const char *buffer);
void runComm(char *string);
char *concatstr(char *str1, char *str2);

#endif
