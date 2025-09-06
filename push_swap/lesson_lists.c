/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 11:05:31 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/05 16:41:42 by yhruda           ###   ########.fr       */
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
void ft_parse_args(int argc, char** argv)
{
	// if argv has characters other than digits, space or '-' or '+' or is empty or dublicates, call ft_error and exit
	// else (if success) create a list using ft_list_args.
	
	// ft_list_args(argc, argv);
	(void)argc;
	(void)argv;
	ft_printf("has some args\n");
	
}

int main (int argc, char** argv)
{	

	// array of Stack Nodes that we crated, imagine as arr of Integers int* arr;
	struct stack_node* stack_a;
	stack_a = NULL; 
	
	// as norm requires, stack has to be created before checking args. 
	if (argc < 2)
		ft_error();
	ft_parse_args(argc, argv);

	ft_is_empty(&stack_a);

	ft_push(&stack_a, 5);
	ft_push(&stack_a, 6);
	ft_push(&stack_a, 7);
	ft_pop(&stack_a); // delete top_value;
	ft_push(&stack_a, 8);

	// just a pointer to a top element
	struct stack_node* current = stack_a;
	while (current != NULL)
	{
		ft_printf("I SEE %d READING A STACK 'A' \n", current->data);
		current = current->next; 
	}
	
	ft_is_empty(&stack_a);

	ft_free_stack(&stack_a);

	return (0);
}