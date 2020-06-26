#include "heap.h"

/**
 * heap_create - creates a heap data structure
 * @data_cmp: pointer to a comparison function
 * Return: pointer to new heap_t structure, or NULL on failure
 */
heap_t *heap_create(int (*data_cmp)(void *, void *))
{
	heap_t *new_heap_struct;

	if (!data_cmp)
		return (NULL);

	new_heap_struct = malloc(sizeof(heap_t));
	if (!new_heap_struct)
		return (NULL);

	new_heap_struct->root = NULL;
	new_heap_struct->size = 0;
	new_heap_struct->data_cmp = data_cmp;

	return (new_heap_struct);
}
