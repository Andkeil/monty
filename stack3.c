#include "monty.h"

/**
 * _mod - compute the rest of the division of the second top element of the
 *        stack by the top element of the stack.
 * @stack: stack
 * @line_number: the line number
 *
 * Return: void
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	int modulo;

	if (*stack == NULL || (*stack)->next == NULL)
		error_handling(ERROR_MOD);
	if ((*stack)->n == 0)
		error_handling(ERROR_DIV_ZERO);
	modulo = (*stack)->next->n % (*stack)->n;
	_pop(stack, line_number);
	(*stack)->n = modulo;
}
