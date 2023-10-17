#include "montycal.h"

/**
 * _pchar_f - Prints the character at the top of the stack.
 * @head: Pointer to the stack's head
 * @count: Line number for error reporting
 *
 * Description:
 * This function interprets the top integer value on the stack as an ASCII
 * character and prints it. It checks for stack empty and character value
 * out of range errors and handles them accordingly.
 *
 * Return: No return value
 */
void _pchar_f(stack_t **head, unsigned int count)
{
	stack_t *h;

	h = *head;

	if (!h)
	{
	fprintf(stderr, "L%d: Error: Char stack is empty\n", count);
	fclose(bus.file);

	free(bus.cont);

	freeing_stack(*head);

	exit(EXIT_FAILURE);
	}

	if (h->n > 127 || h->n < 0)
	{
	fprintf(stderr, "L%d: Error: Char value is out of range\n", count);

	fclose(bus.file);

	free(bus.cont);

	freeing_stack(*head);

	exit(EXIT_FAILURE);
	}

	printf("%c\n", h->n);
}


