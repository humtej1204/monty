#include "monty.h"
/**
 * mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 *
 * @stack: pointer to the double linked list (stack)
 * @line_number: Line number of the monty file
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if (line_number < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
}
/**
 * hashtag - treat line with hashtag as a comment (don’t do anything).
 *
 * @stack: pointer to the double linked list (stack)
 * @line_number: Line number of the monty file
 */
void hashtag(_uu_ stack_t **stack, _uu_ unsigned int line_number)
{}

