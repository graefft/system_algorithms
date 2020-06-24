#include "heap.h"

/**
 * binary_tree_node - creates generic Binary Tree node
 * @parent: pointer to parent node of node to be created
 * @data: data to be stored in the node
 * Return: pointer to created node, or NULL on failure
 */
binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data)
{
	binary_tree_node_t *new_node;

	new_node = malloc(sizeof(binary_tree_node_t));
	if (!new_node)
		return (NULL);

	new_node->parent = parent;
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}
