#include "montycal.h"

/**
 * creating_node - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
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
 * freeing_nodes - Frees nodes in the stack.
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
 * adding_to_queue - Adds a node to the queue.
 * @new_node: Pointer to the new node.
 * @ln: line number of the opcode.
 */
void adding_to_queue(stack_t **new_node,
__attribute__((unused)) unsigned int ln)
{
	stack_t *temp;

	if (new_node == NULL || *new_node == NULL)
	exit(EXIT_FAILURE);
	if (head == NULL)
	{
	head = *new_node;
	return;
	}
	temp = head;
	while (temp->next != NULL)
	temp = temp->next;

	temp->next = *new_node;
	(*new_node)->prev = temp;
}
