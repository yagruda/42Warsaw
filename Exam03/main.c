#include <unistd.h>
#include <stdio.h>

// if before our positon we used this number/character - return false, we shouldn't use it, we should skip it and not start ft_backtrack for this value

int is_valid(int position, int* arr)
{
	for (int i = 0; i < position; i++)
	{
		if (arr[i] == position)
		{
			return 0;
		}
	}

	return 1;
}

void ft_backtrack(int* arr, int arr_len, int position)
{
	if (position == arr_len)
	{
		for(int i = 0; i < arr_len; i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 1; i <= arr_len; i++)
	{
		if (is_valid(position, arr))
		{
			arr[position] = i;
			ft_backtrack(arr,arr_len,position+1);
			arr[position] = 0;
		}
	}
	
}

int main()
{
	int arr[3] = {1, 2, 3};
	int len = sizeof(arr)/sizeof(int);
	
	ft_backtrack(arr, len, 0);
	return 0;
}