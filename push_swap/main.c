/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 11:05:31 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/06 12:56:41 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
int ft_list_args (int argc, char** argv)
{
	// create a list of integers using ft_atoi from argv
	// return the list
}
*/
void ft_free_arr(char** arr)
{
	int i = 0;
	while (arr[i] != NULL)
		free(arr[i++]);
	free(arr);
}

/*
 we assume we don't have letters (so we don't check for it).
 We check - do we have space in argv? 
 if no, we push it directly to stack using ft_atoi
 else if yes, we create a temp arr of strings and fill it using ft_split
 then we push each element of temp arr to stack_a using ft_atoi
 finally we call ft_free_arr
*/

void ft_parse_args(int argc, char** argv, struct stack_node** stack_a)
{
	int i = 1; // start from first arg, not ./push_swap
	int j = 0;
	char** temp_arr;
	
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' ') == NULL)
			ft_push(stack_a, ft_atoi(argv[i]));
		else
		{
			ft_printf("found space in argv\n");
			temp_arr = ft_split(argv[i], ' ');
			while (temp_arr[j] != NULL)
			{
				ft_push(stack_a, ft_atoi(temp_arr[j]));
				j++;
			}
		}
		i++;	
	}
	ft_free_arr(temp_arr);
}

int main (int argc, char** argv)
{	

	// array of Stack Nodes that we crated, imagine as arr of Integers int* arr;
	struct stack_node* stack_a;
	struct stack_node* stack_b;
	
	stack_a = NULL; 
	stack_b = NULL;
	
	// as norm requires, stack has to be created before checking args. 
	if (argc < 2)
		ft_error();

	ft_parse_args(argc, argv, &stack_a);

	ft_read_stack(stack_a);

	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);

	return (0);
}