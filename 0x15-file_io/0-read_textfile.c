#include "main.h"

/**
 * read_textfile- Read text file print to STDOUT.
 * @filename: text file being read
 * @letters: number of letters to be read
 * Return: w- actual number of bytes read and printed
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t ab;
	ssize_t c;
	ssize_t d;

	ab = open(filename, O_RDONLY);
	if (ab == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	d = read(ab, buf, letters);
	c = write(STDOUT_FILENO, buf, d);

	free(buf);
	close(ab);
	return (c);
}
