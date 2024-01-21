#include "monty.h"

/**
 * call_pstr - print string at the top of stack
 * @head: variable with the head node
 * @counter: variable that counts line
 *
 * Return: none
 */
void call_pstr(stack_t **head, unsigned int counter)
{
	stack_t *first;
	(void)counter;

	first = *head;
	while (first)
	{
		if (first->n > 127 || first->n <= 0)
		{
			break;
		}
		printf("%c", first->n);
		first = first->next;
	}
	printf("\n");
}
