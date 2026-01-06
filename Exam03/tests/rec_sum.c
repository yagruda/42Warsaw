#include "unistd.h"
#include "stdio.h"
#include <stdlib.h>


//classical approach
int ft_recurs(int n)
{
	if (n == 0)
		return 0;
	else
		return n + ft_recurs(n-1);
}

// first approach
// int ft_recurs(int n, int i)
// {
// 	if (i == n + 1)
// 		return 0; // as we came to a limit, we don't need to summ ints above our n;
// 	else
// 		return i + ft_recurs(n, i+1);
// }

int main(int argc, char** argv)
{
	int n = atoi(argv[1]);
	int sum;

	//classical approach
	sum = ft_recurs(n);

	//first approach
	//sum = ft_recurs(n, 1);

	printf("%d\n", sum);

	(void)argc;
	(void)argv;
	return 0;
}