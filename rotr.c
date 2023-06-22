#include "monty.h"

/**
 * rotr_func - Rotates the stack to the right.
 * @head: Double pointer to the head of the stack.
 * @line_number: The line number where the function is called.
 * Return: Nothing.
 */

void rotr_func(stack_t **head, unsigned int line_number)
{
	stack_t *temp = NULL;

	(void) line_number;

	if (*head && (*head)->next)
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;

		temp->prev->next = NULL;
		temp->next = *head;

		*head = temp;
	}
}
