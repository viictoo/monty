#include "monty.h"


void sub_func(stack_t **head, unsigned int line_number)
{
    stack_t *current = *head;

    if ((*head)->next == NULL)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
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