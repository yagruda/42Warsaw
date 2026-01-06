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

void swap(int* a, int* b)
{
	int temp = *a;
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
void print_arr(int* arr, int len)
{
	for (int i = 0; i <= len; i++)
	{
		printf("%d", arr[i]);
	}
	printf("\n");
}
void permutation(int* str, int len, int step)
{
	if (step == len)
	{
		print_arr(str,len);
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
	return;
}

int main(int argc, char** argv)
{
	if (argc != 2)
		return 0;

	//char* input = argv[1];

	//int len = ft_strlen(input);

	// Generate and print all permutations

	int arr[5] = {0,1,2,3,4};
	int len = (sizeof(arr) / sizeof(int));
	printf("%d\n", len);
	permutation(arr, len - 1, 0);

	return 0;
}