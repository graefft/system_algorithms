#include "heap.h"

/**
 * sift_down - heapifies subtree
 *
 * @heap: pointer to heap to heapify
 */
void sift_down(heap_t *heap)
{
	binary_tree_node_t *largest, *node;

	if (!heap || !heap->root)
		return;
	node = heap->root;
	while (node->left)
	{
		largest = node->left;
		if (node->right && heap->data_cmp(node->data, node->right->data) >= 0 &&
		heap->data_cmp(node->right->data, node->left->data) < 0 && node->left)
		{
			swap_nodes(node->right, node);
			largest = node->right;
		}
		else if (heap->data_cmp(node->left->data, node->data) <= 0)
			swap_nodes(node->left, node);
		node = largest;
	}
}

/**
 * heap_extract - extracts the root value of a Min Binary Heap
 *
 * @heap: pointer to the heap from which to extract the value
 * Return: pointer to the data that was stored in the root node, or NULL
 */
void *heap_extract(heap_t *heap)
{
	binary_tree_node_t *bottom_node;
	void *root_data;

	if (!heap || !heap->root)
		return (NULL);

	root_data = heap->root->data;
	bottom_node = nth_node(heap->root, heap->size);
	heap->root->data = bottom_node->data;

	if (bottom_node->parent)
	{
		if (bottom_node->parent->left == bottom_node)
			bottom_node->parent->left = NULL;
		else
			bottom_node->parent->right = NULL;
	}
	else
		heap->root = NULL;
	free(bottom_node);
	sift_down(heap);
	heap->size -= 1;
	return (root_data);
}
