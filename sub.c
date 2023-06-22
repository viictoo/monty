#include "monty.h"

/**
 * sub_func - subtracts the value of the second element
 * from that of the top element of the stack.
 * @head: A double pointer to the head of the stack.
 * @line_number: The line number where the function is called.
 * Return: Nothing
 */
void sub_func(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;

	if ((*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
        free_stack(*head);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n -= (*head)->n;
	*head = (*head)->next;
	if (*head)
	{
		(*head)->prev = NULL;
		free(current);
	}
}
