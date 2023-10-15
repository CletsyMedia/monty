#ifndef _MONTYCAL_H
#define _MONTYCAL_H
#define _POSIX_C_SOURCE 200809L

#include <unistd.h>   /* Provides access to POSIX operating system APIs */
#include <stdlib.h>   /* Contains declarations for general-purpose functions */
#include <sys/types.h>/* Defines various data types */
#include <ctype.h>    /* Provides character classification functions */
#include <stdio.h>    /* Used for input and output operations */
#include <fcntl.h>    /* Provides file control options */
#include <string.h>   /* Declares functions for string manipulation */

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
 * struct bus_s - variables -args, file, line content
 * @lifi: flag change stack <-> queue
 * @cont: line content
 * @arg: value
 * @file: pointer to monty file
 * Description: carries values through the program
 */
typedef struct bus_s
{
  int lifi;
  char *cont;
  char *arg;
  FILE *file;
} bus_struct;

extern bus_struct bus;
/**
 * struct instructs_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instructs_s
{
  char *opcode;
  void (*f)(stack_t **stack, unsigned int line_num);
} instructs_t;

/* Monty Output Functions */
void _pchar_f(stack_t **head, unsigned int count);
void _pstring_f(stack_t **head, unsigned int count);
void _rotateT_f(stack_t **head, unsigned int count);
void _rotateB_f(stack_t **head, __attribute__((unused)) unsigned int count);

/* Monty Stack Operations */
void freeing_stack(stack_t *head);
void _poping_f(stack_t **head, unsigned int count);
void _swaping_f(stack_t **head, unsigned int count);
void _adding_f(stack_t **head, unsigned int count);
void no_ops(stack_t **head, unsigned int count);
void _subtract_f(stack_t **head, unsigned int count);
void _divide_f(stack_t **head, unsigned int count);
void _multiply_f(stack_t **head, unsigned int count);
void _modulus_f(stack_t **head, unsigned int count);

/* Monty Functions */
void _pushing_f(stack_t **head, unsigned int count);
void _printall_f(stack_t **, unsigned int count);
void _pinteger_f(stack_t **, unsigned int count);
int exec(char *cont, stack_t **stack, unsigned int count, FILE *file);

/* Monty Node and Queue Functions */
void _adding_node(stack_t **head, int n);
void _adding_queue(stack_t **head, int n);
void _queuing_f(stack_t **head, unsigned int count);
void _stacking_f(stack_t **head, unsigned int count);

/* Monty Operators */
char *mem_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char *clean_line(char *cont);

#endif /* _MONTYCAL_H */