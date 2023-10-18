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

#endif /* _MONTYCAL_H */