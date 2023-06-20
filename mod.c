#include "monty.h"


void mod_func(stack_t **head, unsigned int line_number)
{
    stack_t *current = *head;

    if ((*head)->next == NULL)
    {
        fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    if ((*head)->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }
    (*head)->next->n = (*head)->next->n % (*head)->n;
     *head = (*head)->next;
    (*head)->prev = NULL;
    free(current);
}
