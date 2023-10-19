#include "monty.h"

/**
 * multiply - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void multiply(stack_t **stack, unsigned int line_number)
{
	int prod;

	if (!stack || !*stack || !(*stack)->next)
	errors(8, line_number, "mul");

	(*stack) = (*stack)->next;

	prod = (*stack)->n * (*stack)->prev->n;

	(*stack)->n = prod;

	free((*stack)->prev);

	(*stack)->prev = NULL;
}

/**
 * modulus - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void modulus(stack_t **stack, unsigned int line_number)
{
	int remainder;

	if (!stack || !*stack || !(*stack)->next)

	errors(8, line_number, "mod");

	if ((*stack)->n == 0)

	errors(9, line_number);

	(*stack) = (*stack)->next;

	remainder = (*stack)->n % (*stack)->prev->n;

	(*stack)->n = remainder;

	free((*stack)->prev);

	(*stack)->prev = NULL;
}
