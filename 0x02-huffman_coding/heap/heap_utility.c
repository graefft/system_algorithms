#include "heap.h"

/**
 * swap_nodes - utility function to swap two binary_tree_node elements
 *
 * @x: first element
 * @y: second element
 */
void swap_nodes(binary_tree_node_t *x, binary_tree_node_t *y)
{
	void *temp;

	temp = x->data;
	x->data = y->data;
	y->data = temp;
}


/**
 * is_perfect_recursion - recursive function to check if binary tree is perfect
 *
 * @tree: root
 * @depth: depth
 * @level: checks level
 * Return: 1 if true, 0 if false
 */
int is_perfect_recursion(binary_tree_node_t *tree, int depth, int level)
{
	if (!tree)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (depth == level + 1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (is_perfect_recursion(tree->left, depth, level + 1) &&
			is_perfect_recursion(tree->right, depth, level + 1));
}


/**
 * binary_tree_is_perfect - function that checks if binary tree is perfect
 *
 * @tree: binary tree
 * Return: 1 if tree is perfect
 */
int binary_tree_is_perfect(binary_tree_node_t *tree)
{
	int depth;

	if (tree == NULL)
		return (0);

	depth = find_depth(tree);
	return (is_perfect_recursion(tree, depth, 0));
}
