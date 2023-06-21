#include "monty.h"

/**
 * push - push elements to the array
 * @stack: pointer to header
 * @line_number: the line number
 * Return: nothing
 */
void push(stack_t **stack, unsigned int line_number);
int push_num = 0;


/**
 * handle_push_number - hanlde the number that is pused
 * @line_number: the line number
 * @token_2: number to be checked
 * Return: nothing
 */
void handle_push_number(unsigned int line_number, char *token_2)
{
	int i = 0;

	if (token_2 == NULL)
	{
		printf("L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (i = 0; token_2[i] != '\0'; i++)
	{
		if (!isdigit(token_2[i]))
		{
			printf("L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	push_num = atoi(token_2);
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
	if (current == NULL)
	{
		new->n = push_num;
		*stack = new;
		return;
	}
	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	while (current->next != NULL)
	{
		current = current->next;
	}
	new->next = NULL;
	new->prev = current;
	new->n = push_num;
	current->next = new;
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

