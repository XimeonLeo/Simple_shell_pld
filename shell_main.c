#include "shell.h"

int main(void)
{
	char *cmd = NULL;
	size_t buff_size = 0;
	int i;

	for (;;)
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
		printf("%c\n", cmd[i++]);
	}

	}
	free(cmd);

	return (0);
}
