#include "rb_trees.h"

/**
 * rb_tree_is_valid - checks if a binary tree is a valid Red-Black Tree
 * @tree: pointer to root node of the tree to check
 * Return: 1 if tree is valid, otherwise 0
 */
int rb_tree_is_valid(const rb_tree_t *tree)
{
	int height;

	if (!tree)
		return (0);

	if (tree->color != BLACK)
		return (0);

	if (!is_bst(tree, 0, 0))
		return (0);

	if (!correct_colors(tree))
		return (0);

	height = find_height(tree);

	if (!check_rb_height(tree, height, 0))
		return (0);

	return (1);
}

/**
 * is_bst - checks if tree is a valid Binary Search Tree
 * @tree: binary tree
 * @min: min in the left subtree
 * @max: max in the right subtree
 * Return: 1 or 0
 */
int is_bst(const rb_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if ((min && tree->n < min) || (max && tree->n > max))
		return (0);

	return (is_bst(tree->left, 0, tree->n) &&
		 is_bst(tree->right, tree->n, 0));
}

/**
 * correct_colors - checks if RBT has valid colors
 *
 * @tree: binary tree
 * Return: 1 if yes, 0 if no
 */
int correct_colors(const rb_tree_t *tree)
{
	if (!tree)
		return (1);

	if (tree->color != RED && tree->color != BLACK)
		return (0);
	if (tree->color == RED)
	{
		if (tree->left && (tree->left)->color == RED)
			return (0);
		if (tree->right && (tree->right)->color == RED)
			return (0);
	}
	return (correct_colors(tree->left) && correct_colors(tree->right));
}

/**
 * find_height - gets height of rb tree
 *
 * @tree: binary tree
 * Return: maximum of black nodes between root and leaf
 */
int find_height(const rb_tree_t *tree)
{
	int height;

	if (!tree)
		return (0);

	height = MAXIMUM(find_height(tree->left), find_height(tree->right));

	if (tree->color == BLACK)
		height++;
	return (height);
}

/**
 * check_rb_height - finds the height of black nodes in RBT
 *
 * @tree: tree to check
 * @blk_height: number of black nodes
 * @height: max height
 *
 * Return: 1 if yes, 0 if no
 */
int check_rb_height(const rb_tree_t *tree, int blk_height, int height)
{
	if (!tree)
	{
		if (height == blk_height)
			return (1);
		return (0);
	}
	if (tree->color == BLACK)
		height++;

	return (check_rb_height(tree->left, blk_height, height) &&
		check_rb_height(tree->right, blk_height, height));
}
