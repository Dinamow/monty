#include "monty.h"

void check_lines(char *lines)
{
	char *token, *test[] = {"push", "pop", "pall"}, *token_2;
	int line_number = 1, i, test_len = 3;
	char *saveptr1;

	token = strtok(lines, "\n");
	while (token != NULL)
	{
		token_2 = strtok_r(token, " ", &saveptr1);
		while (token_2 != NULL)
		{
			for (i = 0; i < test_len; i++)
			{
				if (!_strcp(test[i], token_2))
				{
					printf("%s\n", test[i]);
				}
			}
			token_2 = strtok_r(token, " ", &saveptr1);
		}
		token = strtok(NULL, "\n");
		line_number++;
	}
}

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
