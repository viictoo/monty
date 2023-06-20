#include "monty.h"

void rotl_func(stack_t **head, unsigned int line_number)
{
    int data;
    if (*head)
    {
        data = (*head)->n;
        pop_func(head, line_number);
        add_dnodeint_end(head, data);
    }
}

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