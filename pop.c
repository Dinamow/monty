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
