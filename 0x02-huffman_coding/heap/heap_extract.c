#include "heap.h"

/**
 * sift_down - heapifies subtree
 *
 * @heap: pointer to heap to heapify
 */
void sift_down(heap_t *heap, binary_tree_node_t *node)
{
	binary_tree_node_t *largest = NULL;

	if (!heap || !heap->root || !node)
		return;

	if (node->right && heap->data_cmp(node->data, node->right->data) >= 0 &&
		heap->data_cmp(node->left->data, node->right->data) < 0)
	{
		swap_nodes(node->right, node);
		largest = node->right;
	}
	else if (heap->data_cmp(node->left->data, node->data) <= 0)
		swap_nodes(node->left, node);
	node = largest;
	sift_down(heap, largest);
}

/**
 * heap_extract - extracts the root value of a Min Binary Heap
 *
 * @heap: pointer to the heap from which to extract the value
 * Return: pointer to the data that was stored in the root node, or NULL
 */
void *heap_extract(heap_t *heap)
{
	void *data;

	if (!heap || !heap->root)
		return (NULL);

	data = heap->root->data;
	sift_down(heap, heap->root);
	return (data);
}
