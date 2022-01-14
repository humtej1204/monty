#ifndef HEADER_FILE
#define HEADER_FILE

/********** Libraries **********/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
extern int value;
#define _uu_  __attribute__((unused))
/********** Structures **********/
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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

/**
 * struct Stores - tokens of the monty file text
 * @line_token: monty file's text sepatates in tokens by new lines
 * @word_token: line_tokens sepatates in tokens by spaces
 * @buffer: pointer that save monty file text
 *
 * Description: save the tokkens
 */
typedef struct Stores
{
	char *buffer;
	char **line_token;
	char **word_token;
} stores;

/********** Prototyopes **********/
/*Our Functions*/
char *read_file(char *executable, char *filename, stores *cmd);
char **text_tokenizator(stores *cmd);
int line_tokenizator(stores *cmd, stack_t *stack);
int match(char **word_token, int line_number, stack_t **stack);
char *_strtok(char *buff);
/*Opcode*/
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, _uu_ unsigned int line_number);
void pop(stack_t **stack, _uu_ unsigned int line_number);
void swap(stack_t **stack, _uu_ unsigned int line_number);
void print_dlistint(stack_t **h);
void add(stack_t **stack, unsigned int line_number);
void nop(_uu_ stack_t **stack, _uu_ unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void div_f(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void hashtag(stack_t **stack, unsigned int line_number);
/*FREE*/
void dfree_list(stack_t **head);
void _free(char **head);

#endif
