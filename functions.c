#include "monty.h"
/**
 * read_file - Function that open and read the monty file
 *
 * @executable: name of the c program
 * @filename: name of the monty file
 * @cmd: struct that saves the pointers
 *
 * Return: Return a buffer with the text of the file
 */
char *read_file(char *executable, char *filename, stores *cmd)
{
	int fd = 0, rd = 0, i = 0;
	char buf[BUFSIZ] = "";

	fd = open(filename, O_RDWR);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", executable);
		close(fd);
		exit(EXIT_FAILURE);
	}
	rd = read(fd, buf, BUFSIZ);
	if (rd == -1)
	{
		fprintf(stderr, "Error: Can't read file %s\n", executable);
		close(fd);
		exit(EXIT_FAILURE);
	}
	cmd->buffer = malloc(sizeof(char) * (rd + 1)); /*error Malloc*/
	while (buf[i])
	{
		cmd->buffer[i] = buf[i];
		i++;
	}
	close(fd);
	return (cmd->buffer);
}
/**
 * text_tokenizator - Function that separate the text by "\n"
 *
 * @cmd: struct that save the tokens
 *
 * Return: End Program
 */
char **text_tokenizator(stores *cmd)
{
	int i = 0, j = 0, count = 0;
	char *ptr = NULL;

	while (*(cmd->buffer + i))
	{
		if (*(cmd->buffer + i) == '\n')
			count++;
		i++;
	}
	cmd->line_token = malloc(sizeof(char *) * (count + 1));
	if (cmd->line_token == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	while ((cmd->line_token[j] = strtok(cmd->buffer, "\n")) != NULL)
	{
		ptr = cmd->line_token[j];
		while (*ptr == 32 || *ptr == 9)
		{
			ptr++;
			if (*ptr == '\0')
			{
				j--;
				break;
			}
		}
		cmd->buffer = NULL;
		j++;
	}
	return (cmd->line_token);
}
/**
 * line_tokenizator - Function that separate the line tokens by espaces
 *
 * @cmd: struct that save the tokens
 * @stack: pointer to the double linked list
 *
 * Return: End Program
 */
int line_tokenizator(stores *cmd, stack_t *stack)
{
	int i = 0, n = 0, validator = 0;

	while (cmd->line_token[i] != NULL)
	{
		cmd->word_token = malloc(sizeof(char *) * 2);
		if (cmd->word_token == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		/* Bucle que separa las cada linea por espacios */
		while ((cmd->word_token[n] = strtok(cmd->line_token[i], " ")) != NULL)
		{
			cmd->line_token[i] = NULL;
			n++;
		}
		validator = match(cmd->word_token, i - 1, &stack);
		if (validator == -1)
		{
			return (i);
		}
		free(cmd->word_token);
		n = 0;
		i++;
	}
	dfree_list(&stack);
	return (0);
}
/**
 * match - Function that select the correct funtion to execute
 * for the n line of the monty file's text
 *
 * @word_token: Token of each text line
 * @line_number: Line number of the monty file
 * @stack: pointer to the double linked list (stack)
 *
 * Return: Return Error
 */
int match(char **word_token, int line_number, stack_t **stack)
{
	int pos = 0, result = 0;
	/*Array-List with the name of the OPCODES*/
	instruction_t flag[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div_f},
		{"mul", mul},
		{"mod", mod},
		{"#", hashtag},
		/*{"pchar", pchar},*/
		/*{"pstr", pstr},*/
		/*{"rotl", rotl},*/
		/*{"rotr", rotr},*/
		/*{"stack", stack},*/
		/*{"queue", queue},*/
	};
	while (flag[pos].opcode)
	{
		if (strcmp(word_token[0], flag[pos].opcode) == 0)
		{
			if (word_token[1] != NULL)
			{
				value = atoi(word_token[1]);
			}
			flag[pos].f(stack, line_number);
			return (result);
		}
		pos++;
	}
	return (-1);
}
