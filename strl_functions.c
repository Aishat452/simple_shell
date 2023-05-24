#include "main.h"

/**
 * _strdup - duplicates a string in heap memory.
 * @s: string pointer
 * Return: string
 */
char *_strdup(const char *s)
{
	char *new_str;
	size_t len;

	len = _strlen(s);
	new_str = malloc(sizeof(char) * (len + 1));
	if (new_str == NULL)
		return (NULL);
	_memcpy(new_str, s, len + 1);
	return (new_str);
}

/**
 * _strlen - Returns the lenght of a string.
 * @s: string pointer
 * Return: 0
 */
int _strlen(const char *s)
{
	int len;

	for (len = 0; s[len] != 0; len++)
	{
	}
	return (len);
}

/**
 * cmp_chars - compares the chars of strings
 * @str: string
 * @delim: delimiter
 * Return: 1, 0 if not.
 */
int cmp_chars(char str[], const char *delim)
{
	unsigned int a, b, c;

	for (a = 0, b = 0; str[a]; a++)
	{
		for (b = 0; delim[b]; b++)
		{
			if (str[a] == delim[b])
			{
				c++;
				break;
			}
		}
	}
	if (a == c)
		return (1);
	return (0);
}

/**
 * _strtok - splits a string into tokens
 * @str: string
 * @delim: delimiter
 * Return: pointer to next token or NULL
 */
char *_strtok(char str[], const char *delim)
{
	static char *split_ptr, *str_end;
	char *str_start;
	unsigned int i, bool;

	if (str != NULL)
	{
		if (cmp_chars(str, delim))
			return (NULL);
		split_ptr = str;
		i = _strlen(str);
		str_end = &str[i];
	}
	str_start = split_ptr;
	if (str_start == str_end)
		return (NULL);

	for (bool = 0; *split_ptr; split_ptr++)
	{

		if (split_ptr != str_start)
			if (*split_ptr && *(split_ptr - 1) == '\0')
				break;
		for (i = 0; delim[i]; i++)
		{
			if (*split_ptr == delim[i])
			{
				*split_ptr = '\0';
				if (split_ptr == str_start)
					str_start++;
				break;
			}
		}
		/*Set flag(bool) to 1 if a token is found*/
		if (bool == 0 && *split_ptr)
			bool = 1;
	}
	/*determines if any tokens were found*/
	if (bool == 0)
		return (NULL);
	return (str_start);
}

/**
 * _isdigit - defines if string is a number
 * @s: string
 * Return: 1, 0 if otherwise
 */
int _isdigit(const char *s)
{
	unsigned int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] < 48 || s[i] > 57)
			return (0);
	}
	return (1);
}
