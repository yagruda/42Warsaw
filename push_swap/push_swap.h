/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 11:07:08 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/06 12:09:18 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "Includes/ft_printf.h" // include Libft inside

struct stack_node
{
	int data;
	struct stack_node* next;
};

void ft_error(void);
struct stack_node* ft_new_node(int data);
void ft_free_stack(struct stack_node** head);
void ft_push(struct stack_node** top_ref, int value);
void ft_pop (struct stack_node** top_ref);
void ft_is_empty (struct stack_node** top_ref);
void ft_read_stack(struct stack_node* current); // for tests to read & write stack
void ft_parse_args(int argc, char** argv, struct stack_node** stack_a);

#endif
