/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 11:05:31 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/05 22:15:03 by yhruda           ###   ########.fr       */
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
void ft_parse_args(int argc, char** argv, struct stack_node** stack_a)
{
	// if argv has characters other than digits, space or '-' or '+' or is empty or dublicates, call ft_error and exit
	// else (if success) create a list using ft_list_args.
	
	// ft_list_args(argc, argv);
	(void)argv;
	ft_printf("has %d argc\n", argc);

	int i = 1;
	int j = 0;
	while (i < argc)
	{
		
		if (ft_strchr(argv[i], ' ') == NULL)
		{
			ft_printf("we don't have spaces in argvs, I write as it is\n");
			ft_push(stack_a, ft_atoi(argv[i]));
		}
		else
		{
			ft_printf("we have space in argv\n");
			char** temp_arr = ft_split(argv[i], ' ');
			while (temp_arr[j] != NULL)
			{
				ft_push(stack_a, ft_atoi(temp_arr[j]));
				j++;
			}
		}
		i++;
	}


	
	// char	**ft_split(char const *s, char c)
	// int	ft_atoi(const char *str)
	// int	ft_strlen(const char *s)
	// char	*ft_strchr(const char *s, int c)
	
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
	// TBD: Decide, do I need to make any ft_parse_args return 0 for succes and -1 for fail and etc



	// just a test 


	// !! TBD MORNING
	ft_read_stack(stack_a); // TBD !!!!! Here I have an issue. I guess because (struct stack_node** current). ASK GPT!
	// !! TBD MORNING
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);

	return (0);
}