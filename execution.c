#include "monty.h"

/**
 * find_op - find the proper operation and return its function
 *
 * Return: needed function
 */

void (*find_op(void))(stack_t **stack, unsigned int line_number)
{
	char *input_op;
	instruction_t *i;
	static instruction_t instructions[] = {
		{"push", _push}, {"pall", _pall},
		{"pint", _pint}, {"pop", _pop}, {"swap", _swap},
		{"add", _add}, {"nop", _nop}, {NULL, NULL}
	};

	i = instructions;
	input_op = inventory->input[0];
	while (i->opcode && strncmp(i->opcode, input_op, strlen(input_op)))
		i++;
	if (!i->f)
		error_handling(ERROR_UNKNOWN);

	return (i->f);
}

/**
 * parse_line - parse line/getline into input
 * @line: input line
 *
 * Return: EXIT_FAILURE or EXIT_SUCCESS
 */

int parse_line(char *line)
{
	char *s, *delim;
	int i, len;

	delim = "\n ";
	s = inventory->line;
	len = strlen(s);

	for (i = 0; s[i] == delim[0] || s[i] == delim[1]; i++)
		;
	if (i == len)
		return (EXIT_FAILURE);

	inventory->input[0] = strtok(line, delim);
	if (inventory->input[0][0] == '#')
		return (EXIT_FAILURE);
	inventory->input[1] = strtok(NULL, delim);
	return (EXIT_SUCCESS);
}
