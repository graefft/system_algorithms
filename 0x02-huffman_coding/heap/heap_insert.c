#include "heap.h"

/**
 * heap_insert - inserts a value in a Min Binary Heap
 * @heap: pointer to heap in which node has to be inserted
 * @data: pointer containing data to store in the new node
 * Return: pointer to created node with data, or NULL on failure
 */
binary_tree_node_t *heap_insert(heap_t *heap, void *data)
{
	binary_tree_node_t *new_node;

	if (!heap)
		return (NULL);

	new_node = binary_tree_node(heap->root, data);

	heap->size++;

	return (new_node);
}
