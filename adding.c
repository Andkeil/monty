#include "monty.h"

/**
 * add_node_fifo - adds a new node at the end of a list
 * @stack: head of stack
 * @newnode: node to add
 *
 * Return: void
 */

void add_node_fifo(stack_t **stack, stack_t *newnode)
{
	stack_t *copy = *stack;

	newnode->next = NULL;
	if (!*stack)
	{
		newnode->prev = NULL;
		*stack = newnode;
	}
	else
	{
		while (copy->next)
			copy = copy->next;
		copy->next = newnode;
		newnode->prev = copy;
	}
}

/**
 * add_node_lifo - adds a new node at the beginning of a list
 * @stack: head of stack
 * @newnode: node to add
 *
 * Return: void
 */
void add_node_lifo(stack_t **stack, stack_t *newnode)
{
	newnode->prev = NULL;
	newnode->next = *stack;

	if (*stack)
		(*stack)->prev = newnode;
	*stack = newnode;
}

/**
 * _push - adds a new node at the beginning of a list
 * @stack: head of stack
 * @line_number: line number
 *
 * Return: void
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode = NULL;
	char *num;
	(void)line_number;

	if (inventory->input[1] == NULL)
		error_handling(ERROR_PUSH);
	else
		num = inventory->input[1];
	if (is_digits(num) == TRUE)
	{
		newnode = malloc(sizeof(stack_t));
		if (newnode == NULL)
			error_handling(ERROR_MALLOC);
	}
	else
		error_handling(ERROR_PUSH);
	newnode->n = atoi(num);
	if (inventory->order == LIFO)
		add_node_lifo(stack, newnode);
	else
		add_node_fifo(stack, newnode);
}
