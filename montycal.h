#ifndef _MONTYCAL_H
#define _MONTYCAL_H

#define _POSIX_C_SOURCE 200809L

#include <unistd.h> /* Provides access to POSIX operating system APIs */
#include <stdlib.h> /* Contains declarations for general-purpose functions */
#include <ctype.h>  /* Provides character classification functions */
#include <stdio.h>  /* Used for input and output operations */
#include <string.h> /* Declares functions for string manipulation */
#include <stdarg.h>
#define _GNU_SOURCE

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO ALX	project
 */
typedef struct stack_s
{
  int n;
  struct stack_s *prev;
  struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
  char *opcode;
  void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);


/*Stack operations*/
stack_t *creating_node(int n);

void freeing_nodes(void);

void printing_stack(stack_t **, unsigned int);

void adding_to_stack(stack_t **, unsigned int);

void adding_to_queue(stack_t **, unsigned int);

void calling_func(op_func, char *, char *, int, int);

void prnt_top(stack_t **, unsigned int);

void poping(stack_t **, unsigned int);

void no_op(stack_t **, unsigned int);

void swapping(stack_t **, unsigned int);

/*String operations*/
void prnt_char(stack_t **, unsigned int);

void prnt_str(stack_t **, unsigned int);

void rotl(stack_t **, unsigned int);

/*Error hanlding*/
void error(int error_code, ...);

void errors(int error_code, ...);

void strng_error(int error_code, ...);

void rotr(stack_t **, unsigned int);


/*Math operations with nodes*/
void addition(stack_t **, unsigned int);
void subtract(stack_t **, unsigned int);
void divide(stack_t **, unsigned int);
void multiply(stack_t **, unsigned int);
void modulus(stack_t **, unsigned int);

/*file operations*/
void opening_file(char *file_name);
int parsing_line(char *buffer, int line_number, int format);
void reading_file(FILE *);
int length_chars(FILE *);
void finding_func(char *, char *, int, int);

#endif /* _MONTYCAL_H */