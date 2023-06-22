#include "monty.h"

/**
 * handle_instruction - Handle file instructions
 * @fp: Pointer to the file to be parsed.
 * @stack: head node
 * @instruct: instruction
 * @line_number: line number
 * @opcode: input buffer
 * Return: Nothing
 */
void handle_instruction(stack_t **stack, unsigned int line_number,
		char *instruct, char *opcode, FILE *fp)
{
	char *argument;
	void (*instruction_func)(stack_t **, unsigned int);

	if (strcmp(instruct, "stack") == 0)
		mode = STACK_MODE;
	else if (strcmp(instruct, "queue") == 0)
		mode = QUEUE_MODE;
	else if (strcmp(instruct, "push") == 0)
	{
		argument = strtok(NULL, "\t\n ");
		if (argument == NULL || !is_integer(argument))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free(opcode);
			free_stack(*stack);
			fclose(fp);
			exit(EXIT_FAILURE);
		}

		if (mode == STACK_MODE)
			add_dnodeint(stack, atoi(argument));
		else if (mode == QUEUE_MODE)
			add_dnodeint_end(stack, atoi(argument));
	}
	else
	{
		instruction_func = pick_func(instruct);
		if (instruction_func)
			instruction_func(stack, line_number);
		else
			handle_unknown_instruction(line_number, instruct, opcode, fp, stack);
	}
}
/**
 * parse_file - Parses the contents of the given file.
 * @fp: Pointer to the file to be parsed.
 * Return: Nothing
 */
void parse_file(FILE *fp)
{
	char *opcode;
	char *instruct = NULL;
	int line_number = 1;
	stack_t *stack = NULL;

	opcode = malloc(BUFFER_SIZE * sizeof(char));
	if (!opcode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	while (fgets(opcode, BUFFER_SIZE, fp) != NULL)
	{
		if (opcode[0] == '\n')
		{
			line_number++;
			continue;
		}

		instruct = strtok(opcode, "\t\n ");
		if (instruct[0] == '#')
		{
			line_number++;
			continue;
		}

		handle_instruction(&stack, line_number, instruct, opcode, fp);
		line_number++;
	}

	free(opcode);
	free_stack(stack);
	fclose(fp);
}
