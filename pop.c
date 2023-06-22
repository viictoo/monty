#include "monty.h"


/**
 * pop_func - Removes the top element of the stack.
 * @head: Double pointer to the head of the stack.
 * @line_number: The line number where the function is called.
 * Return: Nothing.
 */

void pop_func(stack_t **head, unsigned int line_number)
{
	stack_t *current;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current = (*head)->next;
	free(*head);
	if (current)
		(current)->prev = NULL;
	*head = current;
}
