#include "monty.h"

/**
 * inventory_build - builds inventory of important variables
 *
 * Return: EXIT_FAILURE or EXIT_SUCCESS
 */

int inventory_build(void)
{
	inventory = malloc(sizeof(inventory_t));
	if (!inventory)
		error_handling(ERROR_MALLOC);

	inventory->input = malloc(sizeof(char *) * 3);
	if (!inventory->input)
	{
		free(inventory);
		error_handling(ERROR_MALLOC);
	}

	inventory->line = NULL;
	inventory->lnum = 0;
	inventory->order = LIFO;
	inventory->stack = NULL;

	return (EXIT_SUCCESS);
}
