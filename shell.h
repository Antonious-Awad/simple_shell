#ifndef SHELL_H
#define SHELL_H

extern char **environ;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * struct path - path structure for usage in a singly linked list
 * @dir: directory string in path array
 * @next: next directory pointer
 */
typedef struct path
{
	char *dir;
	struct path *next;
} path_t;

void start_loop(char *shell_name, int *exit_code);
int _putchar(char c);
int _put_str(char *str);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, size_t n);
char **tokenize(char *str, char delim);
void _free_dbl_ptr(char **str);
char **get_command(int *exit_code);
char *_getenv(char *env_var);
int handle_builtin(char **command);
void exec_command(char **command, char *shell_name, int *exit_code);

#endif
