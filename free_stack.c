#include "monty.h"
#include <stdbool.h>
/**
 * free_stack - Frees all the elements of a stack.
 * @stack: Double pointer to the head of the stack.
 * Return: Nothing.
 */
void free_stack(stack_t *stack)
{
	stack_t *current = stack;
	stack_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}



/**
 * is_integer - Checks if a string represents a valid integer.
 * @str: The string to be checked.
 * Return: True if the string is a valid integer, false otherwise.
 */
bool is_integer(const char *str)
{
	if (str == NULL || *str == '\0')
		return (false);

	if (*str == '-' || *str == '+')
		str++;

	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (false);
		str++;
	}

	return (true);
}
