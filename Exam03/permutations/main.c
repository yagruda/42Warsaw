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
 * 
 * PROCESS FOR "abc":
 * 1. Sort: "abc" (already sorted)
 * 2. pos=0: Try 'a', 'b', 'c'
 *    - Choose 'a': result="a"
 *      - pos=1: Try 'b', 'c' (not 'a' because it's used)
 *        - Choose 'b': result="ab"
 *          - pos=2: Try 'c': result="abc" → PRINT
 *        - Choose 'c': result="ac"  
 *          - pos=2: Try 'b': result="acb" → PRINT
 *    - Choose 'b': result="b"
 *      - Similar process...
 */

/*
 * KEY POINTS FOR THE EXAM:
 * 
 * 1. ALPHABETICAL ORDER:
 *    - CRUCIAL to sort the string before generating permutations
 *    - Without sorting, alphabetical order is not guaranteed
 *    - Use simple but correct sorting algorithm
 * 
 * 2. EFFICIENT BACKTRACKING:
 *    - Use array of used characters for O(n) verification
 *    - Mark/unmark characters correctly
 *    - Don't forget to clean state when returning
 * 
 * 3. MEMORY MANAGEMENT:
 *    - Allocate buffer for current permutation
 *    - Use calloc() to initialize to '\0'
 *    - Free memory when finished
 * 
 * 4. ROBUST VALIDATION:
 *    - Verify number of arguments
 *    - Validate that it only contains letters
 *    - Handle special cases (empty string, spaces)
 * 
 * 5. OPTIMIZATIONS:
 *    - For strings with duplicate characters, use different algorithm
 *    - For very long strings, consider Heap's algorithm
 *    - Avoid regenerating duplicate permutations
 */

// 1 отсортировать строку и вывести
// 2

#include "unistd.h"
#include "stdio.h"
#include <stdlib.h>

void swap(char* a, char* b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

void sort_substring(char* str, int start, int end)
{
	int i = start;
	int j = start;
	char temp;

	while (i < end)
	{
		while (j < end - (i - start))
		{
			if (str[j] > str[j + 1])
			{
				temp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void permutation (char* str, int l, int r)
{
	int i;

	i = l;
	
	if (l == r)
	{
		puts(str);
	}
	else
	{
		sort_substring(str, l, r);
		while (i <= r)
		{
			swap(&str[i], &str[l]);
			permutation(str, l+1, r);
			swap(&str[i], &str[l]);
			i++;
		}
	}
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

int main(int argc, char** argv)
{
	int i = 0;
	int j = 0;
	char* s_buff;
	int len;
	char temp;
	
	if (argc != 2)
		return 0;
	
	j = 0;
	len = ft_strlen(argv[1]);
	s_buff = malloc(sizeof(char) * (len + 1));
	if (!s_buff)
		return 1;

	// write to buff from argv1
	while (i < len)
	{
		s_buff[i] = argv[1][i];
		i++;
	}
	s_buff[i] = '\0';

	// sort by ascending order
	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - 1 - i)
		{
			temp = s_buff[j];
			if (s_buff[j] > s_buff[j+1])
			{
				s_buff[j] = s_buff[j + 1];
				s_buff[j + 1] = temp;
			}
			j++;
		}
		i++;
	}

	permutation(s_buff, 0, len-1);

	//swap((s_buff + len - 1), (s_buff + len - 2)); same as swap(s_buff[len-1], s_buff[len-2]);
	//swap(&s_buff[len-1], &s_buff[len-2]);

	free(s_buff);


	return 0;
}