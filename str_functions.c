#include "main.h"

/**
 * _strcat - concat two str
 * @dest: char pointer that points to destination of copied str
 * @src: const pointer to source of str
 * Return: returns destination
 */
char *_strcat(char *dest, const char *src)
{
	int a, b;

	a = 0;
	while (dest[a])
		a++;
	for (b = 0; src[b]; b++)
		dest[a++] = src[b];
	return (dest);
}
/**
 * *_strcpy - Copies str pointed to by the src.
 * @dest: char pointer type, points to dest of copied str
 * @src: points to the source of strings
 * Return: returns the destination.
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0, j = 0;

	while (*(src + i) != '\0')
	{
		i++;
	}
	for ( ; j < i ; j++)
	{
		dest[j] = src[j];
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strcmp - compares two str.
 * @s1: the str type to  compare
 * @s2: the str to compare.
 * Return: returns 0 always.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}
/**
 * _strchr - locate char in str.
 * @s: str.
 * @c: char.
 * Return: pointer that points to first occurrence char c.
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
 * _strspn - the length of the prefixed substring.
 * @s: initial seg.
 * @accept: bytes.that are accepted
 * Return: num of bytes accepted.
 */
int _strspn(char *s, char *accept)
{
	unsigned int j, k;

	for (j = 0; s[j] != '\0'; j++)
	{
		for (k = 0; accept[k] != '\0'; k++)
		{
			if (s[j] == accept[k])
			{
				break;
			}
		}
		if (accept[k] == '\0')
		{
			return (j);
		}
	}
	return (j);
}
