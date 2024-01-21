#include "monty.h"

/**
* exe_cal - execute the operator code
* @stack: The linked list stack
* @counter: Counter of the line
* @file: monty file address holder
* @content: Content in a line
*
* Return: null
*/
int exe_cal(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", do_push}, {"pall", call_pall}, {"pint", call_pint},
				{"pop", call_pop},
				{"swap", call_swap},
				{"add", do_add},
				{"nop", call_not},
				{"sub", do_sub},
				{"div", do_div},
				{"mul", do_mul},
				{"mod", do_mod},
				{"pchar", call_pichar},
				{"pstr", call_pstr},
				{"rotl", rot_fst},
				{"rotr", rot_lst},
				{"queue", queue_call},
				{"stack", call_stack},
				{NULL, NULL}
				};
	unsigned int index = 0;
	char *operant;

	operant = strtok(content, " \n\t");
	if (operant && operant[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[index].opcode && operant)
	{
		if (strcmp(operant, opst[index].opcode) == 0)
		{	opst[index].f(stack, counter);
			return (0);
		}
		index++;
	}
	if (operant && opst[index].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, operant);
		fclose(file);
		free(content);
		freestack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
