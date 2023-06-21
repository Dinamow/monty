#include "monty.h"

/**
 * _free_stack - frees the stack
 * @stack: stack's head
 * Return: nothing
 */
void _free_stack(stack_t **stack)
{
	stack_t *current = *stack, *temp;

	if (current == NULL)
		return;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}

/**
 * handle_error_file - handles error file
 * @fd: the opeand file
 * @a: agrv[1]
 * Return: nothing
 */
void handle_error_file(int fd, char *a)
{
	if (fd == -1)
	{
		write(STDERR_FILENO, "Error: Can't open file ", 23);
		write(STDERR_FILENO, a, (size_t) strlen(a));
		write(STDERR_FILENO, "\n", 1);
		exit(EXIT_FAILURE);
	}
}

/**
 * handle_optcode - handels optcode errors
 * @line_number: the number of the line
 * @instruct: the wrong instruct
 * @head: pointer to head
 * Return: nothing
 */
void handle_optcode(unsigned int line_number, char *instruct, stack_t **head)
{
	_free_stack(head);
	printf("L%u: unknown instruction %s\n", line_number, instruct);
	free(train.buff);
	exit(EXIT_FAILURE);
}

