#include "monty.h"

/**
 * add_dnodeint - adds new node at beginning of a list
 * @head: pointer
 * @n: element
 * Return: address o the new element
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
 * print_dlistint - function that prints all the elements of a dbly linked list
 * @h: pointer
 * Return: number of nodes
 */

void pall(stack_t **stack, unsigned int line_number)
{
	unsigned int i = 0;
    stack_t *h = *stack;
    (void) line_number;

	if (!h)
		exit(EXIT_FAILURE);

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		i++;
	}
}
