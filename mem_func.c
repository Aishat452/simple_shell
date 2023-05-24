#include "main.h"

/**
 * _memcpy - copies info between the void pointers.
 * @destptr: destination pointer.
 * @src_ptr: source pointer
 * @size: new pointer size
 * Return: void
 */
void _memcpy(void *destptr, const void *src_ptr, unsigned int size)
{
	char *char_destptr = (char *)destptr;
	char *char_src_ptr = (char *)src_ptr;
	unsigned int i;

	for (i = 0; i < size; i++)
		char_destptr[i] = char_src_ptr[i];
}

/**
 * _realloc - realocates memory block.
 * @src_ptr: points to the previously allocated memory
 * @old_size: old size
 * @new_size: new size
 * Return: pointer
 */
void *_realloc(void *src_ptr, unsigned int old_size, unsigned int new_size)
{
	void *destptr;

	if (src_ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(src_ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (src_ptr);

	destptr = malloc(new_size);
	if (destptr == NULL)
		return (NULL);

	if (new_size < old_size)
		_memcpy(destptr, src_ptr, new_size);
	else
		_memcpy(destptr, src_ptr, old_size);

	free(src_ptr);
	return (destptr);
}

/**
 * _reallocdp - reallocs memory block
 * @src_ptr: double pointer
 * @old_size: old size
 * @new_size: new size in bytes
 * Return: pointer
 */
char **_reallocdp(char **src_ptr, unsigned int old_size, unsigned int new_size)
{
	char **destptr;
	unsigned int i;

	if (src_ptr == NULL)
		return (malloc(sizeof(char *) * new_size));

	if (new_size == old_size)
		return (src_ptr);

	destptr = malloc(sizeof(char *) * new_size);
	if (destptr == NULL)
		return (NULL);

	for (i = 0; i < old_size; i++)
		destptr[i] = src_ptr[i];

	free(src_ptr);

	return (destptr);
}
