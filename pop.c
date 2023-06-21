#include "monty.h"


/**
 * pop_func - Removes the top element of the stack.
 * @head: Double pointer to the head of the stack.
 * @line_number: The line number where the function is called.
 * Return: Nothing.
 */

void pop_func(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*head = (*head)->next;
	if (*head)
	{
		(*head)->prev = NULL;
		free(current);
	}
}
