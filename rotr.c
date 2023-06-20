#include "monty.h"

void rotr_func(stack_t **head, unsigned int line_number)
{
    int data;
    stack_t *current = *head;
    
    (void)line_number;

    while (current->next)
    {
        current = current->next;
    }

    data = current->n;
    current->prev->next = NULL;
    free(current);
    add_dnodeint(head, data);

}