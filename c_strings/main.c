#include <stdio.h>
#include "c_strings.h"

buftable buf;

int main(int argc, char* argv[])
	{
		
		printf("\n\tIndex  \tValue\n");
		for(int i = 1; i < argc; i++){	
		bufdec(argv[i], &buf);
		printf("\t%d\t%.2f\n", buf.index, buf.value);
		}
		printf("\n");
		return 0;
	}
