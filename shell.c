#include "shell.h"

/**
 * main - Entry point
 * @argc: number of command-line arguments passed by the user
 * @argv: pointer array to each argument passed
 * @env: pointer to the null terminated environment variables
 *
 * Return: Always 0 (Success)
 */

int main(int argc __attribute__((unused)), char **argv, char **env)
{
	char *lineptr;
	size_t no = 20;
	char *av[50];

	signal(SIGINT, sig_handler);

	lineptr = malloc(sizeof(char) * no);

	if (!lineptr)
		return (-1);

	/* non-interactive mode */
	if (!isatty(0))
		non_interact_mode(&lineptr, &no, argv[0], av, env);

	/* interactive mode */
	interact_mode(&lineptr, &no, argv[0], av, env);

	return (0);
}
