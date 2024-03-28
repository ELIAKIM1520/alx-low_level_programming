#include "main.h"
#define BUFFER_SIZE 1024
/**
  * main - it should copy the content of one file to another
  * @argc: it it the argument count
  * @argv: it is the argumentt vector
  * Return: 0 (success)
  */
int main(int argc, char **argv)
{
	int fd_src, fd_dest, rd;
	int close_src, close_dest;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fd_src = open(argv[1], O_RDONLY);
	if (fd_src == -1)
	{
		dprintf(STDERR_FILENO, " Error: can't read from file %s\n", argv[1]);
		exit(98);
	}
	fd_dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	while ((rd = read(fd_src, buffer, BUFFER_SIZE)) > 0)
		if (fd_dest == -1 || (write(fd_dest, buffer, rd) != rd))
		{
			dprintf(STDERR_FILENO, "Error: can't write to %s\n", argv[2]);
			exit(99);
		}
	if (rd == -1)
	{
		dprintf(STDERR_FILENO, "Error: can't read from file %s\n", argv[1]);
		exit(98);
	}
	close_src = close(fd_src);
	close_dest = close(fd_dest);
	if (close_src == -1 || close_dest == -1)
	{
		if (close_src == -1)
			dprintf(STDERR_FILENO, "Error: can't close fd %d\n", fd_src);
		else if (close_dest == -1)
			dprintf(STDERR_FILENO, "Error: can't close fd %d\n", fd_dest);
		exit(100);
	}
	return (0);
}
