#include "montycal.h"

/**
 * opening_file - Open and process a file for reading.
 *
 * This function opens a file for reading, processes its contents, and provides
 * error handling for cases of an invalid file name or the inability to open
 * the file.
 *
 * @file_name: The name or path of the file to open.
 *
 * Return: void
 */
void opening_file(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	/* Check for invalid file name or inability to open the file. */
	if (file_name == NULL || fd == NULL)
		error(2, file_name);

	/* Read and process the contents of the opened file. */
	reading_file(fd);

	/* Close the opened file to release resources. */
	fclose(fd);
}

/**
 * reading_file - Read and process the contents of a file.
 *
 * This function reads the contents of a file line by line, processes each
 * line, and maintains the line number. It also manages memory allocation and
 * freeing for reading and processing each line.
 *
 * @fd: A pointer to the file descriptor.
 *
 * Return: void
 */
void reading_file(FILE *fd)
{
	int format = 0;
	char *buffs = NULL;
	size_t length = 0;
	int line_num;

	for (line_num = 1; getline(&buffs, &length, fd) != -1; line_num++)
	{		/* Process each line. */
	format = parsing_line(buffs, line_num, format);
	}

	free(buffs);	/* Free allocated memory. */
}

/**
 * parsing_line - Parse a line from the file and determine the operation.
 *
 * This function tokenizes a line from the file, extracts the opcode and value,
 * and determines the storage format (stack or queue). It also handles errors
 * for invalid input and invokes the appropriate function based on the opcode.
 *
 * @buffer: The line from the file to parse.
 * @line_number: The line number being processed.
 * @format: Storage format, 0 for stack, 1 for queue.
 *
 * Return: 0 if the opcode is 'stack', 1 if the opcode is 'queue', or the
 * current format if other opcodes are encountered.
 */
int parsing_line(char *buffer, int line_number, int format)
{
	char *val;
	const char *delim = "\n ";
	char *opcode;

	if (buffer == NULL)
	error(4);	/* Handle invalid input error. */

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
			/* No valid opcode, return current format. */
	return (format);

	val = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
	return (0);	/* Set format to stack. */

	if (strcmp(opcode, "queue") == 0)
	return (1);	/* Set format to queue. */
		 /* Call the appropriate function. */
	finding_func(opcode, val, line_number, format);

	return (format);	/* Return the current format. */
}

/**
 * finding_func - Find and execute the function corresponding to the opcode.
 *
 * This function searches for the appropriate function based on the provided
 * opcode, and then executes that function with the associated arguments.
 * It also handles comments and invokes an error function if an invalid
 * opcode is encountered.
 *
 * @opcode: The opcode to be processed.
 * @value: The argument associated with the opcode (if any).
 * @ln: The line number where the opcode is found.
 * @format: Storage format, 0 for stack, 1 for queue.
 *
 * Return: void
 */
void finding_func(char *opcode, char *value, int ln, int format)
{
	int a, flaging;

	instruction_t func_list[] = {
	{"push", adding_to_stack},
	{"pall", printing_stack},
	{"pint", prnt_top},
	{"pop", poping},
	{"nop", no_op},
	{"swap", swapping},
	{"add", addition},
	{"sub", subtract},
	{"div", divide},
	{"mul", multiply},
	{"mod", modulus},
	{"pchar", prnt_char},
	{"pstr", prnt_str},
	{"rotl", rotl},
	{"rotr", rotr},
	{NULL, NULL}
	};

	if (opcode[0] == '#')
	return;	/* Handle comments by ignoring the line. */

	for (flaging = 1, a = 0; func_list[a].opcode != NULL; a++)
	{
	if (strcmp(opcode, func_list[a].opcode) == 0)
	{		 /* Execute the function. */
	calling_func(func_list[a].f, opcode, value, ln, format);
	flaging = 0;
	}
	}

	if (flaging == 1)
	error(3, ln, opcode); /* Handle invalid opcode error. */
}

/**
 * calling_func - Call the required function with the provided arguments.
 *
 * This function is responsible for executing the specified function using
 * the appropriate arguments. It processes the 'push' opcode differently
 * to handle numeric values and provides error handling for invalid values.
 *
 * @func: Pointer to the function to be executed.
 * @op: String representing the opcode.
 * @val: String representing a numeric value (if applicable).
 * @ln: Line number where the instruction is found.
 * @format: Storage format, 0 for stack, 1 for queue.
 */
void calling_func(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flaging, a;

	flaging = 1;

	if (strcmp(op, "push") == 0)
	{
	if (val != NULL && val[0] == '-')
	{
	val = val + 1;
	flaging = -1;
	}

	if (val == NULL)
	error(5, ln);	/* Handle missing argument error. */

	for (a = 0; val[a] != '\0'; a++)
	{
	if (isdigit(val[a]) == 0)
	error(5, ln);	/* Handle invalid argument error. */
	}

	node = creating_node(atoi(val) * flaging);

	if (format == 0)
	func(&node, ln);
	if (format == 1)
	adding_to_queue(&node, ln);
	}
	else
	{
	func(&head, ln);/* Execute the function with the provided arguments. */
	}
}
