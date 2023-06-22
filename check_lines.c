#include "monty.h"

/**
 * check_lines - check line by line to execute monty code
 * @lines: a string that cotaines all monty file's contante
 * Return: nothing
 */
void check_lines(char *lines)
{
	char *token, *token_2, *saveptr1, *temp;
	stack_t *head = NULL;
	unsigned int line_number = 1, i, arr_length = 5, no = 0;
	instruction_t arr[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop}, {"swap", swap}
	};

	token = strtok(lines, "\n");
	while (token != NULL)
	{
		token_2 = (char *)strtok_r(token, " ", &saveptr1);
		while (*token_2 == ' ' || *token_2 == 9)
			token_2++;
		for (i = 0; i < arr_length; i++)
		{
			if (!_strcp(arr[i].opcode, token_2))
			{
				temp = strtok_r(NULL, " ", &saveptr1);
				if (i == 0)
					handle_push_number(line_number, temp, &head);
				arr[i].f(&head, line_number);
				no = 1;
				break;
			}
		}
		if (check_spaces(token_2))
			no = 1;
		if (no == 0)
			handle_optcode(line_number, token_2, &head);
		no = 0;
		token = strtok(NULL, "\n");
		line_number++;
	}
	_free_stack(&head);
}

/**
 * _strcp - compare two strings
 * @a: first string
 * @b: second strign
 * Return: 0 in sucess and 1 on failuer
 */
int _strcp(char *a, char *b)
{
	int size_b, size = 0;

	while (*b == ' ' || *b == 9)
		b++;
	size_b = strlen(b);
	while (*a)
	{
		if (*a != *b)
			return (1);
		a++;
		b++;
		size++;
		if (size == size_b)
			return (0);
	}
	return (0);
}

/**
 * check_spaces - check if a string is only spaces
 * @a: string to be checked
 * Return: 0 on failer and 1 on success
 */
int check_spaces(char *a)
{
	while (*a == ' ')
		a++;
	if (*a == '\n' || *a == '\0')
		return (1);
	return (0);

}

