#include "montycal.h"

/**
 * _pushing_f - Pushes an integer onto the stack.
 * @head: Pointer to the stack's head
 * @count: Line number for error reporting
 *
 * Description:
 * This function pushes an integer onto the stack. It first checks if the
 * argument is a valid integer and handles error cases accordingly. It then
 * pushes the integer onto the stack as either a stack or a queue, based on
 * the current mode.
 *
 * Return: No return value
 */
void _pushing_f(stack_t **head, unsigned int count)
{
	int a, b = 0, flag = 0;

	if (bus.arg)
	{
	if (bus.arg[0] == '-')
	b++;
	for (; bus.arg[b] != '\0'; b++)
	{
	if (bus.arg[b] > '9' || bus.arg[b] < '0')
	flag = 1;
	}
	if (flag == 1)
	{
	fprintf(stderr, "L%d: Usage: Pushing integer\n", count);
	fclose(bus.file);
	free(bus.cont);
	freeing_stack(*head);
	exit(EXIT_FAILURE);
	}
	}
	else
	{
	fprintf(stderr, "L%d: Usage: Pushing integer\n", count);
	fclose(bus.file);
	free(bus.cont);
	freeing_stack(*head);
	exit(EXIT_FAILURE);
	}
	a = atoi(bus.arg);
	if (bus.lifi == 0)
	_adding_node(head, a);
	else
	_adding_queue(head, a);
}

/**
 * _printall_f - Prints all elements in the stack.
 * @head: Pointer to the stack's head
 * @count: Line number (unused)
 *
 * Description:
 * This function prints all the integer values stored in the stack, from top
 * to bottom. It iterates through the stack and prints each element on a new
 * line.
 *
 * Return: No return value
 */
void _printall_f(stack_t **head, unsigned int count)
{
	stack_t *h;
	(void)count;

	for (h = *head; h; h = h->next)
	{
	printf("%d\n", h->n);
	}
}

/**
 * _pinteger_f - Prints the integer at the top of the stack.
 * @head: Pointer to the stack's head
 * @count: Line number for error reporting
 *
 * Description:
 * This function prints the integer value at the top of the stack. It checks
 * for an empty stack and handles the error accordingly.
 *
 * Return: No return value
 */
void _pinteger_f(stack_t **head, unsigned int count)
{
	if (*head == NULL)
	{
	/* If the stack is empty, print an error message and clean up resources.*/
	fprintf(stderr, "L%u: Can't print integer, stack empty\n", count);

	fclose(bus.file); /* Close the Monty script file. */

	free(bus.cont); /* Free the line content. */

	freeing_stack(*head); /* Free the stack memory. */

	exit(EXIT_FAILURE);
	}

	/* Print the integer at the top of the stack. */
	printf("%d\n", (*head)->n);
}
