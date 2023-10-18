#include "montycal.h"

/**
 * adding_to_stack - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode.
 */
void adding_to_stack(stack_t **new_node, __attribute__((unused)) unsigned int ln)
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
  head = *new_node;
  head->next = temp;
  temp->prev = head;
}

/**
 * printing_stack - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: line number of  the opcode.
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
 * poping - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void poping(stack_t **stack, unsigned int line_number)
{
  stack_t *temp;

  if (stack == NULL || *stack == NULL)
    more_err(7, line_number);

  temp = *stack;
  *stack = temp->next;
  if (*stack != NULL)
    (*stack)->prev = NULL;
  free(temp);
}

/**
 * prnt_top - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void prnt_top(stack_t **stack, unsigned int line_number)
{
  if (stack == NULL || *stack == NULL)
    more_err(6, line_number);
  printf("%d\n", (*stack)->n);
}
