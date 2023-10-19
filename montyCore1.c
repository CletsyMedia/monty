#include "monty.h"

/**
 * no_op - Perform no operation.
 *
 * This function does nothing and serves as a placeholder for the 'nop' opcode.
 *
 * @stack: Pointer to a pointer pointing to the top node of the stack (unused).
 * @line_number: Line number of the opcode (unused).
 */
void no_op(stack_t **stack, unsigned int line_number)
{
	(void)stack;

	(void)line_number;
}

/**
 * swapping - Swap the top two elements of the stack.
 *
 * This function swaps the top two elements of the stack, provided that the
 * stack is not empty and contains at least two elements.
 *
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Line number of the opcode.
 */
void swapping(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack || !(*stack)->next)
		errors(8, line_number, "swap");

	temp = (*stack)->next;

	(*stack)->next = temp->next;

	if (temp->next != NULL)
		temp->next->prev = *stack;

	temp->next = *stack;

	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}

/**
 * addition - Add the top two elements of the stack.
 *
 * This function adds the top two elements of the stack, provided that the
 * stack is not empty and contains at least two elements. The result is
 * stored in the new top element of the stack.
 *
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Line number of the opcode.
 */
void addition(stack_t **stack, unsigned int line_number)
{
	int add;

	if (!stack || !*stack || !(*stack)->next)

		errors(8, line_number, "add");

	(*stack) = (*stack)->next;

	add = (*stack)->n + (*stack)->prev->n;

	(*stack)->n = add;

	free((*stack)->prev);

	(*stack)->prev = NULL;
}

/**
 * subtract - Subtract the top two elements of the stack.
 *
 * This function subtracts the top two elements of the stack, provided that
 * the stack is not empty and contains at least two elements. The result is
 * stored in the new top element of the stack.
 *
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Line number of the opcode.
 */
void subtract(stack_t **stack, unsigned int line_number)
{
	int diff;

	if (!stack || !*stack || !(*stack)->next)

		errors(8, line_number, "sub");

	(*stack) = (*stack)->next;

	diff = (*stack)->n - (*stack)->prev->n;

	(*stack)->n = diff;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * divide - Divide the top two elements of the stack.
 *
 * This function divides the top two elements of the stack, provided that
 * the stack is not empty and contains at least two elements. The result is
 * stored in the new top element of the stack. It also checks for division by
 * zero.
 *
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Line number of the opcode.
 */
void divide(stack_t **stack, unsigned int line_number)
{
	int quotient;

	if (!stack || !*stack || !(*stack)->next)

		errors(8, line_number, "div");

	if ((*stack)->n == 0)
		errors(9, line_number);

	(*stack) = (*stack)->next;
	quotient = (*stack)->n / (*stack)->prev->n;

	(*stack)->n = quotient;

	free((*stack)->prev);
	(*stack)->prev = NULL;
}
