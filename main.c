#include "monty.h"
#define _GNU_SOURCE

bus_t bus = {NULL, NULL, NULL, 0};

/**
* main - interpret the monty code
* @argc: variable that counts argument
* @argv: variable argument vector
*
* Return: 0 Always
*/
int main(int argc, char *argv[])
{
	char *relate;
	FILE *file;
	size_t volume = 0;
	ssize_t check_l = 1;
	stack_t *stack = NULL;
	unsigned int count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	bus.file = file;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (check_l > 0)
	{
		relate = NULL;
		check_l = getline(&relate, &volume, file);
		bus.content = relate;
		count++;

		if (check_l > 0)
			exe_cal(relate, &stack, count, file);

		free(relate);
	}

	freestack(stack);
	fclose(file);
	return (0);
}
