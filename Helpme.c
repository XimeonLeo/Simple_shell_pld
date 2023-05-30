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
