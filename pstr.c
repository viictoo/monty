#include "monty.h"
/**
 * pstr_func - function that prints all the elements of a dbly linked list
 * @stack: pointer
 * @line_number: unused
 */

void pstr_func(stack_t **stack, unsigned int line_number)
{
    stack_t *head;
    (void) line_number;

	if (!(*stack))
		printf("\n");

    head = *stack;
	while (head)
	{
		if (head->n > 0 && head->n <= 127)
		    printf("%c", head->n);
        else
        {
            printf("\n");
            exit(EXIT_FAILURE);
        }
		head = head->next;
	}
    printf("\n");
}
