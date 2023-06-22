#include "monty.h"


/**
 * pick_func - Picks a function based on the given string.
 * @s: The string used to determine the function to be picked.
 * Return: Pointer to a function that takes stack_t**
 * and unsigned int as arguments,
 * or NULL if no matching function is found.
 */
void (*pick_func(char *s))(stack_t **, unsigned int)
{

	int i = 0;
	instruction_t insts[] = {
		{ "push", push_func},
		{ "pall", pall},
		{ "pint", pint_func},
		{ "pop", pop_func},
		{ "swap", swap_func},
		{ "add", add_func},
		{ "sub", sub_func},
		{ "div", div_func},
		{ "nop", nop_func},
		{ "mul", mul_func},
		{ "mod", mod_func},
		{ "pchar", pchar_func},
		{ "pstr", pstr_func},
		{ "rotl", rotl_func},
		{ "rotr", rotr_func},
		{ NULL, NULL }
	};

	while (insts[i].opcode)
	{
		if (strcmp(s, insts[i].opcode) == 0)
			return (insts[i].f);

		++i;
	}

	return (NULL);
}


/**
 * push_func - Pushes an element onto the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line number where the function is called.
 * Return: Nothing
 */

void push_func(stack_t **stack, unsigned int line_number)
{
	char *value = strtok(NULL, "\t\n ");
	int n;

	if (!value)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	if (!isdigit(value[0]) && value[0] != '-')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if (value == NULL || !is_integer(value))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	n = atoi(value);
	if (mode == STACK_MODE)
		add_dnodeint(stack, n);
	else if (mode == QUEUE_MODE)
		add_dnodeint_end(stack, n);

}
