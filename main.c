#include "monty.h"


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
 * main - Entry point of the program
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on success
 */

int main(int ac, char **av)
{
	FILE *fp = NULL;

	validate_arguments(ac, av);
	fp = open_file(av[1]);
	parse_file(fp);
	return (0);
}
