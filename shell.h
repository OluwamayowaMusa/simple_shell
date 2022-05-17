#ifndef SHELL_H
#define SHELL_H

/* Header Files */
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Function Prototypes */
int _strlen(char *s);
char *_strdup(char *str);
void print_arr(char **ptr);
char **get_cmd(char *cmd_ptr);
int no_arg(char *str, char *delim);
void _execute(char **arr_cmd);
void free_arrcmd(char **arrCmd);

#endif
