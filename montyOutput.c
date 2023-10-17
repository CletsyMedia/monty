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


/**
 * _pstring_f - Prints a string of characters from the stack.
 * @head: Pointer to the stack's head
 * @count: Line number (unused)
 *
 * Description:
 * This function interprets the integers on the stack as ASCII values and
 * prints characters until it encounters a 0 (null byte), a character value
 * out of range, or the stack becomes empty. It prints the characters in the
 * stack as a string.
 *
 * Return: No return value
 */
void _pstring_f(stack_t **head, unsigned int count)
{
	stack_t *h;
	(void)count;

	for (h = *head; h && (h->n != 0 && h->n <= 127 && h->n > 0); h = h->next)
	{
	printf("%c", h->n);
	}

	printf("\n");
}
