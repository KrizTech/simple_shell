#include "shell.h"

/**
 * handle_args - splits input string into arg. tokens
 * @str: string
 * @av: empty auto array of char *(strings) (preferable size > 30)
 */
void handle_args(char *str, char **av)
{
int i = 0;
char *token;

if (!str)
exit(98);

token = _strtok(str, " ");
while (token)
{
av[i] = token;
token = _strtok(NULL, " ");
i++;
}
av[i] = NULL;
}


/**
 * _testpath - generates absolute paths to commands to be tested
 * @path: path from enviroment
 * @command: command to be tested
 *
 * Return: absolute path to command that need testing
 */
char *_testpath(const char *path, const char *command)
{
char *ptr;
int i = 0, j = 0;

if (!path && !command)
return (NULL);

ptr = malloc(sizeof(const char) * (_strlen(path) + _strlen(command) + 2));
if (!ptr)
return (NULL);
while (i < _strlen(path))
{
ptr[i] = path[i];
i++;
}
ptr[i++] = '/';
while (j < _strlen(command))
{
ptr[i] = command[j];
i++;
j++;
}
ptr[i] = 0;
return (ptr);
}

/**
 * _which - returns fullpath to a file or link
 * @command: command to be tested
 * @env: enviromnent vector from main function
 *
 * Return: valid absolute path to command or NULL
 */
char *_which(const char *command, char **env)
{
char *token, *path, *pathcpy, *testpath, *rtn = NULL;

/* check if command has fullpath */
if (!(command[0] >= 'a' && command[0] <= 'z'))
{
if (!access(command, F_OK))
return ((char *)command);
return (NULL);
}

path = _getenv("PATH", env);
pathcpy = strdup(path);
token = _strtok(pathcpy, ":");

while (token)
{
testpath = _testpath(token, command);
token = _strtok(NULL, ":");

if (!access(testpath, F_OK))
rtn = testpath;
}

free(pathcpy);
pathcpy = NULL;
return (rtn);
}

/**
 * sig_handler - Function that stops control C from terminating the shell
 * @signum: the signal for control C
 */
void sig_handler(int signum)
{
if (signum)
{
printf("\n$ ");
fflush(stdout);
}
}

