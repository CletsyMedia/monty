#include "montycal.h"

/**
 * creating_node - Create a new stack node.
 *
 * This function creates a new stack node with the specified number (n) and
 * initializes the node's next and previous pointers. If memory allocation
 * fails, it reports an error.
 *
 * @n: The integer value to store in the new node.
 * Return: A pointer to the newly created node, or NULL on failure.
 */
stack_t *creating_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	error(4);

	node->next = NULL;
	node->prev = NULL;
	node->n = n;

	return (node);
}

/**
 * freeing_nodes - Free nodes in the stack.
 *
 * This function frees all the nodes in the stack, starting from the head.
 * It iterates through the stack and releases each node's memory.
 */
void freeing_nodes(void)
{
	stack_t *temp;

	if (head == NULL)
	return;

	while (head != NULL)
	{
	temp = head;
	head = head->next;
	free(temp);
	}
}

/**
 * adding_to_queue - Add a node to the queue.
 *
 * This function adds a new node to the queue data structure. If the queue is
 * empty, the new node becomes the head of the queue. If the queue is not
 * empty, the new node is inserted at the end of the queue.
 *
 * @new_node: Pointer to the new node to be added.
 * @ln: Integer representing the line number of the opcode (unused here).
 */
void adding_to_queue(stack_t **new_node,
	__attribute__((unused)) unsigned int ln)
{
	stack_t *temp;

	if (new_node == NULL || *new_node == NULL)
	exit(EXIT_FAILURE);

	/* If the queue is empty, the new node becomes the head. */
	if (head == NULL)
	{
	head = *new_node;
	return;
	}

	/* Insert the new node at the end of the queue. */
	temp = head;
	while (temp->next != NULL)
	temp = temp->next;

	temp->next = *new_node;
	(*new_node)->prev = temp;
}
