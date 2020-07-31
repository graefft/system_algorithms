#include "heap.h"

/**
 * heapify - heapifies a binary tree
 *
 * @heap: pointer to heap
 * @inserted: new node that was just inserted
 * Return: inserted node
 */
binary_tree_node_t *heapify(heap_t *heap, binary_tree_node_t *inserted)
{
	void *temp;

	if (!inserted)
		return (NULL);

	while (inserted->parent)
	{
		if (heap->data_cmp(inserted->parent->data, inserted->data) > 0)
		{
			temp = inserted->data;
			inserted->data = inserted->parent->data;
			inserted->parent->data = temp;
		}
		inserted = inserted->parent;
	}
	return (inserted);
}

/**
 * nth_node - finds nth node of binary tree
 *
 * @root: pointer to root node
 * @n: nth node to find
 * Return: pointer to node or NULL if failed
 */
binary_tree_node_t *nth_node(binary_tree_node_t *root, int n)
{
	int bit_index, mask;

	if (!root || n <= 0)
		return (NULL);

	for (bit_index = 0; 1 << (bit_index + 1) <= (int)n; bit_index++)
		;
	for (--bit_index; bit_index >= 0; --bit_index)
	{
		mask = 1 << bit_index;
		if (n & mask)
		{
			if (root->right)
				root = root->right;
			else
				break;
		}
		else
		{
			if (root->left)
				root = root->left;
			else
				break;
		}
	}
	return (root);
}

/**
 * heap_insert - inserts a value into a Min Binary Heap
 *
 * @heap: pointer to heap in which node has to be inserted
 * @data: pointer containing data to store in new node
 * Return: created node containing data, or NULL on failure
 */
binary_tree_node_t *heap_insert(heap_t *heap, void *data)
{
	binary_tree_node_t *new_node, *parent_node;

	if (!heap)
		return (NULL);

	new_node = binary_tree_node(NULL, data);
	if (!new_node)
		return (NULL);

	heap->size += 1;
	if (!heap->root)
		heap->root = new_node;
	else
	{
		parent_node = nth_node(heap->root, heap->size);

		if (!parent_node->left)
			parent_node->left = new_node;
		else
			parent_node->right = new_node;

		new_node->parent = parent_node;
	}
	return (heapify(heap, new_node));
}
