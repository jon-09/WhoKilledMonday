#include "monty.h"

/**
 * _add - adds the top two elem of the stack
 * @stack: stack
 * @line_number: line number of monty file
 * Return: void
**/

void _add(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *first = *stack, *next = NULL;
	int sum;

	if (*stack == NULL || _stackLen(*stack) <= 1)
		_errorHandler(ADD_STACK_TOO_SHORT);

	next = first->next;
	sum = first->n + next->n;
	_pop(stack, line_number);
	next->n = sum;
}

/**
 * _sub - sub the top two elem of the stack
 * @stack: stack
 * @line_number: line number of monty file
 * Return: void
**/

void _sub(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *first = *stack, *next;
	int sub;

	if (first == NULL || first->next == NULL)
		_errorHandler(SUB_STACK_TOO_SHORT);

	next = first->next;
	sub = next->n - first->n;
	next->n = sub;
	_pop(stack, line_number);
}
/**
 * _mul - adds the top two elem of the stack
 * @stack: stack
 * @line_number: line number of monty file
 * Return: void
**/

void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *first = *stack, *next;
	int mul;

	if (*stack == NULL || (*stack)->next == NULL)
		_errorHandler(MUL_STACK_TOO_SHORT);

	next = first->next;
	mul = first->n * next->n;
	_pop(stack, line_number);
	next->n = mul;
}
/**
 * _div - div the top two elem of the stack
 * @stack: stack
 * @line_number: line number of monty file
 * Return: void
**/

void _div(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *first = *stack, *next = NULL;
	int div;

	if (*stack == NULL || _stackLen(*stack) <= 1)
		_errorHandler(DIV_STACK_TOO_SHORT);

	next = first->next;

	if (first->n == 0)
		_errorHandler(NULLABLE_NUMBER);

	div = next->n / first->n;
	_pop(stack, line_number);
	next->n = div;
}

/**
 * _mod - modulo the top two elem of the stack
 * @stack: stack
 * @line_number: line number of monty file
 * Return: void
**/

void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *first = *stack, *next;
	int mod;

	if (*stack == NULL || _stackLen(*stack) <= 1)
		_errorHandler(MOD_STACK_TOO_SHORT);

	if (first->n == 0)
		_errorHandler(NULLABLE_NUMBER);

	next = first->next;
	mod = next->n % first->n;
	_pop(stack, line_number);
	next->n = mod;
}
