#include "monty.h"

/**
 * push - push elements to the array
 * @stack: pointer to header
 * @line_number: the line number
 * Return: nothing
 */
void push(stack_t **stack, unsigned int line_number);
int push_num = 0;


void hanlde_push_number(unsigned int line_number, char *token_2)
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

void push(stack_t **stack, unsigned int line_number)
{
	return;
}

void pall(stack_t **stack, unsigned int line_number)
{
	printf("%d\n", push_num);
}

