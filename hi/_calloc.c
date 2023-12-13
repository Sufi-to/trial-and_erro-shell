#include "simpleshellmain.h"
/**
 * Description - This function allocates contiguous memory for the
 * specified number of elements of the specified size and initializes
 * each element to zero. It is intended as a safer alternative to
 * malloc in cases where you want to ensure the memory is cleared before use.
 * @numOfElements: The number of elements to allocate (size_t).
 * @byteSize: The size in bytes of each element (size_t).
 * Return: A pointer to the allocated memory block, or
 * NULL if the allocation failed.
*/
void *_calloc(size_t numOfElements, size_t byteSize)
{
	void *ptr;

	if ((numOfElements >= SIZE_MAX && byteSize > 1)
	|| (numOfElements > 1 && byteSize > SIZE_MAX))
		return (NULL);
	if (!numOfElements || !byteSize)
		return (malloc(numOfElements * byteSize));
	ptr = malloc(numOfElements * byteSize);
	if (!ptr)
		return (NULL);
	_bzero(ptr, byteSize * numOfElements);
	return (ptr);
}
