/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 11:07:08 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/09 15:18:30 by yhruda           ###   ########.fr       */
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
    bool above_median;
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
t_stack_node* find_min(t_stack_node* stack);
t_stack_node* find_max(t_stack_node* stack);
void append_node(t_stack_node **stack, int n);

//command_reverse_rotate.c
void rra(t_stack_node** a, bool print);
void rrb(t_stack_node** b, bool print);
void rrr(t_stack_node** a, t_stack_node** b, bool print);

//command_push.c
void pa(t_stack_node **a, t_stack_node **b, bool print);
void pb(t_stack_node **b, t_stack_node **a, bool print);
int stack_len(t_stack_node* stack);

//lessons, can be deleted
void delete_first_node(t_stack_node** stack);

// init_a_to_b.c
void current_index(t_stack_node *stack);
void init_nodes_a(t_stack_node *a, t_stack_node *b);
void init_nodes_b(t_stack_node *a, t_stack_node *b);
void cost_analysis_a(t_stack_node *a, t_stack_node *b);
void set_cheapest(t_stack_node *stack);
void move_a_to_b(t_stack_node **a, t_stack_node **b);
void move_b_to_a(t_stack_node **a, t_stack_node **b);
void min_on_top(t_stack_node **stack_a);


int	stack_len(t_stack_node *stack);

#endif
