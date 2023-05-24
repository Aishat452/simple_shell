#include "main.h"

/**
 * _strcat - concat two string
 * @dest: char pointer
 * @src: const pointer
 * Return: dest
 */
char *_strcat(char *dest, const char *src)
{
	int a, b;

	for (a = 0; dest[a] != '\0'; a++)
		;

	for (b = 0; src[b] != '\0'; b++)
	{
		dest[a] = src[b];
		a++;
	}

	dest[a] = '\0';
	return (dest);
}
/**
 * *_strcpy - Copies string
 * @dest: char pointer
 * @src: points to the source of string
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{

	size_t i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
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
		return (-1);
	return (0);
}
/**
 * _strchr - locates char in string
 * @s: string
 * @c: character
 * Return: pointer
 */
char *_strchr(char *s, char c)
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
 * _strspn - the length of string
 * @s: initial seg
 * @accept: bytes that are accepted
 * Return: num of bytes
 */
int _strspn(char *s, char *accept)
{
	int a, b, bool;

	for (a = 0; *(s + a) != '\0'; a++)
	{
		/*the flag is to track if the byte is accepted or not*/
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
			/*Exit the loop if byte is not accepted*/
			break;
	}
	return (a);
}
