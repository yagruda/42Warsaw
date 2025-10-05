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

<<<<<<< HEAD
#include "unistd.h"
#include "stdio.h"
#include <stdlib.h>

void swap(char* a, char* b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}
=======

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

>>>>>>> 29fa19a64435e984ab9aeb8c2344b8611d61766c

int ft_strlen(char* str)
{
	int len = 0;
	while (str[len])
		len++;
	return len;
}
void sort_str(char* str, int len);

<<<<<<< HEAD
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
=======
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
>>>>>>> 29fa19a64435e984ab9aeb8c2344b8611d61766c

	free(is_used);
	free(current);
	
	return 0;
}