#include "monty.h"
/**
 * _div - start point
 * @stack: input
 * @line_number: input
 *
 * Return: nothing
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		_free_stack(stack);
		free(train.buff);
		fprintf(stderr, "L%u: can't sub, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		_free_stack(stack);
		free(train.buff);
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = (*stack)->n / temp;
}
/**
 * _mul - start point
 * @stack: input
 * @line_number: input
 *
 * Return: nothing
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		_free_stack(stack);
		free(train.buff);
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = (*stack)->n * temp;
}
/**
 * _mod - start point
 * @stack: input
 * @line_number: input
 *
 * Return: nothing
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		_free_stack(stack);
		free(train.buff);
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		_free_stack(stack);
		free(train.buff);
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = (*stack)->n % temp;
}

