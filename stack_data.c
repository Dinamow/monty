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
	int go = 0, i;

	if (token_2 == NULL)
	{
		go = 1;
	}
	else
	{
		for(i = 0; token_2[i] != '\0'; i++)
		{
			if(token_2[0] == '-' && isdigit(token_2[i + 1]))
				continue;
			if(!isdigit(token_2[i]))
			{
				go = 1;
				break;
			}
		}
	}
	if (go == 1)
	{
		_free_stack(head);
		free(train.buff);
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	go = 0;
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
	stack_t *new;

	(void) line_number;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = train.push_num;
	new->prev = NULL;

	if (*stack == NULL)
	{
		new->next = NULL;
		*stack = new;
	}
	else
	{
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
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


/**
 * pint - print all elements of a stack
 * @stack: pointer to head
 * @line_number: line's number
 * Return: nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (*stack == NULL)
	{
		_free_stack(stack);
		free(train.buff);
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", current->n);
}
