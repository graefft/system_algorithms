#include "heap.h"

/**
 * free_tree - frees binary_tree
 *
 * @root: root of tree to free
 * @free_data: function to free data of nodes
 */
void free_tree(binary_tree_node_t *root, void (*free_data)(void *))
{
	if (!root)
		return;

	free_tree(root->left, free_data);
	free_tree(root->right, free_data);
	if (free_data)
		free_data(root->data);
	free(root);
}

/**
 * heap_delete - deletes a heap
 *
 * @heap: pointer to heap to delete
 * @free_data: pointer to function that is used to free content of a node
 */
void heap_delete(heap_t *heap, void (*free_data)(void *))
{
	if (!heap)
		return;

	free_tree(heap->root, free_data);
	free(heap);
}
