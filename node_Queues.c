#include "montycal.h"


/**
 * _adding_node - Adds a new node to the stack.
 * @head: Pointer to the stack's head
 * @n: Value to be stored in the new node
 *
 * Description:
 * This function creates a new node, initializes it with the given value, and
 * adds it to the top of the stack. If the allocation of memory for the new
 * node fails, it prints an error message and exits the program.
 * Returns: no return value
 */
void _adding_node(stack_t **head, int n)
{
	stack_t *newNode; /* Declare a pointer to the new node */
	stack_t *auxil;		/* Declare a pointer to the current top of the stack */
	/* Set auxil to point to the current top of the stack */
	auxil = *head;
	newNode = malloc(sizeof(stack_t)); /* Allocate memory for the new node */

	if (newNode == NULL) /* Check if memory allocation failed */
	{
		printf("Error: Can't malloc\n");
		exit(0);
	}

	if (auxil)							 /* Check if the stack is not empty */
		auxil->prev = newNode; /* Update the previous node's 'prev' pointer */

	newNode->n = n; /* Set the value of the new node to 'n' */
	/* Set the new node's 'next' to point to the current top */
	newNode->next = *head;
	newNode->prev = NULL; /* Set the new node's 'prev' to NULL */
	/* Update the head to point to the new node (new top) */
	*head = newNode;
}

/**
 * _queuing_f - Set the queue mode.
 * @head: Pointer to the stack's head
 * @count: Line number
 *
 * Description:
 * This function sets the queue mode, which changes the behavior of the push
 * operation to add elements to the back of the stack instead of the front.
 *
 * Return: No return value
 */
void _queuing_f(stack_t **head, unsigned int count)
{
	(void)head;
	(void)count;
	bus.lifi = 1;
}
/**
 * _adding_queue - Adds a new node to the end of the stack.
 * @head: Pointer to the stack's head
 * @n: Value to be stored in the new node
 *
 * Description:
 * This function creates a new node with the given value and adds it to the end
 * of the stack. If the allocation of memory for the new node fails, it prints
 * an error message.
 *
 * Return: No return value
 */
void _adding_queue(stack_t **head, int n)
{
	stack_t *newNode, *auxil;

	newNode = malloc(sizeof(stack_t));
	if (!newNode)
	{
	fprintf(stderr, "Error: Can't malloc\n");
	exit(EXIT_FAILURE);
	}
	newNode->n = n;
	newNode->next = NULL;

	if (!*head)
	{
	newNode->prev = NULL;
	*head = newNode;
	return;
	}

	auxil = *head;
	while (auxil->next)
	auxil = auxil->next;

	newNode->prev = auxil;
	auxil->next = newNode;
}


