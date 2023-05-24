#include "main.h"

/**
 * _memcpy - copies info between the void pointers.
 * @dest_ptr: destination pointer.
 * @ptr: source pointer
 * @size: new pointer size
 * Return: void
 */
void _memcpy(void *dest_ptr, const void *ptr, unsigned int size)
{
	char *char_ptr = (char *)ptr;
	char *char_dest_ptr = (char *)dest_ptr;
	unsigned int a;

	for (a = 0; a < size; a++)
		char_dest_ptr[a] = char_ptr[a];
}

/**
 * _realloc - realocates memory block.
 * @ptr: points to the previously allocated memory
 * @old_size: old size
 * @new_size: new size
 * Return: pointer
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *dest_ptr;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	dest_ptr = malloc(new_size);
	if (dest_ptr == NULL)
		return (NULL);
	/*Copy the data from the old memory block to the new memory block*/
	if (new_size < old_size)
		_memcpy(dest_ptr, ptr, new_size);
	else
		_memcpy(dest_ptr, ptr, old_size);

	free(ptr);
	return (dest_ptr);
}

/**
 * _reallocdp - reallocs memory block
 * @ptr: double pointer
 * @old_size: old size
 * @new_size: new size in bytes
 * Return: pointer
 */
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **dest_ptr;
	unsigned int i;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * new_size));

	if (new_size == old_size)
		return (ptr);

	dest_ptr = malloc(sizeof(char *) * new_size);
	if (dest_ptr == NULL)
		return (NULL);

	for (i = 0; i < old_size; i++)
		dest_ptr[i] = ptr[i];

	free(ptr);

	return (dest_ptr);
}
