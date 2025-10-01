#include "unistd.h"
#include "stdio.h"
#include <stdlib.h>

/*
Write a program in C to print the Fibonacci Series using recursion.

Test Data :
Input number of terms for the Series (< 20) : 10

Expected Output:

 Input number of terms for the Series (< 20) : 10                                
 The Series are :                                                                
 1  1  2  3  5  8  13  21  34  55  
*/

int fibonacci(int* target, int count, int prevNum, int num)
{
	int temp = num;
	if (*target == count)
	{
		return 0;
	}
	else
	{
		num += prevNum;
		prevNum = temp;
		printf("%d\n", num);
		fibonacci(target, count+1, prevNum, num);
		return 0;
	}
}

int main(int argc, char** argv)
{
	int prNum = 0;
	int* i = malloc(sizeof(int));

	*i = atoi(argv[1]);

	fibonacci(i, 0, 0, 1);

	(void)argc;
	(void)argv;
	free(i);
	return 0;
}