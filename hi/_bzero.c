# include "simpleshellmain.h"
/**
 * Description - This function sets the first n bytes of the memory
 * area pointed to by s to zero.
 * This effectively clears the memory of any previously stored data.
 * @s: A pointer to the memory area to be cleared.
 * @n: The number of bytes to clear
 * Return: None (void)
*/
void _bzero(void *memo_pointer, size_t n_bytes)
{
	_memset(memo_pointer, 0, n_bytes);
}
