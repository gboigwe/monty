#include "monty.h"

/**
 * call_pichar - print the char at the top of stack
 * @head: variable with the head node
 * @counter: variable that counts line
 *
 * Return: line
 */

void call_pichar(stack_t **head, unsigned int counter)
{
	stack_t *first;

	first = *head;
	if (!first)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		freestack(*head);
		exit(EXIT_FAILURE);
	}
	if (first->n > 127 || first->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(bus.file);
		free(bus.content);
		freestack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", first->n);
}
