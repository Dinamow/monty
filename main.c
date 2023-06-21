#include "monty.h"

int main(int argc, char **argv) {
	char *buff;
	size_t size = 0;
	int file;
	struct stat st;

	if (argc != 2)
	{
		write(STDERR_FILENO, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	file = open(argv[1], O_RDONLY);
	handle_error_file(file, argv[1]);
	stat(argv[1], &st);
	buff = malloc(st.st_size);
	if (buff == NULL)
	{
		write(STDERR_FILENO, "Error: malloc failed\n", 21);
		exit(EXIT_FAILURE);
	}
	size = read(file, buff, st.st_size - 1);
	buff[size] = '\0';
	close(file);
	check_lines(buff);
	free(buff);
	return (0);
}
