#include "main.h"

/**
 * append_text_to_file - creates a file.
 * @filename: file name
 * @text_content: is the NULL terminated string to add at the end of the file
 * Return: 1 on success and -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int file;
	int i, write_counter;

	if (filename == NULL)
		return (-1);

	file = open(filename, O_WRONLY | O_APPEND);
	if (file == -1)
		return (-1);

	if (text_content)
	{
		for (i = 0; text_content[i]; i++)
			;

		write_counter = write(file, text_content, i);
		if (write_counter == -1)
		{
			close(file);
			return (-1);
		}
	}
	close(file);
	return (1);
}

