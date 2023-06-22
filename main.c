#include "monty.h"
#define BUFFER_SIZE 10000

int mode = STACK_MODE;


/**
 * validate_arguments - Validates the command-line arguments.
 * @ac: The argument count.
 * @av: The argument vector.
 * Return: Nothing.
 */
void validate_arguments(int ac, char **av)
{
	(void)av;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * open_file - function that opens file.
 * @filename: name of file to be opened
 * Return: Nothing.
 */
FILE *open_file(char *filename)
{
	FILE *fp = fopen(filename, "r");

	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	return (fp);
}


/**
 * handle_unknown_instruction - Handles unknown instructions.
 * @line_number: The line number of the unknown instruction.
 * @instruct: The unknown instruction.
 * @opcode: The opcode string.
 * @fp: The file pointer.
 * @stack: head node
 * Return: Nothing.
 */
void handle_unknown_instruction(int line_number, char *instruct,
		char *opcode, FILE *fp, stack_t **stack)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, instruct);
	free_stack(*stack);
	free(opcode);
	fclose(fp);
	exit(EXIT_FAILURE);
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
	void (*instruction_func)(stack_t **, unsigned int);
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
			line_number++;
		else if (strcmp(instruct, "stack") == 0)
			mode = STACK_MODE;
		else if (strcmp(instruct, "queue") == 0)
			mode = QUEUE_MODE;
		else
		{
			instruction_func = pick_func(instruct);
			if (instruction_func)
				instruction_func(&stack, line_number);
			else
				handle_unknown_instruction(line_number, instruct, opcode, fp, &stack);
		}
		line_number++;
	}
	free(opcode);
	free_stack(stack);
	fclose(fp);
}



/**
 * main - Entry point of the program
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on success
 */

int main(int ac, char **av)
{
	FILE *fp = open_file(av[1]);

	validate_arguments(ac, av);
	parse_file(fp);
	return (0);
}
