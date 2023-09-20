#ifndef MAIN_H
#define MAIN_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
int _putchar(char c);
int _strlen(char *s);
void print_string(char *str);
void _strcpy(char *dest, char *src);
void _execCommand(char **argv);
char *get_path(char *command);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_getenv(char *name);
char *_strdup(char *str);
int _atoi(char *s);
char **read_command_tokens(ssize_t charsRead, char *input);
#endif
