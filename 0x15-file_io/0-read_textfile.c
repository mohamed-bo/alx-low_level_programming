#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output.
 * @filename: file name
 * @letters: is the number of letters it should read and print
 * Return: the actual number of letters it could read and print
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int file;
	ssize_t read_counter, write_counter;
	char *buffer;

	buffer = malloc(sizeof(char) * letters);
	if (!buffer || !filename)
	{
		free(buffer);
		return (0);
	}
	file = open(filename, O_RDONLY);
	if (file == -1)
	{
		free(buffer);
		return (0);
	}

	read_counter = read(file, buffer, letters);

	if (read_counter == -1)
	{
		free(buffer);
		close(file);
		return (0);
	}

	write_counter = write(STDOUT_FILENO, buffer, read_counter);

	if (write_counter == -1)
	{
		free(buffer);
		close(file);
		return (0);
	}
	free(buffer);
	close(file);
	return (write_counter);
}
