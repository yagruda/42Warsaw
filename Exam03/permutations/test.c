#include "unistd.h"
#include "stdio.h"
#include <stdlib.h>

// for backtracking study, i'd use digits for easier work.

void permutation

int main(int argc, char** argv)
{
	char* str = "acbhfg";
	int len = strln(str);

	permutation(str, 0, len);
	return 0;
}