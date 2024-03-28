#include "main.h"
/**
  * create_file - the function creates a file
  * @filename: is the name of the file to create
  * @text_content: is a NULL terminated string to write to a file
  * Return: 1 on success, -1 on failure if file cannot be created or wtitten
  */
int create_file(const char *filename, char *text_content)
{
	int count;
	int fd;
	int wr;

	if (filename == NULL)
		return (-1);
	if (text_content == NULL)
	{
		fd = open(filename, O_WRONLY | O_CREAT, 0600);
		if (fd == -1)
			return (-1);
		return (1);
	}
	fd  = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);
	for (count = 0; text_content[count] != '\0'; count++)
	{}
	wr = write(fd, text_content, count);
	if (wr == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (1);
}
