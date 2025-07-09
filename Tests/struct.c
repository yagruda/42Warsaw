/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:16:05 by yhruda            #+#    #+#             */
/*   Updated: 2025/03/20 19:02:51 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

// we need to pass pointer to pointer to change head_ref, to change position of head_ref and new_node. First element of list is head_ref and head_ref would be new_node
void push(struct Node** head_ref, int new_data)
{
	Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	new_node->data = new_data;
	new_node->next = (*head_ref);

	// move pointer from head_ref (first element) to new_node
	(*head_ref) = new_node;
}

void insertAfter(struct Node* prev_node, int new_data)
{
	if (prev_node == NULL)
	{
		printf("previous node is null");
		return;
	}
	
	Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}

void insertEnd (struct Node** head_ref, int new_data)
{
	Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	Node* last = *head_ref;
	
	new_node->data = new_data;
	new_node->next = NULL;

	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}

	while (last->next != NULL)
		last = last->next;

	last->next = new_node;
}

void list_example (int a, int b)
{
	// allocate memory for first element of Node
	Node* first = (Node *)malloc(sizeof(Node));
	Node *second = (Node *)malloc(sizeof(Node));
	Node *third = (Node *)malloc(sizeof(Node));
	
	first->data = a;	
	second->data = b;
	third->data = 3;

	first->next = second;
	second->next = third;
	third->next = NULL;

	push(&first, -1);
	insertAfter(first, 0);
	insertEnd(&first, 4);
	
	// first in truth is new_node from push function 

	Node* temp = first;
	printf("\nCreated Linked list is: ");
    while(temp) {
    	printf("%d ", temp->data);
        temp = temp->next;
    }
}



int main()
{
	list_example(1, 2);
    printf("\n");
    return 0;
}