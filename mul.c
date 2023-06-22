#include "monty.h"

/**
 * mul_func - Computes the product the top
 * two elements of the stack.
 * @head: Double pointer to the head of the stack.
 * @line_number: The line number where the function is called.
 * Return: Nothing
 */

void mul_func(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;

	if (!(*head) || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n *= (*head)->n;
	*head = (*head)->next;
	if (*head)
	{
		(*head)->prev = NULL;
		free(current);
	}
}
