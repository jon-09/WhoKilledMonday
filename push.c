#include "monty.h"

/**
 * _push - push an element to the stack
 * @stack: stack
 * @line_number: line number of monty file
 * Return: void
**/

void _push(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	switch (appData->way)
	{
		case FIFO:
			_pushToEnd(stack);
			break;
		case LIFO:
		default:
			_pushToStart(stack);
			break;
	}
}
/**
 * _pushToStart - push new stack at start of the stack
 * @stack: head of the stack
 */
void _pushToStart(stack_t **stack)
{
	stack_t *new;
	stack_t *tmp;

	new = NULL;
	tmp = *stack;

	_checkArguments();

	new = _createStack(_atoi(appData->arguments[1]));

	if (new == NULL)
		_errorHandler(MALLOC_FAILED);

	if (*stack == NULL)
	{
		*stack = new;
	}
	else
	{
		new->next = tmp;
		tmp->prev = new;
		*stack = new;
	}
}

/**
 * _pushToEnd - push new stack at end of the stack
 * @stack: head of the stack
 */
void _pushToEnd(stack_t **stack)
{
	stack_t *new;
	stack_t *tmp;

	new = NULL;
	tmp = *stack;

	_checkArguments();

	new = _createStack(_atoi(appData->arguments[1]));

	if (new == NULL)
		_errorHandler(MALLOC_FAILED);

	if (*stack == NULL)
	{
		new->prev = NULL;
		*stack = new;
	}
	else
	{
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		new->prev = tmp;
		tmp->next = new;
	}
}
