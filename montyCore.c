#include "monty.h"

/**
 * adding_to_stack - Add a node to the stack.
 *
 * This function adds a new node to the stack data structure. If the stack
 * is empty, the new node becomes the head of the stack. If the stack is not
 * empty, the new node is inserted as the new head of the stack, and the
 * previous head is connected as the next element.
 *
 * @new_node: Pointer to the new node to be added.
 * @ln: Integer representing the line number of the opcode (unused here).
 */
void adding_to_stack(stack_t **new_node,
										 __attribute__((unused)) unsigned int ln)
{
	stack_t *temp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);

	/* If the stack is empty, the new node becomes the head. */
	if (head == NULL)
	{
		head = *new_node;

		return;
	}

	/* If the stack is not empty, insert the new node as the new head. */
	temp = head;

	head = *new_node;

	head->next = temp;

	temp->prev = head;
}

/**
 * printing_stack - Print the elements of the stack.
 *
 * This function prints the elements of the stack, starting from the top
 * (head). It goes through the stack and prints each element.
 *
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Line number of the opcode.
 */
void printing_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;

	if (stack == NULL)

		exit(EXIT_FAILURE);

	temp = *stack;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);

		temp = temp->next;
	}
}

/**
 * poping - Remove the top node from the stack.
 *
 * This function removes the top node from the stack and frees the memory
 * associated with it. The next node in the stack becomes the new top.
 *
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Line number of the opcode.
 */
void poping(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack)

		errors(7, line_number);

	temp = *stack;

	*stack = temp->next;

	if (*stack != NULL)

		(*stack)->prev = NULL;

	free(temp);
}

/**
 * prnt_top - Print the top node of the stack.
 *
 * This function prints the value of the top node in the stack to the
 * standard output.
 *
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Line number of the opcode.
 */
void prnt_top(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)

		errors(6, line_number);

	printf("%d\n", (*stack)->n);
}
