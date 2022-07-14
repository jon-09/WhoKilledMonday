#include "monty.h"

/**
 * _pall - prints all the values on the stack
 * @stack: stack
 * @line_number: line number of monty file
 * Return: void
**/

void _pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	_palFromStart(stack);
}

/**
 * _palFromStart - display linked list from start
 * @stack: first node
 */
void _palFromStart(stack_t **stack)
{
	stack_t *tmp = *stack;

	if (tmp == NULL)
		return;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * _palFromEnd - display linked list from end
 * @stack: first node
 */
void _palFromEnd(stack_t **stack)
{
	stack_t *tmp = *stack, *prev;

	if (tmp == NULL)
		return;

	while (tmp != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
	}

	if (prev != NULL)
	{
		while (prev != NULL)
		{
			printf("%d\n", prev->n);
			prev = prev->prev;
		}
	}
}
