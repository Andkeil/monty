#include "monty.h"

/**
 * main - main function for monty program
 * @argc: argument count
 * @argv: arguments
 *
 * Return: Always 0
 */

int main(int argc, char **argv)
{
	size_t n;
	void (*execute)(stack_t **stack, unsigned int line_number);

	inventory = NULL;
		if (argc != 2)
			error_handling(ERROR_USAGE_FILE);

	inventory_build();
	inventory->filename = argv[1];
	inventory->file = fopen(inventory->filename, "r");
	if (inventory->file == NULL)
		error_handling(ERROR_OPEN_FILE);

	while (getline(&inventory->line, &n, inventory->file) > 0)
	{
		inventory->lnum++;
		if (parse_line(inventory->line) == EXIT_FAILURE)
			continue;
		execute = find_op();
		execute(&inventory->stack, inventory->lnum);
	}
	free_all();
	return (EXIT_SUCCESS);
}
