#include "push_swap.h"

/*
!stack → checks if you received a valid pointer to the stack.
!*stack → checks if the stack is empty (no nodes).
*/

// move stack header
void delete_first_node(t_stack_node** stack)
{
	if (!stack)
		return;
	
	t_stack_node* temp;
	temp = *stack;


	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);

}

/*

void ft_free_stack(t_stack_node** head)
{
    t_stack_node* current;
    t_stack_node* next;

    current = *head;
    
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    free(current);
}
*/