#include "monty.h"

/**
 * swap_func - Swaps the top two elements of the stack.
 * @head: A double pointer to the head of the stack.
 * @line_number: The line number where the function is called.
 * Return: Nothing.
 */

void swap_func(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head;
	stack_t *next2 = NULL;

	if (!(*head) || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	next2 = temp->next;
	temp->next = next2->next;
	if (next2->next)
	{
		next2->next->prev = temp;
	}
	temp->prev = next2;
	next2->next = temp;
	next2->prev = NULL;
	*head = next2;
}



