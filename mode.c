#include "shell.h"

/**
 * non_interact_mode - none interactive shell mode
 * @lineptr: pointer to lineptr (used by getline funct)
 * @no: pointer to num. of bytes to be read by getline funct
 * @sh_name: first index of the main argument vector
 * @av: argument vector for execve funct
 * @env: enviroment vector for execve funct
 */
void non_interact_mode(char **lineptr, size_t *no,
		char *sh_name, char **av, char **env)
{
	int read_byte;

	read_byte = getline(lineptr, no, stdin);

	if (read_byte <= 1)
		exit_shell(0, *lineptr);

	(*lineptr)[read_byte - 1] = 0;

	/* splits the input string into arguments */
	handle_args(*lineptr, av);

	if (_which(av[0], env))
		av[0] = _which(av[0], env);

	if (execve(av[0], av, env) < 0)
	{
		printf("%s: 1: %s: not found\n", sh_name, av[0]);
		exit_shell(127, *lineptr);
	}
}
/**
 * interact_mode - interactive shell mode
 * @lineptr: pointer to lineptr (used by getline funct)
 * @no: pointer to num. of bytes to be read by getline funct
 * @sh_name: first index of the main argument vector
 * @av: argument vector for execve funct
 * @env: enviroment vector for execve funct
 */

void interact_mode(char **lineptr, size_t *no,
		char *sh_name, char **av, char **env)
{
	pid_t pid;
	int read_byte;

	while (1)
	{
		rewind(stdin);
		printf("$ ");
		read_byte = getline(lineptr, no, stdin);

		if (read_byte == -1)
		{
			putchar(10);
			exit_shell(0, *lineptr);
		}
		/* checks if only the return key is entered */
		if (read_byte <= 1)
			continue;
		if ((*lineptr)[read_byte - 1] == 10)
			(*lineptr)[read_byte - 1] = 0;

		/* splits the input string into arguments */
		handle_args(*lineptr, av);

		if (_which(av[0], env))
			av[0] = _which(av[0], env);

		if (!strcmp(av[0], "exit"))
			exit_shell(0, *lineptr);

		pid = fork();
		if (pid < 0)
		{
			perror("Error: ");
			exit_shell(98, *lineptr);
		}
		if (pid == 0)
		{
			if (execve(av[0], av, env) == -1)
			{
				printf("%s: No such file or directory\n", sh_name);
				exit_shell(127, *lineptr);
			}
		}
		else
			wait(NULL);
	}
}
