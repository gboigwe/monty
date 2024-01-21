#include "monty.h"

/**
 * do_push - This function will add node to stack
 * @head: variable that points to stack pointer
 * @counter: variable that counts line
 *
 * Return: null
 */
void do_push(stack_t **head, unsigned int counter)
{
	int index, moty = 0, note = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			moty++;
		for (; bus.arg[moty] != '\0'; moty++)
		{
			if (bus.arg[moty] > 57 || bus.arg[moty] < 48)
				note = 1; }
		if (note == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			freestack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		freestack(*head);
		exit(EXIT_FAILURE); }
	index = atoi(bus.arg);
	if (bus.lifi == 0)
		putnode(head, index);
	else
		tailqueue(head, index);
}
