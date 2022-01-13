#include "header.h"
/**
 * add - adds the top two elements of the stack.
 *
 * @stack: pointer to the double linked list (stack)
 * @line_number: Line number of the monty file
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (line_number < 2)
	{
		fprintf(stderr, "L<%d>: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
}
/**
 * nop - doesn’t do anything.
 *
 * @stack: pointer to the double linked list (stack)
 * @line_number: Line number of the monty file
 */
void nop(_uu_ stack_t **stack, _uu_ unsigned int line_number)
{
}
/**
 * sub - subtracts the top element of the stack from the second
 * top element of the stack.
 *
 * @stack: pointer to the double linked list (stack)
 * @line_number: Line number of the monty file
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (line_number < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
}
/**
 * div_f - divides the second top element of the stack,
 * by the top element of the stack.
 *
 * @stack: pointer to the double linked list (stack)
 * @line_number: Line number of the monty file
 */
void div_f(stack_t **stack, unsigned int line_number)
{
	if (line_number < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n /= (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
}
/**
 * mul - multiplies the second top element of the stack with the
 * top element of the stack.
 *
 * @stack: pointer to the double linked list (stack)
 * @line_number: Line number of the monty file
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (line_number < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
}
