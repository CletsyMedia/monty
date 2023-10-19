#include "monty.h"

/**
 * prnt_char - Prints the Ascii value.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void prnt_char(stack_t **stack, unsigned int line_number)
{
	int ansi;

	if (!stack || !*stack)

	strng_error(11, line_number);

	ansi = (*stack)->n;
	if (ansi < 0 || ansi > 127)

	strng_error(10, line_number);

	printf("%c\n", ansi);
}

/**
 * prnt_str - Prints a string.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void prnt_str(stack_t **stack, __attribute__((unused)) unsigned int ln)
{
	stack_t *temp;
	int ansi;

	if (!stack || !*stack)
	{
	printf("\n");
	return;
	}

	temp = *stack;
	while (temp != NULL)
	{
	ansi = temp->n;
	if (ansi <= 0 || ansi > 127)
	break;

	printf("%c", ansi);

	temp = temp->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void rotl(stack_t **stack, __attribute__((unused)) unsigned int ln)
{
	stack_t *temp;

	if (!stack || !*stack || !(*stack)->next)

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
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void rotr(stack_t **stack, __attribute__((unused)) unsigned int ln)
{
	stack_t *temp;

	if (!stack || !*stack || !(*stack)->next)

	return;

	temp = *stack;

	while (temp->next != NULL)
	temp = temp->next;

	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack)->prev = temp;
	(*stack) = temp;
}
