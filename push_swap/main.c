/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 11:05:31 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/08 15:12:33 by yhruda           ###   ########.fr       */
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


/*
 we assume we don't have letters (so we don't check for it).
 We check - do we have space in argv? 
 if no, we push it directly to stack using ft_atoi
 else if yes, we create a temp arr of strings and fill it using ft_split
 then we push each element of temp arr to stack_a using ft_atoi
 finally we call ft_free_arr
*/

int ft_parse_args(int argc, char** argv, t_stack_node** stack_a)
{
    int i = 1; // start from first arg, not ./push_swap
    int j = 0;
    int arguments_count = 0;
    char** temp_arr;
    
    while (i < argc)
    {
        if (ft_strchr(argv[i], ' ') == NULL)
        {
            append_node(stack_a, ft_atoi(argv[i]));
            arguments_count++;
        }
        else
        {
            ft_printf("found space in argv\n");
            temp_arr = ft_split(argv[i], ' ');
            while (temp_arr[j] != NULL)
            {
                append_node(stack_a, ft_atoi(temp_arr[j]));
                j++;
                arguments_count++;
            }
            ft_free_arr(temp_arr);
        }
        i++;	
    }
    return arguments_count; 	// return count of numbers pushed to stack
}

int main (int argc, char** argv)
{	

    // array of Stack Nodes that we crated, imagine as arr of Integers int* arr;
	t_stack_node* a;
	t_stack_node* b;
	int arguments_count;

    a = NULL; 
    b = NULL;
    arguments_count = 0;
    
    // as norm requires, stack has to be created before checking args. 
    if (argc < 2)
        ft_error();

    arguments_count = ft_parse_args(argc, argv, &a);

	if (!ft_is_stack_sorted(a))
		ft_sort_stack(&a, &b, arguments_count); // if we have only one number we would just return from it
    
    ft_read_stack(a);

    ft_free_stack(&a);
    ft_free_stack(&b);

    return (0);
}