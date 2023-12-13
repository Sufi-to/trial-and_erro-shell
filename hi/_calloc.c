#include "simpleshellmain.h"
/**
 * _calloc - This function allocates contiguous memory for the
 * specified number of elements of the specified size and initializes
 * each element to zero. It is intended as a safer alternative to
 * malloc in cases where you want to ensure the memory is cleared before use.
 * @num_elements: The number of elements to allocate (size_t).
 * @byte_size: The size in bytes of each element (size_t).
 * Return: A pointer to the allocated memory block, or
 * NULL if the allocation failed.
*/
void *_calloc(size_t num_elements, size_t byte_size)
{
	void *ptr;

	if ((num_elements >= SIZE_MAX && byte_size > 1)
	|| (num_elements > 1 && byte_size > SIZE_MAX))
		return (NULL);
	if (!num_elements || !byte_size)
		return (malloc(num_elements * byte_size));
	ptr = malloc(num_elements * byte_size);
	if (!ptr)
		return (NULL);
	_bzero(ptr, byte_size * num_elements);
	return (ptr);
}
