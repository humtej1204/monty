#include "header.h"
int value = 0;
/**
 * main - Main function
 *
 * @argc: number of arguments
 * @argv: contend of the arguments
 *
 * Return: End program
 */
int main(int argc, char *argv[])
{
	stores cmd;
	stack_t *stack = NULL;
	char *ptr = NULL, **ptr2;
	/* Verify the number of arguments passed to the program */

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/* Verify if the text can be readed and returned a buffer with the text*/
	ptr = read_file(argv[0], argv[1], &cmd);
	ptr2 = text_tokenizator(&cmd);

	/* Separate line's text in words */
	value = line_tokenizator(&cmd, stack);
	if (value != 0)
	{
		fprintf(stderr, "L<%d>: unknown instruction <opcode>\n", value);
		exit(EXIT_FAILURE);
	}
	free(ptr);
	free(ptr2);

	return (0);
}

/**
 * dfree_list - clean the double linked list
 *
 * @head: pointer to the linked list
 */
void dfree_list(stack_t **head)
{
	if (head == NULL)
		return;

	if (*head)
	{
		dfree_list(&((*head)->next));
		free(*head);
	}
}
