#include "shell.h"

int main(__attribute__((unused)) int ac, char **av, char **ev)
{
	char *cmd = NULL, *path = NULL;
	char **cmd_toks = NULL, **path_toks = NULL;
	size_t buff_size = 0;
	int i;

	for (;;) /* while (1) */
	{
	_write(" :) ", 1);

	if (getline(&cmd, &buff_size, stdin) == -1)
	{
		break;
	}

	_write(cmd, 1);

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\n')
			cmd[i] = '\0';
		i++;
	}
	cmd_toks = tokenizer(cmd, " ");
	path = look_for_path(av, ev);

	path_toks = malloc(sizeof(char *) * 20);
	if (!path_toks)
	{
		return (0);
	}
	path_toks = tokenizer(path, ":");

	i = 0;
	while (path_toks[i])
	{
		printf("%s\n", path_toks[i]);
		i++;
	}

	free(cmd_toks), free(path), free(path_toks);

	}
	free(path_toks), free(path), free(cmd_toks), free(cmd);

	return (0);
}
