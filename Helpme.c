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
	int index = 0;

	for (; str[index]; index++)
	{
		write(stm, &str[index], 1);
	}
}

/**
 * tokenizer - helps to tokenize a string
 *
 * @buff: the command to tokenize
 * @delim: the delimeter used to tikenize
 *
 * Returns: an array of strings of the command tokens
 */

char **tokenizer(char *buff, char *delim)
{
	char *token = NULL, *tmp_buff = NULL;
	int i = 0, num_toks = 0;
	char **buff_toks = NULL;

	tmp_buff = strdup(buff);

	token = strtok(tmp_buff, delim);

	while (token)
	{
		num_toks++;
		token = strtok(NULL, delim);
	}
	printf("The number of tokens = %d\n", num_toks);

	buff_toks = malloc((sizeof(char *) * num_toks) + 1);
	if (!buff_toks)
		return (NULL);

	token = NULL;
	token = strtok(buff, delim);

	i = 0;
	while (token)
	{
		buff_toks[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	buff_toks[i] = NULL;

	free(tmp_buff);

	return (buff_toks);
}

char *look_for_path(char **av, char **ev)
{
	char *path = NULL;
	int i = 0;

	for (; ev[i]; i++)
	{
		if (strncmp(ev[i], "PATH=", 5) == 0)
		{
			path = strdup(ev[i]);
		}
	}
	if (!path)
		perror(av[0]);

	return (path);
}
