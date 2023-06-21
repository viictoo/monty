#include "monty.h"

/**
 * pint_func - Prints the value at the top of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line number where the function is called.
 * Return: Nothing.
 */

void pint_func(stack_t **stack, unsigned int line_number)
{

	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
