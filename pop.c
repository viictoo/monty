#include "monty.h"

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