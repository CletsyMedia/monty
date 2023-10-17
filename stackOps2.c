#include "montycal.h"

/**
 * _subtract_f - Subtracts the top element from the 2nd top elm of the stack.
 * @head: Pointer to the stack's head
 * @count: Line number
 *
 * Description:
 * This function subtracts the top element from the second top element of the
 * stack, and the result is stored in the second top element. If the stack does
 * not contain at least two elements, it prints an error message and exits the
 * program.
 *
 * Return: No return value
 */
void _subtract_f(stack_t **head, unsigned int count)
{
	stack_t *auxil;
	int sub;
	int nodes;

	auxil = *head;

	for (nodes = 0; auxil != NULL; nodes++)
	auxil = auxil->next;

	if (nodes < 2)
	{
	fprintf(stderr, "L%d: Error: Can't subtract, stack too short\n", count);

	fclose(bus.file);

	free(bus.cont);

	freeing_stack(*head);

	exit(EXIT_FAILURE);
	}

	auxil = *head;
	sub = auxil->next->n - auxil->n;
	auxil->next->n = sub;
	*head = auxil->next;
	free(auxil);
}


/**
 * _divide_f - Divides the second element by the top element of the stack.
 * @head: Pointer to the stack's head
 * @count: Line number for error reporting
 *
 * Description:
 * This function calculates the result of dividing the second element of the
 * stack by the top element and updates the stack accordingly. It checks if
 * there are at least two elements in the stack and whether the top element
 * is not zero to perform the division operation. If not, it prints an error
 * message and exits.
 *
 * Return: no return
 *
 */
void _divide_f(stack_t **head, unsigned int count)
{
	stack_t *h;	/* Declare a pointer to traverse the stack */
	int length = 0; /* Initialize a variable to keep track of stack length */
	int auxil;	/* Initialize a variable for the division result */

	h = *head; /* Set h to point to the current top of the stack */

	while (h)
	{
	h = h->next; /* Traverse the stack to calculate its length */
	length++;
	}

	if (length < 2) /* Check if there are at least two elements in the stack */
	{
	fprintf(stderr, "L%d: Error: Not enough operands to divide\n", count);
	fclose(bus.file);
	free(bus.cont);
	freeing_stack(*head);
	exit(EXIT_FAILURE);
	}

	h = *head; /* Reset h to point to the current top of the stack */

	if (h->n == 0) /* Check if the top element is zero */
	{
	fprintf(stderr, "L%d: Error: Division by zero is not allowed\n", count);
	fclose(bus.file);
	free(bus.cont);
	freeing_stack(*head);
	exit(EXIT_FAILURE);
	}

	auxil = h->next->n / h->n; /* Calculate the division result */
	h->next->n = auxil;	/* Update the second element with the result */
	*head = h->next;	/* Update the head to point to the new top */
	free(h);	/* Free the previous top node */
}

/**
 * _modulus_f - Computes the modulus of the top two elements of the stack.
 * @head: Pointer to the stack's head
 * @count: Line number for error reporting
 *
 * Description:
 * This function calculates the modulus of the top two elements of the stack.
 * If the stack is too short or if division by zero is attempted, it prints an
 * error message and exits the program.
 *
 * Return: No return value
 */
void _modulus_f(stack_t **head, unsigned int count)
{
	int length = 0;
	stack_t *h;

	for (h = *head; h; h = h->next)
	{
	length++;
	}

	if (length < 2)
	{
	fprintf(stderr, "L%d: Error: Stack too short for mod operation\n", count);
	fclose(bus.file);
	free(bus.cont);
	freeing_stack(*head);
	exit(EXIT_FAILURE);
	}

	h = *head;

	if (h->n == 0)
	{
	fprintf(stderr, "L%d: Error: Division by zero is not allowed\n", count);
	fclose(bus.file);
	free(bus.cont);
	freeing_stack(*head);
	exit(EXIT_FAILURE);
	}

	int auxil = h->next->n % h->n;

	h->next->n = auxil;
	*head = h->next;
	free(h);
}

/**
 * _multiply_f - Multiplies the top two elements of the stack.
 * @head: Pointer to the stack's head
 * @count: Line number for error reporting
 *
 * Description:
 * This function multiplies the top two elements of the stack. If the stack is
 * too short, it prints an error message and exits the program.
 *
 * Return: No return value
 */
void _multiply_f(stack_t **head, unsigned int count)
{
	stack_t *h;
	int length = 0;

	for (h = *head; h; h = h->next)
	{
	length++;
	}

	if (length < 2)
	{
	fprintf(stderr, "L%d: Error: Stack too short for multiplication\n", count);

	fclose(bus.file);

	free(bus.cont);

	freeing_stack(*head);
	exit(EXIT_FAILURE);
	}

	h = *head;
	int auxil = h->next->n * h->n;

	h->next->n = auxil;
	*head = h->next;
	free(h);
}

