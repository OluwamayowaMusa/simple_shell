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
void _execute(char **arr_cmd, char *ptr, char **env);
void free_arrcmd(char **arrCmd);
void arr_cmd_size(char ***ptrCmd, int argNum, char *str);
void parse_exec_free(char *cmd, char *ptr, char **env);
int _strcmp(char **s1, char *s2);
char **get_path(char *cmd_ptr);
void arr_path_size(char ***ptrCmd, int argNum, char *str);
int no_arg_path(char *str, char *delim);
char *env_check(char **envPtr, char *cmd);

#endif
