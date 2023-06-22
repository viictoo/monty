#include "monty.h"

/**
 * add_dnodeint - adds new node at beginning of a list
 * @head: double pointer to the head of the stack.
 * @n: data to be contained in the node.
 * Return: Nothing
 */

void add_dnodeint(stack_t **head, unsigned int n)
{
	stack_t *ptr;

	if (!head)
	{
		exit(EXIT_FAILURE);
	}
	ptr  = malloc(sizeof(stack_t));
	if (!ptr)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	ptr->n = n;
	ptr->next = *head;
	ptr->prev = NULL;
	if (*head)
		(*head)->prev = ptr;

	*head = ptr;

}

/**
 * pall - function that prints all the elements of a dbly linked list
 * @stack: double pointer to the head of a stack.
 * @line_number: The line number where the function is called.
 * Return: number of nodes
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;
	(void) line_number;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
