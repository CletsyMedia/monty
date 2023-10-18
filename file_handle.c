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
		err(2, file_name);

	read_file(fd);
	fclose(fd);
}
