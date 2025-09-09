/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 11:07:08 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/09 13:16:33 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdbool.h>
#include <limits.h>
#include "Includes/ft_printf.h" // include Libft inside

typedef struct s_stack_node
{
    int nbr;
    int index;
    int push_cost;
    bool above_media;
    bool cheapest;
    struct s_stack_node* target_node;
    struct s_stack_node* next;
    struct s_stack_node* prev;
} t_stack_node;

void ft_error(void);
 t_stack_node* ft_new_node(int nbr);
 void ft_free_stack(t_stack_node** head);
 void ft_push(t_stack_node** top_ref, int value);
 void ft_pop (t_stack_node** top_ref);
 void ft_is_empty (t_stack_node** top_ref);
 void ft_read_stack(t_stack_node* current); // for tests to read & write stack
 int ft_parse_args(int argc, char** argv, t_stack_node** stack_a);
void ft_free_arr(char** arr);
void ft_sort_stack(t_stack_node** stack_a, t_stack_node** stack_b, int arguments_count);
void ft_sort_two(t_stack_node** stack_a);
void ft_sort_three(t_stack_node** stack_a);
void ft_sort_turk(t_stack_node** stack_a, t_stack_node** stack_b);
int ft_is_stack_sorted(t_stack_node* stack);

//command_swap.c
void sa(t_stack_node** a, bool print);

//command_rotate.c
void ra(t_stack_node** a, bool print);
void rb(t_stack_node** b, bool print);
void rr(t_stack_node** a, t_stack_node** b, bool print);

//stack_helpers.c
t_stack_node* find_last(t_stack_node* stack);
void append_node(t_stack_node **stack, int n);

//command_reverse_rotate.c
void rra(t_stack_node** a, bool print);
void rrb(t_stack_node** b, bool print);
void rrr(t_stack_node** a, t_stack_node** b, bool print);

//lessons, can be deleted
void delete_first_node(t_stack_node** stack);

#endif
