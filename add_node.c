#include "monty.h"

/**
* putnode - at the stack top add a node
* @head: The head node
* @n: value considered
*
* Return: null
*/

void putnode(stack_t **head, int n)
{
	stack_t *nnode, *jumper;

	jumper = *head;
	nnode = malloc(sizeof(stack_t));

	if (nnode == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (jumper)
		jumper->prev = nnode;

	nnode->n = n;
	nnode->next = *head;
	nnode->prev = NULL;
	*head = nnode;
}
