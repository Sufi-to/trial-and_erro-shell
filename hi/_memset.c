#include "simpleshellmain.h"
/**
 * _memset - fills a block of memory with a specific value.
 * It is a safer alternative to writing directly to memory
 * because it performs bounds checking and ensures type safety.
 * @memo_block: A pointer to the memory block to be filled (void *).
 * @val: The value to fill the memory with (int).
 * @byte_num: The number of bytes to fill (size_t).
 * Return: A pointer to the filled memory block (void *),
 * which is the same as the input memo_block.
*/
void *_memset(void *memo_block, int val, size_t byte_num)
{
size_t	i;
i = 0;
while (i < byte_num)
{
((unsigned char *)memo_block)[i] = val;
i++;
}
return (memo_block);
}
