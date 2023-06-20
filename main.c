#include "monty.h"
/**
 * main - start point
 * @argc: input
 * @argv: input
 * @env: input
 *
 * Return: int
 */
int main(int argc, char **argv)
{
	int fd, len;
	char *buff;
	FILE *f;
	
	printf("hello");
	if (argc != 2)
		write(STDERR_FILENO, "USAGE: monty file\n", 18), exit(EXIT_FAILURE);
	fd = open(argv[1], O_RDONLY);
	handle_err(fd, argv[1], 0);
	f = fopen(argv[1], "r");
	fseek(f, 0, SEEK_END);
	len = ftell(f);
	fclose(f);
	read(fd, buff, len);
	printf("%s\n", buff);
	return (0);
	
}

/**
 * handle_err - handle some errors
 * @fd: input
 * @a: input
 * @c: input
 *
 * Return: nothing
 */
void handle_err(int fd, char *a, int c)
{
	switch (c)
	{
		case 0:
		{
			if (fd < 0)
			{
				write(STDERR_FILENO, "Error: Can't open file", 22);
				write(STDERR_FILENO, a, (sizeof(a))); /*problem here with bytes num*/
				write(STDERR_FILENO, "\n", 1);
				exit(EXIT_FAILURE);
			}
			else
				return;
		}
		case 1:
			exit(EXIT_FAILURE);
		case 2:
			exit(EXIT_FAILURE);
		case 3:
			exit(EXIT_FAILURE);
		default:
			return;
	}
}

