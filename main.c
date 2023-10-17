#include "montycal.h"

bus_struct bus = {0, NULL, NULL, NULL};

/**
 * main - monty code interpreter
 * @argc: number of arguments
 * @argv: monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *cont;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
	fprintf(stderr, "USAGE: A monty file\n");
	exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file; /*Correct usage of bus, which is declared in the header.*/
	if (!file)
	{
	fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
	exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
	cont = NULL;
	read_line = getline(&cont, &size, file);
	bus.cont = cont; /* Correct usage of bus, which is declared in the header.*/
	counter++;
	if (read_line > 0)
	{
	exec(cont, &stack, counter, file);
	}
	free(cont);
	}
	freeing_stack(stack);
	fclose(file);
	return (0);
}
