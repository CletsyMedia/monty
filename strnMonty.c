#include "montycal.h"

/**
 * prnt_char - Prints the Ascii value.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void prnt_char(stack_t **stack, unsigned int line_number)
{
  int ansi;

  if (stack == NULL || *stack == NULL)
    strng_error(11, line_number);

  ansi = (*stack)->n;
  if (ansi < 0 || ansi > 127)
    strng_error(10, line_number);
  printf("%c\n", ansi);
}

/**
 * prnt_str - Prints a string.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void prnt_str(stack_t **stack, __attribute__((unused)) unsigned int ln)
{
  stack_t *temp;
  int ansi;

  if (stack == NULL || *stack == NULL)
  {
    printf("\n");
    return;
  }

  temp = *stack;
  while (temp != NULL)
  {
    ansi = temp->n;
    if (ansi <= 0 || ansi > 127)
      break;
    printf("%c", ansi);
    temp = temp->next;
  }
  printf("\n");
}
