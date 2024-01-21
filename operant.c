#include "monty.h"

/**
 * do_add - add first 2 elements of the stack
 * @head: pointing to pointer of first node
 * @counter: variable that counts line
 *
 * Return: null
 */

void do_add(stack_t **head, unsigned int counter)
{
	stack_t *first;
	int size = 0, jump;

	first = *head;
	while (first)
	{
		first = first->next;
		size++;
	}
	if (size < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		freestack(*head);
		exit(EXIT_FAILURE);
	}
	first = *head;
	jump = first->n + first->next->n;
	first->next->n = jump;
	*head = first->next;
	free(first);
}

/**
 * do_sub - Function to subtract from stack 2 elements
 * @head: pointer that points to first node
 * @counter: variable that counts line
 *
 * Return: null
 */
void do_sub(stack_t **head, unsigned int counter)
{
	stack_t *jumper;
	int remove, num;

	jumper = *head;
	for (num = 0; jumper != NULL; num++)
		jumper = jumper->next;

	if (num < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		freestack(*head);
		exit(EXIT_FAILURE);
	}
	jumper = *head;
	remove = jumper->next->n - jumper->n;
	jumper->next->n = remove;
	*head = jumper->next;
	free(jumper);
}

/**
 * do_mul - Function to mul 2 stack elements
 * @head: pointer point to first node
 * @counter: variable that counts line
 *
 * Return: null
 */
void do_mul(stack_t **head, unsigned int counter)
{
	stack_t *first;
	int size = 0, jumper;

	first = *head;
	while (first)
	{
		first = first->next;
		size++;
	}
	if (size < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		freestack(*head);
		exit(EXIT_FAILURE);
	}
	first = *head;
	jumper = first->next->n * first->n;
	first->next->n = jumper;
	*head = first->next;
	free(first);
}

/**
 * do_div - Func to divide 2 stack element
 * @head: pointer pointing to first node
 * @counter: variable that counts line
 *
 * Return: null
 */
void do_div(stack_t **head, unsigned int counter)
{
	stack_t *first;
	int size = 0, jumper;

	first = *head;
	while (first)
	{
		first = first->next;
		size++;
	}
	if (size < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		freestack(*head);
		exit(EXIT_FAILURE);
	}
	first = *head;
	if (first->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		freestack(*head);
		exit(EXIT_FAILURE);
	}
	jumper = first->next->n / first->n;
	first->next->n = jumper;
	*head = first->next;
	free(first);
}

/**
 * do_mod - Func for 2 stack modulos element
 * @head: pointer pointing the first node
 * @counter: variable that counts line
 *
 * Return: null
 */
void do_mod(stack_t **head, unsigned int counter)
{
	stack_t *first;
	int size = 0, jumper;

	first = *head;
	while (first)
	{
		first = first->next;
		size++;
	}
	if (size < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		freestack(*head);
		exit(EXIT_FAILURE);
	}
	first = *head;
	if (first->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		freestack(*head);
		exit(EXIT_FAILURE);
	}
	jumper = first->next->n % first->n;
	first->next->n = jumper;
	*head = first->next;
	free(first);
}
