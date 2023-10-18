#include "montycal.h"

/**
 * no_op - Does no operation.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void no_op(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * swapping - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void swapping(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
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
 * addition - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void addition(stack_t **stack, unsigned int line_number)
{
	int add;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	errors(8, line_number, "add");

	(*stack) = (*stack)->next;
	add = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = add;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * subtract - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void subtract(stack_t **stack, unsigned int line_number)
{
	int add;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

	errors(8, line_number, "sub");

	(*stack) = (*stack)->next;
	add = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = add;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * divide - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void divide(stack_t **stack, unsigned int line_number)
{
	int add;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	errors(8, line_number, "div");

	if ((*stack)->n == 0)
	errors(9, line_number);
	(*stack) = (*stack)->next;
	add = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = add;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
