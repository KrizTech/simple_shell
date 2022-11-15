#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

/* shell none interact mode functions */
void non_interact_mode(char **lineptr,
			size_t *no, char *sh_name, char **av, char **env);

/* shell interact mode function */
void interact_mode(char **lineptr, size_t *no,
		char *sh_name, char **av, char **env);

/* shell_util functionc */
void handle_args(char *str, char **av);
char *_testpath(const char *path, const char *command);
char *_which(const char *command, char **env);
void sig_handler(int signum);

/* std_util functions */
int _strtok_validate(char *str, char *backup, char *delm);
char *_strtok(char *str, char *delm);
int _strlen(const char *str);
void exit_shell(int status, char *ptr);

/* _env functions */
int check_var(char *env, const char *name);
char *getvalue(char *line);
char *_getenv(const char *name, char **env);
int _unsetenv(const char *name, char **env);
extern char **environ;

#endif /* SHELL_H */
