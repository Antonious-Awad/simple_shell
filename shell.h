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

void start_loop(char *shell_name, int *exit_code);
int _putchar(char c);
int _put_str(char *str);
int _strlen(char *s);
char **tokenize(char *str);
void _free_dpl_ptr(char **str);
char *_strcpy(char *dest, char *src);

#endif
