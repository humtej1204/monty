#include "monty.h"
/**
 * push - pushes an element to the stack.
 *
 * @stack: pointer to the double linked list (stack)
 * @line_number: Line number of the monty file
 */
void push(stack_t **stack, unsigned int line_number)
{
	/*insert_dnodeint_at_index(stack, line_number, value);*/
	stack_t *node = NULL;
	(void) line_number;
	if (stack == NULL)
		return;

	node = malloc(sizeof(stack_t)); /*error Malloc*/
	/**
	 * if n is not an integer or if there is no argument given to push
	 * print the error message
	 */

	if (!node)
	{
		fprintf(stderr, "Error: Can't malloc\n");
		return;
	}
	node->n = value;
	node->next = *stack;
	node->prev = NULL;
	if (*stack)
		(*stack)->prev = node;
	*stack = node;
}
/**
 * pall - Pprints all the values on the stack,
 * starting from the top of the stack.
 *
 * @stack: pointer to the double linked list (stack)
 * @line_number: Line number of the monty file
 */
void pall(stack_t **stack, _uu_ unsigned int line_number)
{
	/*If the stack is empty, don’t print anything*/
	if (stack == NULL)
	{
		return;
	}
	if (*stack)
	{
		printf("%d\n", (*stack)->n);
		pall(&((*stack)->next), line_number);
	}
}
/**
 * pint - prints the value at the top of the stack, followed by a new line.
 *
 * @stack: pointer to the double linked list (stack)
 * @line_number: Line number of the monty file
 */
void pint(stack_t **stack,  unsigned int line_number)
{
	/*If the stack is empty, print the error message*/
	if (stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	/*else*/
	printf("%d\n", (*stack)->n);
}
/**
 * pop - removes the top element of the stack.
 *
 * @stack: pointer to the double linked list (stack)
 * @line_number: Line number of the monty file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	/*If the stack is empty, print the error message*/
	if (stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	/*else*/
	if ((*stack)->next != NULL)
	{
		(*stack) = (*stack)->next;
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}
/**
 * swap - swaps the top two elements of the stack.
 *
 * @stack: pointer to the double linked list (stack)
 * @line_number: Line number of the monty file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *new_st = *stack, *new_nd = *stack, *temp = *stack;

	/*If the stack is empty, print the error message*/
	if (stack == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	/*else*/
	if ((*stack)->next != NULL)
	{
		if ((*stack)->next->next != NULL)
		{
			temp = temp->next->next;
			new_st = new_st->next;
			new_nd->next = temp;
			new_nd->prev = new_st;
			new_st->next = new_nd;
			new_st->prev = NULL;
			(*stack) = new_st;
		}
		else
		{
			new_st = new_st->next;
			new_nd->next = NULL;
			new_nd->prev = new_st;
			new_st->next = new_nd;
			new_st->prev = NULL;
			(*stack) = new_st;
		}
	}
}
