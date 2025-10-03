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


/*
 * EXECUTION EXAMPLE:
 * 
 * ./permutations abc
 * abc
 * acb  
 * bac
 * bca
 * cab
 * cba
 
 */



#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int ft_strlen(char* str)
{
	int len = 0;
	while (str[len])
		len++;
	return len;
}

void ft_bubble_sort(char* arr, int size)
{
	char temp;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void permutation(int len, char* orig, char* current, int* is_used, int step)
{
	if (step == len)
	{
		current[step] = '\0';
		puts(current);
	}
	else
	{
		for(int i = 0; i < len; i++)
			if(!is_used[i])
			{
				is_used[i] = 1;
				current[step] = orig[i]; 
				permutation(len,orig,current,is_used, step + 1);
				is_used[i] = 0;
			}
	}

	return;
}
int main(int argc, char** argv)
{
	if (argc != 2)
		return 1;
	
	int len = ft_strlen(argv[1]);
	int* is_used = calloc(len, sizeof(char) * len);
	char* current = malloc(sizeof(char) * len);
	if (!current || !is_used)
		return 1;
	
	ft_bubble_sort(argv[1], len);
	
	permutation(len, argv[1], current, is_used, 0);
	
	return 0;
}