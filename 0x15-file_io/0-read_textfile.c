#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file print to STDOUT
 * @thefilename: text file being read
 * @theletters: number of letters to be read
 * Return: w- actual number of bytes read and printed
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *cat;
	ssize_t ab;
	ssize_t c;
	ssize_t d;

	ab = open(filename, O_RDONLY);
	if (ab == -1)
		return (0);
	cat = malloc(sizeof(char) * letters);
	d = read(ab, cat, letters);
	c = write(STDOUT_FILENO, cat, d);

	free(cat);
	close(ab);
	return (c);
}
