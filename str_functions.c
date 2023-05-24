#include "main.h"

/**
 * _strcat - concat two string
 * @new_str: char pointer
 * @src: const pointer
 * Return: new_str
 */
char *_strcat(char *new_str, const char *src)
{
	int len = 0, i = 0;

	while (new_str[len] != '\0')
		len++;

	while (src[i] != '\0')
	{
		new_str[len] = src[i];
		len++;
		i++;
	}
	new_str[len] = '\0';

	return new_str;
}
/**
 * *_strcpy - Copies string
 * @new_str: char pointer
 * @src: pointer to the source string
 * Return: new_str
 */
char *_strcpy(char *new_str, char *src)
{

	size_t i;

	for (i = 0; src[i] != '\0'; i++)
	{
		new_str[i] = src[i];
	}
	new_str[i] = '\0';

	return (new_str);
}
/**
 * _strcmp - compares two strings
 * @s1: the string1
 * @s2: the string2
 * Return: 0
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;

	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])

		/* if s1 is less than s2*/
		return (-1);
	return (0);
}
/**
 * _strshr - locates char in string
 * @s: string
 * @c: character
 * Return: pointer
 */
char *_strshr(char *s, char c)
{
	unsigned int i = 0;

	for (; *(s + i) != '\0'; i++)
		if (*(s + i) == c)
			return (s + i);
	if (*(s + i) == c)
		return (s + i);
	return ('\0');
}
/**
 * _strpln - computes the length of string
 * @s: string
 * @accept: bytes that are accepted
 * Return: num of bytes
 */
int _strpln(char *s, char *accept)
{
	int a, b, bool;

	for (a = 0; *(s + a) != '\0'; a++)
	{
		/*This flag tracks if the byte is accepted or not*/
		bool = 1;
		for (b = 0; *(accept + b) != '\0'; b++)
		{
			if (*(s + a) == *(accept + b))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (a);
}
