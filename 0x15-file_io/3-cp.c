#include "main.h"

char *create_buffer(char *file);
void close_file(int ab);

/**
 * create_buffer - Allocates 1024 bytes for a buffer.
 * @file: The name of the file buffer is storing chars for.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Cannot write upto %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - Closes file descriptors.
 * @ab: The file descriptor to be closed.
 */
void close_file(int ab)
{
	int x;

	x = close(ab);

	if (x == -1)
	{
		dprintf(STDERR_FILENO, "Error: Cannot close ab %d\n", ab);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 * If file_from does not exist or cannot be read - exit code 98.
 * If file_to cannot be created or written to - exit code 99.
 * If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int start, upto, y, c;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_start file_upto\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	start = open(argv[1], O_RDONLY);
	y = read(start, buffer, 1024);
	upto = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (start == -1 || y == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Cannot read start file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		c = write(upto, buffer, y);
		if (upto == -1 || c == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Cannot write upto %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		y = read(start, buffer, 1024);
		upto = open(argv[2], O_WRONLY | O_APPEND);

	} while (y > 0);

	free(buffer);
	close_file(start);
	close_file(upto);

	return (0);
}
