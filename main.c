#include "monty.h"
#define BUFFER_SIZE 10000

int main(int ac, char **av)
{
    FILE *fp;
    char *opcode;
    int line_number = 1;
    char *instruct = NULL;
    void (*instruction_func)(stack_t **, unsigned int);
    stack_t *stack = NULL;

    if (ac != 2)
    {
        fprintf(stderr,"USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    fp = fopen(av[1], "r");
    if (!fp)
    {
        fprintf(stderr,"Error: Can't open file %s\n", av[1]);
        exit(EXIT_FAILURE);
    }

    opcode = malloc(BUFFER_SIZE * sizeof(char));
    if(!opcode)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(opcode, BUFFER_SIZE, fp) != NULL)
    {
        instruct = strtok(opcode, "\t\n ");
        if (instruct[0] == '#')
        {
            line_number++;
            continue;
        }
        instruction_func = pick_func(instruct);
        if (instruction_func)
        {
            instruction_func(&stack, line_number);
        }
        else
        {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, instruct);
            free(opcode);
            fclose(fp);
            exit(EXIT_FAILURE);
        }
        line_number++;
    }
    free(opcode);
    fclose(fp);

    return (0);
}
