#include "monty.h"

/**
 * _add - add top two elements of the stack
 * @stack: stack
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
 * _nop - it does nothing. NOTHING.
 * @stack: stack
 * @line_number: the line number
 *
 * Return: void
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * _sub - subtract top element of the stack from the second to the top
 * @stack: stack
 * @line_number: the line number
 *
 * Return: void
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	int diff;

	if (*stack == NULL || (*stack)->next == NULL)
		error_handling(ERROR_SUB);
	diff = (*stack)->next->n - (*stack)->n;
	_pop(stack, line_number);
	(*stack)->n = diff;
}

/**
 * _div - divide second from the top element of the stack by the top element
 * @stack: stack
 * @line_number: the line number
 *
 * Return: void
 */

void _div(stack_t **stack, unsigned int line_number)
{
	int quot;

	if (*stack == NULL || (*stack)->next == NULL)
		error_handling(ERROR_DIV);
	if ((*stack)->n == 0)
		error_handling(ERROR_DIV_ZERO);
	quot = (*stack)->next->n / (*stack)->n;
	_pop(stack, line_number);
	(*stack)->n = quot;
}

/**
 * _mul - multiply the top two elements of the stack
 * @stack: stack
 * @line_number: the line number
 *
 * Return: void
 */

void _mul(stack_t **stack, unsigned int line_number)
{
	int prod;

	if (*stack == NULL || (*stack)->next == NULL)
		error_handling(ERROR_MUL);
	prod = (*stack)->next->n * (*stack)->n;
	_pop(stack, line_number);
	(*stack)->n = prod;
}
