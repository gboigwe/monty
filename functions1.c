#include "monty.h"

/**
 * call_pop - call the top node on the stack
 * @head: point to first node pointer
 * @counter: variable that count the line
 *
 * Return: null
 */

void call_pop(stack_t **head, unsigned int counter)
{
	stack_t *first;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		freestack(*head);
		exit(EXIT_FAILURE);
	}

	first = *head;
	*head = first->next;

	free(first);
}

/**
 * call_pint - call the top on the node's stack
 * @head: variable pointing to the pointer of first node
 * @counter: variable that count line
 *
 * Return: null
 */

void call_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		freestack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * call_not - do nothing
 * @head: variable pointing to the pointer of first node
 * @counter: variable that count line
 *
 * Return: null
 */

void call_not(stack_t **head, unsigned int counter)
{
	(void) counter;
	(void) head;
}
