#include "main.h"

/**
 * create_file - creates a file.
 * @filename: file name
 * @text_content: is a NULL terminated string to write to the file
 * Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
	int file;
	int i, write_counter;

	if (filename == NULL)
		return (-1);

	file = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (file == -1)
		return (-1);
	if (text_content == NULL)
	{
		close(file);
		return (1);
	}
	for (i = 0; text_content[i]; i++)
		;
	write_counter = write(file, text_content, i);
	if (write_counter == -1)
	{
		close(file);
		return (-1);
	}
	close(file);
	return (1);
}
