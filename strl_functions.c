#include "main.h"

/**
 * _strdup - duplicates a string in heap memory.
 * @s: string pointer
 * Return: duplicated string
 */
char *_strdup(const char *s)
{
	char *newstr;
	size_t len;

	len = _strlen(s);
	newstr = malloc(sizeof(char) * (len + 1));
	if (newstr == NULL)
		return (NULL);
	_memcpy(newstr, s, len + 1);
	return (newstr);
}
/**
 * _strlen - Returns the lenght of a string.
 * @s: string pointer
 * Return: length of string
 */
int _strlen(const char *s)
{
	int a;

	for (a = 0; s[a] != 0; a++)
	{
	}
	return (a);
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

	for (a = 0, c = 0; str[a]; a++)
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
	/*if all characters in str are found in delim*/
	if (a == c)
		return (1);
	return (0);
}
/**
 * _strtok - splits a string by delimiter.
 * @str: string
 * @delim: delimiter
 * Return: next token or NULL
 */
char *_strtok(char str[], const char *delim)
{
	static char *split_ptr, *str_end;
	char *str_start;
	unsigned int a, bool;

	if (str != NULL)
	{
		if (cmp_chars(str, delim))
			return (NULL);
		split_ptr = str;
		a = _strlen(str);
		str_end = &str[a];
	}
	str_start = split_ptr;
	if (str_start == str_end)
		return (NULL);

	for (bool = 0; *split_ptr; split_ptr++)
	{
		if (split_ptr != str_start)
			if (*split_ptr && *(split_ptr - 1) == '\0')
				break;

		for (a = 0; delim[a]; a++)
		{
			if (*split_ptr == delim[a])
			{
				*split_ptr = '\0';
				if (split_ptr == str_start)
					/*if it points to a delimiter, move it*/
					str_start++;
				break;
			}
		}
		if (bool == 0 && *split_ptr)
			bool = 1;/*if the token has non-delimiter characters set flag*/
	}
	if (bool == 0)
		return (NULL);
	return (str_start);
}
/**
 * _isdigit - defines if string is a number
 * @s: string
 * Return: 1, 0
 */
int _isdigit(const char *s)
{
	unsigned int a;

	for (a = 0; s[a]; a++)
	{
		if (s[a] < 48 || s[a] > 57)
			return (0);
	}
	return (1);
}
