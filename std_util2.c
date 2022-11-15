#include "shell.h"

/**
 * reverse_array - Function that reverses a string
 * @str: The string to be reversed
 * @length: The lenghth of the string
 */

void reverse_array(char *str, int length)
{
char temp;
int first, end;

end = length - 1;

for (first = 0; first < end; first++, end--)
{
temp = str[end];
str[end] = str[first];
str[first] = temp;
}
}

/**
 * _itoa - Function that converts integer (base 10) to a character string
 * @num: The number (integer) to be converted
 * @str: A pointer to the address where the string will be stored in memory
 * @base: The conversion base
 *
 * Return: Character string, otherwise NULL if nothing is stored
 */

char *_itoa(int num, char *str, int base)
{
int i;
bool is_negative = false;

if (!str)
return (NULL);

if ((num < 0) && (base == 10))
{
is_negative = true;
num = -num;
}

if (num == 0)
{
str[0] = '0';
str[1] = '\0';
return (str);
}
else
{
for (i = 0; num > 0; i++)
{
str[i] = (num % 10) + '0';
num = num / 10;
}

if (is_negative)
str[i++] = '-';

str[i] = '\0';
}

reverse_array(str, i);

return (str);
}

/**
 * _strdup - Function that duplicates a string
 * @s: String to be duplicated
 *
 * Return: A pointer to the duplicated string if success, NULL
 * if enough memory was not allocated
 */

char *_strdup(const char *s)
{
char *dup_string;
int i, s_size;

s_size = _strlen(s);

dup_string = (char *)malloc(sizeof(char) * s_size + 1);

if (dup_string == NULL)
return (NULL);

for (i = 0; s[i]; i++)
dup_string[i] = s[i];

dup_string[i] = '\0';

return (dup_string);
}

