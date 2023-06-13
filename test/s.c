#include "shell.h"

int main()
{
	char *buff = NULL;
	char **cmd_tokens = NULL;
	size_t buff_size = 0, i = 0;

	while (1)
	{
		_write("$ ", 1);
		if (getline(&buff, &buff_size, stdin) < 0)
		{
			_write("error has occured", 1);
			break;
		}
		while (buff[i])
		{
			if (buff[i] == '\n')
				buff[i] = '\0';
			i++;
		}
		cmd_tokens = tokenizer(buff, " ");
		
		i = 0;
		while (cmd_tokens[i])
		{
			printf("%s\n", cmd_tokens[i++]);
		}
		free(cmd_tokens);
	}
	free(buff);

	return (0);
}
