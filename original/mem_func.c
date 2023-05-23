#include "main.h"

/**
 * _memcpy - this will copy info between the void pointers.
 * @newptr: the destination's pointer.
 * @ptr: the source's pointer.
 * @size: new pointer's size.
 *
 * Return: has no return.
 */
void _memcpy(void *newptr, const void *ptr, unsigned int size)
{
	char *char_ptr = (char *)ptr;
	char *char_newptr = (char *)newptr;
	unsigned int i;

	for (i = 0; i < size; i++)
		char_newptr[i] = char_ptr[i];
}

/**
 * _realloc - this realocates the  memory's block.
 * @ptr: pointer that point to the previously allocated memory.
 * @old_size: old size of the allocated space of previous alloc.
 * @new_size: new size.
 * Return: returns ptr.
 * if new_size == old_size, return ptr with no changes.
 * if malloc fails, returns NULL.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *newptr;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	newptr = malloc(new_size);
	if (newptr == NULL)
		return (NULL);

	if (new_size < old_size)
		_memcpy(newptr, ptr, new_size);
	else
		_memcpy(newptr, ptr, old_size);

	free(ptr);
	return (newptr);
}

/**
 * _reallocdp - realloc the memory block of double pointer.
 * @ptr: double ptr to the previous allocated memory.
 * @old_size: old size of the alloc space of ptr.
 * @new_size: new size in bytes.
 * Return: returns ptr.
 * if new_size == old_size, return ptr with no changes.
 * if malloc fails, return NULL.
 */
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **newptr;
	unsigned int i;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * new_size));

	if (new_size == old_size)
		return (ptr);

	newptr = malloc(sizeof(char *) * new_size);
	if (newptr == NULL)
		return (NULL);

	for (i = 0; i < old_size; i++)
		newptr[i] = ptr[i];

	free(ptr);

	return (newptr);
}
