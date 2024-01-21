#include "monty.h"

/**
 * queue_call - Function of first node of queue
 * @head: point to pointer of queue (unused)
 * @counter: variable that counts line (unused)
 *
 * Return: null
 */
void queue_call(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;

	bus.lifi = 1;
}

/**
 * tailqueue - add node to tail of queue
 * @n: variable value
 * @head: head of the queue
 *
 * Return: null
 */

void tailqueue(stack_t **head, int n)
{
	stack_t *nnode, *jumper;

	jumper = *head;
	nnode = malloc(sizeof(stack_t));

	if (nnode == NULL)
		printf("Error\n");

	nnode->n = n;
	nnode->next = NULL;

	if (jumper)
	{
		while (jumper->next)
			jumper = jumper->next;
	}
	if (!jumper)
	{
		*head = nnode;
		nnode->prev = NULL;
	}
	else
	{
		jumper->next = nnode;
		nnode->prev = jumper;
	}
}
