#include "monty.h"

/**
 * rot_fst- Rotate the stack element to top
 * @head: pointer pointing to node
 * @counter: variable that counts line
 *
 * Return: null
 */
void rot_fst(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	stack_t *jup = *head, *aux;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	aux = (*head)->next;
	aux->prev = NULL;
	while (jup->next != NULL)
	{
		jup = jup->next;
	}
	jup->next = *head;
	(*head)->next = NULL;
	(*head)->prev = jup;
	(*head) = aux;
}

/**
 * rot_lst - Rotate stack element to bottom
 * @head: Pointing to pointer of first node
 * @counter: variable that counts line
 *
 * Return: null
 */
void rot_lst(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *dupp;

	dupp = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (dupp->next)
	{
		dupp = dupp->next;
	}
	dupp->next = *head;
	dupp->prev->next = NULL;
	dupp->prev = NULL;
	(*head)->prev = dupp;
	(*head) = dupp;
}
