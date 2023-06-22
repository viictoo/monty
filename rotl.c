#include "monty.h"

/**
 * rotl_func - Rotates the stack to the left.
 *
 * @head: Double pointer to the head of the stack.
 * @line_number: The line number where the function is called.
 * Return: Nothing.
 */
void rotl_func(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	unsigned int data = 0;

	(void) line_number;

	if (current && current->next)
	{
		while (current->next != NULL)
		{
			data = current->n;
			current->n = current->next->n;
			current->next->n = data;
			current = current->next;
		}
	}
}

/**
 * add_dnodeint_end - Adds a new node at the end of a
 * doubly linked list.
 * @head: Double pointer to the head of the doubly linked list.
 * @n: The integer value to be stored in the new node.
 * Return: Pointer to the newly added node, or NULL on failure.
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *post, *temp;

	post  = malloc(sizeof(stack_t));
	if (!post)
		return (NULL);

	post->n = n;
	post->next = NULL;

	if (!(*head))
	{
		post->prev = NULL;
		*head = post;
	}
	else
	{
		temp = *head;
		while (temp->next)
			temp  = temp->next;
		temp->next = post;
		post->prev = temp;
	}
	return (post);
}
