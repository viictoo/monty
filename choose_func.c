#include "monty.h"

void (*pick_func(char *s))(stack_t **, unsigned int)
{
	instruction_t insts[] = {
		{ "push", push_func},
		{ "pall", pall},
		{ "pint", pint_func},
		{ NULL, NULL }
	};
	int i = 0;

	while (insts[i].opcode)
	{
		if (strcmp(s, insts[i].opcode) == 0)
			return (insts[i].f);

		++i;
	}

	return (NULL);
}
void push_func(stack_t **stack, unsigned int line_number)
{
	char *value = strtok(NULL, "\t\n ");
	int n;

	if (!value)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (!isdigit(value[0]) && value[0] != '-')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	n = atoi(value);
	add_dnodeint(stack, n);
}
