#include "monty.h"
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
