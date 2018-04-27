#include "monty.h"

/**
 * _add - add two numbers from the top of that stack
 * @stack: the stack
 * @line_number: the line number
 * Return: none
 */

void _add(stack_t **stack, unsigned int line_number)
{
	int total;

	if (*stack == NULL || (*stack)->next == NULL)
		error_handling(ERROR_ADD);
	total = (*stack)->n + (*stack)->next->n;
	_pop(stack, line_number);
	(*stack)->n = total;
}

/**
 * _nop - does not print, do not pass go, do not collect $200
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
