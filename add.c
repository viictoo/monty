#include "monty.h"

/**
 * add_func - adds the value of the second element
 * to that of the top element of the stack.
 * @head: Double pointer to the head of the stack
 * @line_number: The line number where the function is called
 * Return: Nothing
 */

void add_func(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;

	if ((*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n += (*head)->n;
	*head = (*head)->next;
	if (*head)
	{
		(*head)->prev = NULL;
		free(current);
	}
}
