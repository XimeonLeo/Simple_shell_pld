#include "shell.h"

int main(__attribute__((unused)) int ac, char **av, char **ev)
{
	char *cmd = NULL, *path = NULL;
	char **cmd_toks = NULL, **path_toks = NULL, **exec_cmd = NULL;
	size_t buff_size = 0;
	int i = 0;

	/* Getting the path variable */
	path = look_for_path(av, ev);
	/* Tokenizing the path variable*/
	path_toks = tokenizer(path, ":=");
	/* The SHELL */
	for (;;) /* while (1) */
	{
	_write(" :) ", 1);

	/* Getting input from user using getline */
	if (getline(&cmd, &buff_size, stdin) == -1)
	{
		break;
	}

	/* Using write function to print out what getline receives */
	_write(cmd, 1);

	/* Removing the newline gotten as a result of using getline */
	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\n')
			cmd[i] = '\0';
		i++;
	}
	/* Tokenizing the command passed */
	cmd_toks = tokenizer(cmd, " ");

	i = 0;
	while (path_toks[i])
	{
		printf("%s\n", path_toks[i]);
		i++;
	}
	exec_cmd = malloc(sizeof(char *) * 20);
	i = 0;
	while (path_toks[i])
	{
		exec_cmd[0] = malloc(strlen(path_toks[i]) + strlen(cmd_toks[0] + 3));
		exec_cmd[0] = strdup(path_toks[i]);
		strcat(exec_cmd[0], "/");
		strcat(exec_cmd[0], cmd_toks[0]);
		strcat(exec_cmd[0], "\0");
		printf("%s\n", exec_cmd[0]);
		free(exec_cmd[0]);
		i++;
	}
	free(cmd_toks), free(exec_cmd);

	}
	free(path_toks), free(path), free(cmd);

	return (0);
}
