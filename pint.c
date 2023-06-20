#include "monty.h"

void pint_func(stack_t **stack, unsigned int line_number)
{

	if (!(*stack))
    {
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

	printf("%d\n", (*stack)->n);
}