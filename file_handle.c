#include "montycal.h"

/**
 * opening_file - opens a file
 * @file_name: the file namepath
 * Return: void
 */

void opening_file(char *file_name)
{
  FILE *fd = fopen(file_name, "r");

  if (file_name == NULL || fd == NULL)
    error(2, file_name);

  reading_file(fd);
  fclose(fd);
}

/**
 * reading_file - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void reading_file(FILE *fd)
{
  int format = 0;
  char *buffs = NULL;
  size_t length = 0;
  int line_num;

  for (line_num = 1; getline(&buffs, &length, fd) != -1; line_num++)
  {
    format = parsing_line(buffs, line_num, format);
  }
  free(buffs);
}

/**
 * parsing_line - Separates each line into tokens to determine
 * which function to call
 * @buffer: line from the file
 * @line_number: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int parsing_line(char *buffer, int line_number, int format)
{
	char *opcode;
  char *val;
	const char *delim = "\n ";

	if (buffer == NULL)
		error(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	val = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	finding_func(opcode, val, line_number, format);
	return (format);
}

