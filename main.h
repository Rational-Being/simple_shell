#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
extern char **environ;
extern void free (void *__ptr) __THROW;
void gui();
int execute_if_abs_path(const char *command, char *const args[]);
int execute_search_path(const char *command, char *const args[]);
int launch_command(const char *command_line);
char* _getenv(const char *cmd_name); 
int execute_env(void);
int launch_env(void);
void print_error(const char *program_name, const char *message, int line_number);

#endif
