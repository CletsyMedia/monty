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
