#include "monty.h"

/**
 * pchar_func - function that prints characters.
 * @head: double pointer to the head of a stack.
 * @line_number: The line number where the function is called.
 * Return: Nothing.
 */

void pchar_func(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	if ((*head)->n >= 0 && (*head)->n <= 127)
		printf("%c\n", (*head)->n);
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
}
