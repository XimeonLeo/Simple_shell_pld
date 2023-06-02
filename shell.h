#ifndef __SHELL_H__
#define __SHELL_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void _write(char *str, int stm);
char **tokenizer(char *cmd, char *delim);
char *look_for_path(char **av, char **ev);

#endif
