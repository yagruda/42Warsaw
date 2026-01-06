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

char** permutations;
int perm_count = 0;

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

void permutation (char* str, int l, int r)
{
	int i;
	int len;

	i = l;
	
	if (l == r)
	{
		len = ft_strlen(str);
		int j = 0;
		permutations[perm_count] = malloc(len + 1);
		while (j < len)
		{
			permutations[perm_count][j] = str[j];
			j++;
		}
		permutations[perm_count][j] = '\0';
		perm_count++;
	}
	else
	{
		while (i <= r)
		{
			swap(&str[i], &str[l]);
			permutation(str, l+1, r);
			swap(&str[i], &str[l]);
			i++;
		}
	}
}
int factorial(int n)
{
	if (n <= 1)
		return 1;
	return n * factorial(n - 1);
}

int ft_strcmp(char* s1, char* s2)
{
	int i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return s1[i] - s2[i];
}

int compare_strings(const void* a, const void* b)
{
	return ft_strcmp(*(char**)a, *(char**)b);
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





	// Allocate array for storing permutations
	int total_perms = factorial(len);
	permutations = malloc(total_perms * sizeof(char*));
	
	// Generate all permutations
	permutation(s_buff, 0, len-1);





	
	// Sort permutations alphabetically (bubble sort)
	for (i = 0; i < perm_count - 1; i++)
	{
		for (j = 0; j < perm_count - 1 - i; j++)
		{
			if (ft_strcmp(permutations[j], permutations[j + 1]) > 0)
			{
				char* temp_str = permutations[j];
				permutations[j] = permutations[j + 1];
				permutations[j + 1] = temp_str;
			}
		}
	}
	
	// Print sorted permutations
	for (i = 0; i < perm_count; i++)
	{
		puts(permutations[i]);
		free(permutations[i]);
	}
	
	free(permutations);
	free(s_buff);

	return 0;
}