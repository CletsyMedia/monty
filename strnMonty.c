#include "monty.h"

/**
 * prnt_char - Prints the ASCII character from the stack.
 *
 * @stack: Pointer to the top node of the stack.
 * @line_number: Line number of the opcode.
 *
 * Description:
 * This function prints the ASCII character at the top of the stack and handles
 * error cases for empty stack or invalid ASCII values.
 */
void prnt_char(stack_t **stack, unsigned int line_number)
{
	int ansi;

	if (!stack || !(*stack))
	{
		strng_error(11, line_number);
		return;
	}

	ansi = (*stack)->n;
	if (ansi < 0 || ansi > 127)
	{
		strng_error(10, line_number);
		return;
	}

	printf("%c\n", ansi);
}

/**
 * prnt_str - Prints a string of ASCII characters from the stack.
 *
 * @stack: Pointer to the top node of the stack.
 * @ln: Line number (unused).
 */
void prnt_str(stack_t **stack, __attribute__((unused)) unsigned int ln)
{
	stack_t *temp;
	int ansi;

	if (!stack || !(*stack))
	{
		printf("\n");
		return;
	}

	temp = *stack;
	while (temp)
	{
		ansi = temp->n;
		if (ansi <= 0 || ansi > 127)
			break;

		putchar(ansi);
		temp = temp->next;
	}

	printf("\n");
}

/**
 * rotl - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @ln: Line number (unused).
 */
void rotl(stack_t **stack, __attribute__((unused)) unsigned int ln)
{
	stack_t *temp;

	if (!stack || !(*stack) || !(*stack)->next)
		return;

	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * rotr - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @ln: Line number (unused).
 */
void rotr(stack_t **stack, __attribute__((unused)) unsigned int ln)
{
	stack_t *temp = *stack;

	if (!stack || !(*stack) || !(*stack)->next)
		return;

	while (temp->next != NULL)
		temp = temp->next;

	temp->prev->next = NULL;
	temp->prev = NULL;

	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = temp;
}
