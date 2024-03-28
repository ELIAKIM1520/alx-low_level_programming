#include "main.h"
/**
  * append_text_to_file - appends text at the end of the a file
  * @filename: is the name of the file
  * @text_content: is the NULL terminated string to add at the end of the file
  * Return: 1 (success), -1 (failure)
  * etx_content is NULL do nothing. Return 1 if file exists and -1 if fails
  */
int append_text_to_file(const char *filename, char *text_content)
{
	int count;
	int fd;
	int wr;

	if (filename == NULL)
		return (-1);
	if (text_content == NULL)
	{
		return (1);
	}
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);
	for (count = 0; text_content[count]; count++)
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
