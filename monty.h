#ifndef MONTY_H
#define MONTY_H

#define STACK_MODE 0
#define QUEUE_MODE 1

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <ctype.h>

extern int mode;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void add_dnodeint(stack_t **head, unsigned int n);
void pall(stack_t **stack, unsigned int line_number);
void (*pick_func(char *s))(stack_t **, unsigned int);
void push_func(stack_t **stack, unsigned int line_number);
void pint_func(stack_t **stack, unsigned int line_number);
void pop_func(stack_t **head, unsigned int line_number);
void swap_func(stack_t **head, unsigned int line_number);
void add_func(stack_t **head, unsigned int line_number);
void sub_func(stack_t **head, unsigned int line_number);
void div_func(stack_t **head, unsigned int line_number);
void nop_func(stack_t **head, unsigned int line_number);
void mul_func(stack_t **head, unsigned int line_number);
void mod_func(stack_t **head, unsigned int line_number);
void pchar_func(stack_t **head, unsigned int line_number);
void pstr_func(stack_t **stack, unsigned int line_number);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void rotl_func(stack_t **head, unsigned int line_number);
void rotr_func(stack_t **head, unsigned int line_number);
#endif /* MONTY_H*/
