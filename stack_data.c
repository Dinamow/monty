#include "monty.h"

/**
 * handle_push_number - hanlde the number that is pused
 * @line_number: the line number
 * @token_2: number to be checked
 * @head: header to be freed
 * Return: nothing
 */
void handle_push_number(unsigned int line_number, char *token_2,
		stack_t **head)
{
	int i = 0;

	if (token_2 == NULL)
	{
		_free_stack(head);
		free(train.buff);
		printf("L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (i = 0; token_2[i] != '\0'; i++)
	{
		if (!isdigit(token_2[i]))
		{
			_free_stack(head);
			free(train.buff);
			printf("L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	train.push_num = atoi(token_2);
}

/**
 * push - push elements to the array
 * @stack: pointer to header
 * @line_number: the line number
 * Return: nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *current = *stack;

	(void) line_number;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		if (current != NULL)
		{
			while (current->next != NULL)
				current = current->next;
			current->next = new;
		}
		else
		{
			*stack = new;
		}
		new->n = train.push_num;
		new->prev = current;
		new->next = NULL;
	}
}

/**
 * pall - print all elements of a stack
 * @stack: pointer to head
 * @line_number: line's number
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void) line_number;
	if (*stack == NULL)
		return;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

