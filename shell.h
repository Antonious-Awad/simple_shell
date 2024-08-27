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

#define BUFF_SIZE 1024

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

/**
 * struct builtin - builtin object containing its corresponding function
 * @command: command name
 * @command_f: command function
 */
typedef struct builtin
{
	char *command;
	void (*command_f)(char **command, int *exit_code);
} builtin_t;

/* Strings */
int _strlen(const char *s);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strcpy(char *dest, const char *src);
char *_strdup(const char *str);
char *_strcat(char *dest, const char *src);
char **tokenize(char *str, char delim);

/* STDOUT */
int _putchar(char c);
int _put_str(char *str);

/* Memory */
void _free_dbl_ptr(char **str);
void free_path(path_t *head);

/* Errors */
void not_found(char *command_name, char *shell_name);

/* Shell */
void start_loop(char *shell_name, int *exit_code);
char **get_command(int *exit_code);
char *_getenv(char *env_var);
int handle_builtin(char **command, int *exit_code);
path_t *init_path(void);
int is_in_path(char **command, int *exit_code, char *shell_name);
void exec_command(char **command, char *shell_name, int *exit_code);

#endif
