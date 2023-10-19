#include "montycal.h"
stack_t *head = NULL;

/**
 * main - Entry point for the Monty bytecode interpreter.
 *
 * This function serves as the entry point for the Monty bytecode interpreter.
 * It processes command-line arguments, checks for valid input, and executes
 * the bytecode contained in the specified file. If any errors occur during
 * this process, they are reported to the standard error stream.
 *
 * @argc: The number of command-line arguments.
 * @argv: An array of strings representing the command-line arguments.
 *
 * Return: Always returns 0 upon successful execution.
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/* Open and process the specified Monty bytecode file. */
	opening_file(argv[1]);

	/* Free any allocated memory before program termination. */
	freeing_nodes();

	return (0);
}

