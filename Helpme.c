#include "shell.h"

/**
 * _write: prints to either in out or err
 *
 * @str: the string to be printed
 * @stm: where to print to (in out or err)
 *
 * Return: nothing
 */
void _write(char *str, int stm)
{
	int index;

	for (index = 0; str[index]; index++)
	{
		write(stm, &str[index], 1);
	}
}

/**
 * tokenizer - helps to tokenize a string
 *
 * @cmd: the command to tokenize
 * @delim: the delimeter used to tikenize
 *
 * Returns: an array of strings of the command tokens
 */

char **tokenizer(char *cmd, char *delim)
{
	char *token = NULL, *tmp_cmd = NULL;
	int i = 0, num_toks = 0;
	char **cmd_toks = NULL;

	tmp_cmd = strdup(cmd);

	token = strtok(tmp_cmd, delim);

	while (token)
	{
		num_toks++;
		token = strtok(NULL, delim);
	}
	printf("The number of tokens = %d\n", num_toks);

	cmd_toks = malloc((sizeof(char *) * num_toks) + 1);
	if (!cmd_toks)
		return (NULL);

	token = NULL;
	token = strtok(cmd, delim);

	i = 0;
	while (token)
	{
		cmd_toks[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	cmd_toks[i] = NULL;

	free(tmp_cmd);

	return (cmd_toks);
}

char *look_for_path(char **av, char **ev)
{
	char *path = NULL;
	int i;

	for (i = 0; ev[i]; i++)
	{
		if (strncmp(ev[i], "PATH=", 5) == 0)
		{
			path = strdup(ev[i]);
		}
		if (!path)
			perror(av[0]);
	}
	return (path);
}
