#include "monty.h"
/**
 * free_stack - free all malloced memory for stack
 *
 * Return: void
 */
void free_stack(void)
{
	stack_t *tmp, *head;

	if (inventory->stack)
	{
		head = inventory->stack;
		while (head)
		{
			tmp = head->next;
			free(head);
			head = tmp;
		}
	}
}
/**
 * free_all - free all malloced memory
 *
 * Return: void
 */
void free_all(void)
{
	if (inventory != NULL)
	{
		if (inventory->file != NULL)
			fclose(inventory->file);
		if (inventory->line != NULL)
			free(inventory->line);
		if (inventory->input != NULL)
			free(inventory->input);
		free_stack();
		free(inventory);
	}
}

/**
 * error_handling - errors, it handles it
 * @e: index number of error message
 *
 * Return: void
 */
void error_handling(int e)
{
	unsigned int n;
	static char *const errors[] = {
		"Error: malloc failed\n", "USAGE: monty file\n",
		NULL, NULL,
		"usage: push integer\n", "can't pint, stack empty\n",
		"can't pop an empty stack\n", "can't swap, stack too short\n",
		"can't add, stack too short\n"
	};
	if (inventory)
		n = inventory->lnum;
	if (e <= 1)
		dprintf(STDOUT_FILENO, "%s", errors[e]);
	else if (e == 2)
		dprintf(STDOUT_FILENO, "Error: Can't open file %s\n",
			inventory->filename);
	else if (e == 3)
		dprintf(STDOUT_FILENO, "L%u: unknown instruction %s\n", n,
			inventory->input[0]);
	else if (e >= 4)
		dprintf(STDOUT_FILENO, "L%u: %s", n, errors[e]);
	free_all();
	exit(EXIT_FAILURE);
}

/**
 * is_digits - check if string is all digits
 * @num: number to check if all chars are digits
 *
 * Return: TRUE or FALSE
 */
int is_digits(char *num)
{
	int i;

	for (i = 0; num[i] != '\0'; i++)
	{
		if (num[i] == '-' && i == 0)
			i++;
		if (isdigit(num[i]) == FALSE)
			return (FALSE);
	}
	return (TRUE);
}
