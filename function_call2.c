#include "monty.h"

/**
* call_pall - put or add all to stack
* @head: variable pointing to the pointer of first node
* @counter: variable that count line (ignore)
*
* Return: null
*/
void call_pall(stack_t **head, unsigned int counter)
{
	stack_t *first;
	(void)counter;

	first = *head;
	if (first == NULL)
		return;
	while (first)
	{
		printf("%d\n", first->n);
		first = first->next;
	}
}

/**
* call_swap - swapping two elements in stack
* @head: variable pointing to the pointer of first node
* @counter: variable that count line
*
* Return: null
*/
void call_swap(stack_t **head, unsigned int counter)
{
	stack_t *first;
	int len = 0, jumper;

	first = *head;
	while (first)
	{
		first = first->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		freestack(*head);
		exit(EXIT_FAILURE);
	}
	first = *head;
	jumper = first->n;
	first->n = first->next->n;
	first->next->n = jumper;
}
