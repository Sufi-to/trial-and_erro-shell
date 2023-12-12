#include "simpleshellmain.h"

void	*_calloc(size_t count, size_t size)
{
	void	*ptr;

	if ((count >= SIZE_MAX && size > 1) || (count > 1 && size > SIZE_MAX))
		return (NULL);
	if (!count || !size)
		return (malloc(count * size));
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	_bzero(ptr, size * count);
	return (ptr);
}