#include "rb_trees.h"

/**
 * rb_tree_is_valid - checks if a binary tree is a valid Red-Black Tree
 * @tree: pointer to root node of the tree to check
 * Return: 1 if tree is valid, otherwise 0
 */
int rb_tree_is_valid(const rb_tree_t *tree)
{

	if (!tree || tree->color != BLACK)
		return (0);

	if (!is_RBT(tree, INT_MIN, INT_MAX))
		return (0);
	return (1);
}

/**
 * is_RBT - checks if tree is a valid Binary Search Tree
 * @tree: binary tree
 * @min: min in the left subtree
 * @max: max in the right subtree
 * Return: 1 or 0
 */
int is_RBT(const rb_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if ((min && tree->n < min) || (max && tree->n > max))
		return (0);
	if (tree->color != RED && tree->color != BLACK)
		return (0);
	if (tree->color == RED)
	{
		if (tree->left && (tree->left)->color == RED)
			return (0);
		if (tree->right && (tree->right)->color == RED)
			return (0);
	}
	if (tree->n < min || tree->n > max)
		return (0);


	return (is_RBT(tree->left, min, tree->n) &&
		 is_RBT(tree->right, tree->n, max));
}
