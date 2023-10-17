#include "montycal.h"

/**
 * freeing_stack - Frees a doubly linked list.
 * @head: Pointer to the head of the list
 *
 * Description:
 * This function frees all the nodes in a doubly linked list.
 *
 * Return: No return value
 */
void freeing_stack(stack_t *head)
{
	stack_t *auxil;

	for (auxil = head; head; auxil = head)
	{
	/* Store the next node's address before freeing the current node */
	head = head->next;
	free(auxil); /* Free the current node */
	}
}

/**
 * _poping_f - Removes the top element from the stack.
 * @head: Pointer to the stack's head
 * @count: Line number for error reporting
 *
 * Description:
 * This function removes the top element from the stack and frees its memory.
 * It checks for an empty stack and handles the error accordingly.
 *
 * Return: No return value
 */
void _poping_f(stack_t **head, unsigned int count)
{
	stack_t *h;

	if (*head == NULL)
	{
	/* If the stack is empty, print an error message and clean up resources.*/
	fprintf(stderr, "L%d: Error: Can't pop an empty stack\n", count);

	fclose(bus.file); /* Close the Monty script file. */

	free(bus.cont); /* Free the line content. */

	freeing_stack(*head); /* Free the stack memory. */

	exit(EXIT_FAILURE);
	}

	h = *head;
	*head = h->next;

	free(h);
}

/**
 * _swaping_f - Swaps the top two elements of the stack.
 * @head: Pointer to the stack's head
 * @count: Line number
 *
 * Description:
 * This function swaps the values of the top two elements of the stack.
 * If the stack contains less than two elements, it prints an error message
 *	and exits the program.
 *
 * Return: No return value
 */
void _swaping_f(stack_t **head, unsigned int count)
{
	stack_t *h;
	int length = 0;
	int auxil;

	h = *head;
	while (h)
	{
	h = h->next;
	length++;
	}
	if (length < 2)
	{
	fprintf(stderr, "L%d: Error: Can't swap stack, stack too short\n", count);

	fclose(bus.file);

	free(bus.cont);

	freeing_stack(*head);

	exit(EXIT_FAILURE);
	}
	h = *head;
	auxil = h->n;
	h->n = h->next->n;
	h->next->n = auxil;
}

/**
 * _adding_f - Adds the top two elements of the stack.
 * @head: Pointer to the stack's head
 * @count: Line number for error reporting
 *
 * Description:
 * This function calculates the sum of the two top elements of the stack and
 * updates the stack accordingly. It checks if there are at least two
 * elements in the stack to perform the addition operation. If not, it prints
 * an error message and exits.
 */
void _adding_f(stack_t **head, unsigned int count)
{
	stack_t *h;
	int length = 0;
	int auxil;

	h = *head;

	/* Calculate the length of the stack */
	for (; h; h = h->next)
	{
	length++;
	}

	/* Check if there are at least two elements in the stack */
	if (length < 2)
	{
	fprintf(stderr, "L%d: it can't add, stack is too short\n", count);

	fclose(bus.file);

	free(bus.cont);

	freeing_stack(*head);

	exit(EXIT_FAILURE);
	}

	/* Perform the addition operation */
	h = *head;
	auxil = h->n + h->next->n;
	h->next->n = auxil;
	*head = h->next;
	free(h);
}

/**
 * no_ops - No-operation (NOP) function for Monty bytecode.
 * @head: Pointer to the stack's head
 * @count: Line number for error reporting
 *
 * Description:
 * The no_ops function does nothing and serves as a no-operation (NOP) for
 * Monty bytecode. It's used for maintaining consistency when processing
 * Monty commands that don't perform any specific operation on the stack.
 *
 * Return: No return value
 */
void no_ops(stack_t **head, unsigned int count)
{
	(void)count;
	(void)head;
}
