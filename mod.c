#include "monty.h"

/**
 * mod_func - Computes the remainder of dividing the
 * top two elements of the stack.
 * @head: Double pointer to the head of the stack.
 * @line_number: The line number where the function is called.
 * Return: Nothing
 */

void mod_func(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;

	if (!(*head) || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n = (*head)->next->n % (*head)->n;
	*head = (*head)->next;
	(*head)->prev = NULL;
	free(current);
}
