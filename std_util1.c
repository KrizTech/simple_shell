#include "shell.h"

/**
 * _strtok_validate - validation for _strtok function
 * @str: main string
 * @backup: backup string generated in the _strtok function
 * @delm: delimeter
 *
 * Return: -1 or 0
 */
int _strtok_validate(char *str, char *backup, char *delm)
{
/* checks delimeter */
if (!delm)
return (-1);

/* checks if both backup and str have values */
if (backup && str)
return (-1);

/* checks if both backup and str are NULL */
if (!backup && !str)
return (-1);

return (0);
}
/**
 * _strtok - breaks a string into a sequence of
 * zero or more nonempty tokens
 * @str: string to be broken down
 * @delm: delimeter
 *
 * Return: token (char *)
 */
char *_strtok(char *str, char *delm)
{
static char *backup;
char *rtn = NULL;

/* check validation */
if (_strtok_validate(str, backup, delm) < 0)
return (NULL);

/* checks if backup is NULL && str has value */
/* Function's first call */
if (!backup && str)
backup = str;

/* checks if str is NULL && backup has value */
/* Function's subsequent calls */
if (!str && backup)
str = backup;
while (*str)
{
/* checks if the next char is \0 */
if (*(str + 1) == '\0')
{
rtn = backup;
backup = NULL;
return (rtn);
}
/* checks if the next char is the delimeter */
if (*(str + 1) == *delm)
*(str + 1) = '\0';
str++;
}
str++;

/* moves pointer over successive occurence of delimiter */
while (*str == *delm)
str++;

rtn = backup;
backup = str;
return (rtn);
}

/**
 * _strlen - Measures the length of a string
 * @str: A pointer to the string to be measured
 *
 * Return: length of the measured string
 */
int _strlen(const char *str)
{
int i;

if (!str)
return (-1);

for (i = 0; str[i]; i++)
{}

return (i);
}

/**
 * exit_shell - cleans up before exiting
 * @status: status no. for exit
 * @ptr: ptr to free
 */
void exit_shell(int status, char *ptr)
{
free(ptr);
ptr = NULL;
exit(status);
}

/**
 * _realloc - A function that reallocates a memory block using
 * malloc and free
 * @ptr: A pointer to the memory previously allocated with a
 * call to malloc
 * @old_size: The size, in bytes, of the allocated space for ptr
 * @new_size: The new size, in bytes of the new memory block
 *
 * Return: Returns without doing anything if new size is equal to
 * old size. A pointer to the reallocated memory if success
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *new_ptr;
unsigned int i, remainder;

if (new_size == old_size)
return (ptr);

if (ptr == NULL)
{
ptr = malloc(new_size);
return (ptr);
}

if ((new_size == 0) && (ptr != NULL))
{
free(ptr);
return (NULL);
}

new_ptr = malloc(new_size);

for (i = 0; i < new_size; i++, old_size++)
{
if (new_size > old_size)
{
remainder = new_size - old_size;

for (i = old_size + 1; remainder < new_size; i++, remainder++)
new_ptr[i] = remainder;
}

new_ptr[i] = old_size;
}

free(ptr);
return (new_ptr);
}

