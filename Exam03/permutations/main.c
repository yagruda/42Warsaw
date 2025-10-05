/*
Assignment name  : permutations
Expected files   : *.c *.h
Allowed functions: puts, malloc, calloc, realloc, free, write
---------------------------------------------------------------

Write a program that will print all the permutations of a string given as argument.

The solutions must be given in alphabetical order.

We will not try your program with strings containing duplicates (eg: 'abccd').

For example this should work:

$> ./permutations a | cat -e
a$

$> ./permutations ab | cat -e
ab$
ba$

$> ./permutations abc | cat -e
abc$
acb$
bac$
bca$
cab$
cba$
*/

#include "unistd.h"
#include "stdio.h"
#include <stdlib.h>

void swap(char* a, char* b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

int ft_strlen(char* str)
{
	int i = 0;

	while (str[i])
	{
		i++;
	}

	return i;
}
void sort_str(char* str, int len);

void permutation(char* str, int len, int step)
{
	if (step == len)
	{
		printf("%s\n", str);
		return;
	}
	else
	{
		for(int i = step; i <= len; i++)
		{
			swap(&str[i], &str[step]);
			permutation(str,len, step+1);
			swap(&str[i], &str[step]);
		}
	}
	//sort_str(str,len);
}

void sort_str(char *str, int len)
{
    for (int i = 0; i < len - 1; i++)
        for (int j = i + 1; j < len; j++)
            if (str[i] > str[j])
            {
                char tmp = str[i];
                str[i] = str[j];
                str[j] = tmp;
            }
}

int main(int argc, char** argv)
{
	if (argc != 2)
		return 0;

	char* input = argv[1];
	int len = ft_strlen(input);

	sort_str(input, len);

	// Generate and print all permutations
	permutation(input, len - 1, 0);

	return 0;
}