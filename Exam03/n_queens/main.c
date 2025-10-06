/*

Level02

Assignement name : n_queens

Expected files : *.c *.h

Allowed functions : atoi, fprintf, write, calloc, malloc, free, realloc, stdout, stderr

-------------------------------------------------------------------------

Write a program that will print all the solutions to the n queens problem
for a n given as argument.
We will not test with negative values.
The order of the solutions is not important.

You will display the solutions under the following format :
<p1> <p2> <p3> ... \n
where pn are the line index of the queen in each colum starting from 0.

For example this should work :
$> ./n_queens 2 | cat -e

$> ./n_queens 4 | cat -e
1 3 0 2$
2 0 3 1$

$> ./n_queens 7 | cat -e
0 2 4 6 1 3 5$
0 3 6 2 5 1 4$
etc...

*/

// fprintf(stdout, "Hello, world!\n");
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "n_queens.h"

int ft_abs(int x)
{
	return(x < 0 ? -x : x);
}

int ft_is_safe(int* arr, int col, int step)
{
	for (int i = 0; i < step; i++)
	{
		if (arr[i] == col || ft_abs(arr[i] - col) == ft_abs(i - step))
			return 0;
	}

	return 1;
}

void n_queens(int* arr, int n, int step)
{
	if (step == n)
	{
		for(int i = 0; i < n; i++)
		{
			fprintf(stdout, "%d", arr[i]);
			if (i < n - 1)
				fprintf(stdout," ");
		}
		fprintf(stdout, "\n");
	}

	for (int col = 0; col < n; col++)
	{
		if (ft_is_safe(arr, col, step))
		{
			arr[step] = col;
			n_queens(arr, n, step + 1);
		}
	}
}

int main (int argc, char** argv)
{
	if (argc != 2)
		return 1;
	int n = atoi(argv[1]);
	int* arr = malloc(sizeof(int)*n);

	n_queens(arr, n, 0);
	
	free(arr);
}
