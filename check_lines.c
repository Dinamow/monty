#include "monty.h"

/**
 * check_lines - check line by line to execute monty code
 * @lines: a string that cotaines all monty file's contante
 * Return: nothing
 */
void check_lines(char *lines)
{
	char *token, *token_2, *saveptr1;
	instruction_t arr[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add}, {"nop", nop}
	};
	unsigned int line_number = 1, i, arr_length = 2, no = 0;

	token = strtok(lines, "\n");
	while (token != NULL)
	{
		token_2 = (char *)strtok_r(token, " ", &saveptr1);
		while (token_2 != NULL)
		{
			for (i = 0; i < arr_length; i++)
			{
				if (!_strcp(arr[i].opcode, token_2))
				{
					printf("%s\n", arr[i].opcode);
					no == 1;
					break;
				}
				else if (check_spaces(token_2))
				{
					no == 1;
					break;
				}
			}
			if (no == 1)
			{
				no = 0;
				break;
			}
			token_2 = strtok_r(NULL, " ", &saveptr1);
		}
		token = strtok(NULL, "\n");
		line_number++;
	}
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

	while (*a == ' ')
		a++;
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

int check_spaces(char *a)
{
	while (*a == ' ')
		a++;
	if (*a == '\n' || *a == '\0')
		return (1);
	return (0);

}
