#include "monty.h"

/**
 * freestack - free the doubly linked list stack
 * @head: pointing to first stack node
 * Return: null
 */
void freestack(stack_t *head)
{
	stack_t *jump;

	jump = head;
	while (head)
	{
		jump = head->next;
		free(head);
		head = jump;
	}
}

/**
 * call_stack - free stack
 * @head: point to first node(unused)
 * @counter: variable counts line (unused)
 *
 * Return: null
*/
void call_stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;

	bus.lifi = 0;
}
