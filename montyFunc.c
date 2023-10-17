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

/**
 * exec - Execute a Monty bytecode instruction.
 * @cont: The instruction to be executed
 * @stack: Pointer to the stack
 * @count: Line number for error reporting
 * @file: Pointer to the Monty file
 *
 * Description:
 * This function executes a Monty bytecode instruction. It parses the input
 * instruction, checks for known opcodes, and performs the corresponding
 * operation on the stack. If an unknown instruction is encountered, it prints
 * an error message and exits the program.
 *
 * Return: 0 on success, 1 on failure
 */
int exec(char *cont, stack_t **stack, unsigned int count, FILE *file)
{
	instructs_t opst[] = {
			{"push", _pushing_f}, {"pall", _printall_f}, {"pint", _pinteger_f}, {"pop", _poping_f}, {"swap", _swaping_f}, {"add", _adding_f}, {"nop", no_ops}, {"sub", _subtract_f}, {"div", _divide_f}, {"mul", _multiply_f}, {"mod", _modulus_f}, {"pchar", _pchar_f}, {"pstr", _pstring_f}, {"rotl", _rotateT_f}, {"rotr", _rotateB_f}, {"queue", _queuing_f}, {"stack", _stacking_f}, {NULL, NULL}};

	char *operand;
	unsigned int a = 0;

	operand = strtok(cont, " \n\t");
	if (operand && operand[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");

	while (opst[a].opcode && operand)
	{
		if (strcmp(operand, opst[a].opcode) == 0)
		{
			opst[a].f(stack, count);
			return (0);
		}
		a++;
	}

	if (operand && opst[a].opcode == NULL)
	{
		fprintf(stderr, "L%d: Unknown instruction %s\n", count, operand);
		fclose(file);
		free(cont);
		freeing_stack(*stack);
		exit(EXIT_FAILURE);
	}

	return (1);
}

/**
 * _rotateT_f - Rotate the stack to the top.
 * @head: Pointer to the stack's head
 * @count: Line number (unused)
 *
 * Description:
 * This function rotates the stack to the top, moving the bottom element
 * to the top of the stack.
 *
 * Return: No return value
 */
void _rotateT_f(stack_t **head, __attribute__((unused)) unsigned int count)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	stack_t *cpy = *head;

	while (cpy->next)
	{
		cpy = cpy->next;
	}

	cpy->next = *head;
	cpy->prev->next = NULL;
	cpy->prev = NULL;
	(*head)->prev = cpy;
	(*head) = cpy;
}
