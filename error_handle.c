#include "monty.h"

/**
 * error - Handle and display error messages based on specific error codes.
 *
 * This function receives an error code and, based on that code, generates
 * and prints the appropriate error message. The error codes are as follows:
 *
 * (1) => Indicates that the user provided either no file or more than one
 * file to the program.
 * (2) => Indicates that the provided file cannot be opened or read.
 * (3) => Indicates that the file contains an invalid instruction.
 * (4) => Indicates a failure when attempting to allocate memory.
 * (5) => Indicates an issue when the parameter passed to the "push"
 * instruction is not an integer.
 * (6) => Indicates an attempt to perform "pint" on an empty stack.
 * (7) => Indicates an attempt to perform "pop" on an empty stack.
 * (8) => Indicates an attempt to perform an operation on a stack that is
 * too short.
 *
 * @error_code: The specific error code to determine the error message.
 *
 * Return: This function does not return a value, as it exits the program
 * after displaying the error message.
 */
void error(int error_code, ...)
{
	va_list ag;
	char *op;
	int l_num;

	va_start(ag, error_code);
	switch (error_code)
	{
	case 1:
	fprintf(stderr, "USAGE: monty file\n");
	break;
	case 2:
	fprintf(stderr, "Error: Can't open file %s\n",
	va_arg(ag, char *));
	break;
	case 3:
	l_num = va_arg(ag, int);
	op = va_arg(ag, char *);
	fprintf(stderr, "L%d: unknown instruction %s\n", l_num, op);
	break;
	case 4:
	fprintf(stderr, "Error: malloc failed\n");
	break;
	case 5:
	fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
	break;
	default:
	break;
	}
	freeing_nodes();
	exit(EXIT_FAILURE);
}

/**
 * errors - Handle and display specific error messages based on error codes.
 *
 * This function is responsible for processing various error codes and
 * generating corresponding error messages. The error codes and their
 * respective meanings are:
 *
 * (6) => Indicates an attempt to execute "pint" on an empty stack.
 * (7) => Indicates an attempt to execute "pop" on an empty stack.
 * (8) => Indicates that the stack is too short to perform an operation.
 * (9) => Indicates a division by zero error.
 *
 * @error_code: The specific error code to determine the error message.
 *
 * Return: This function does not return a value; it exits the program after
 * displaying the relevant error message.
 */
void errors(int error_code, ...)
{
	va_list ag;
	char *op;
	int l_num;

	va_start(ag, error_code);
	switch (error_code)
	{
	case 6:
	fprintf(stderr, "L%d: can't pint, stack empty\n",
	va_arg(ag, int));
	break;
	case 7:
	fprintf(stderr, "L%d: can't pop an empty stack\n",
	va_arg(ag, int));
	break;
	case 8:
	l_num = va_arg(ag, unsigned int);
	op = va_arg(ag, char *);
	fprintf(stderr, "L%d: can't %s, stack too short\n", l_num, op);
	break;
	case 9:
	fprintf(stderr, "L%d: division by zero\n",
	va_arg(ag, unsigned int));
	break;
	default:
	break;
	}
	freeing_nodes();
	exit(EXIT_FAILURE);
}

/**
 * strng_error - Handle and display specific error msgbased on error codes.
 *
 * This function is responsible for processing various error codes and
 * generating corresponding error messages. The error codes and their
 * respective meanings are:
 *
 * (10) => Indicates that the number inside a node is outside the ASCII bounds.
 * (11) => Indicates an attempt to execute "pchar" on an empty stack.
 *
 * @error_code: The specific error code to determine the error message.
 *
 * Return: This function does not return a value; it exits the program after
 * displaying the relevant error message.
 */
void strng_error(int error_code, ...)
{
	va_list ag;
	int l_num;

	va_start(ag, error_code);
	l_num = va_arg(ag, int);
	switch (error_code)
	{
	case 10:
	fprintf(stderr, "L%d: can't pchar, value out of range\n", l_num);
	break;
	case 11:
	fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);
	break;
	default:
	break;
	}
	freeing_nodes();
	exit(EXIT_FAILURE);
}
