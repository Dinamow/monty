#include "monty.h"
/**
 * pop - start point
 * @stack: input
 * @line_number: input
 *
 * Return: nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (*stack == NULL)
	{
		_free_stack(stack);
		free(train.buff);
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = current->next;
	free(current);
	current = *stack;
	if (current == NULL)
		return;
	current->prev = NULL;
}
/**
 * swap - start point
 * @stack: input
 * @line_number: input
 *
 * Return: nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *current = *stack;

	if (*stack == NULL || current->next == NULL)
	{
		_free_stack(stack);
		free(train.buff);
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	current = current->next;
	temp = current->n;
	current->n = (*stack)->n;
	(*stack)->n = temp;
}
/**
 * add - start point
 * @stack: input
 * @line_number: input
 *
 * Return: nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *current = *stack;

	if (*stack == NULL || current->next == NULL)
	{
		_free_stack(stack);
		free(train.buff);
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = current->n;
	pop(stack, line_number);
	(*stack)->n += temp;
}
/**
 * nop - nothing to do
 * @stack: input
 * @line_number: input
 *
 * Return: nothing
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) *stack;
}
/**
 * sub - start point
 * @stack: input
 * @line_number: number of lines
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		_free_stack(stack);
		free(train.buff);
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	pop(stack, line_number);
	(*stack)->n -= temp;
}
