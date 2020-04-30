#include "rb_trees.h"

/**
 * rb_tree_remove - removes a node from a Red-Black Tree
 *
 * @root: pointer to root node of tree
 * @n: value to search for and remove from tree
 *
 * Return: pointer to new root of the tree after removal
 */
rb_tree_t *rb_tree_remove(rb_tree_t *root, int n)
{
	rb_tree_t *remove = root;

	while (remove && remove->n != n)
	{
		if (remove->n > n)
			remove = remove->left;
		else
			remove = remove->right;
	}
	return (rb_tree_delete(root, remove));
}

/**
 * rb_tree_delete - deltes node from RB Tree
 *
 * @root: pointer to root node of tree
 * @remove: node to remove
 * Return: pointer to new root
 */
rb_tree_t *rb_tree_delete(rb_tree_t *root, rb_tree_t *remove)
{
	rb_tree_t *x = NULL;
	rb_tree_t *y = remove;
	rb_color_t og_color = remove->color;

	if (remove->left == NULL)
	{
		x = remove->right;
		rb_transplant(&root, remove, remove->right);
	}
	else if (remove->right == NULL)
	{
		x = remove->left;
		rb_transplant(&root, remove, remove->left);
	}
	else
	{
		y = tree_min(remove->right);
		if (y->color)
			og_color = y->color;
		x = y->right;
		if (y->parent && y->parent == remove)
			x->parent = y;
		else
		{
			rb_transplant(&root, y, y->right);
			y->right = remove->right;
			y->right->parent = y;
		}
		rb_transplant(&root, remove, y);
		y->left = remove->left;
		y->left->parent = y;
		y->color = remove->color;
	}
	if (og_color == BLACK)
		rb_delete_fixup(root, x);
	return (root);
}
/**
 * rb_transplant - replaces one subtree as a child of its parent with
 *                 another subtree
 * @root: pointer to root node of tree
 * @x: root of subtree to replace
 * @y: subtree to replace with
 *
 * Return: new pointer to root
 */
void rb_transplant(rb_tree_t **root, rb_tree_t *x, rb_tree_t *y)
{
	if (x->parent == NULL)
		*root = y;
	else if (x->parent->left && x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;
	if (y)
		y->parent = x->parent;
}

/**
 * rb_delete_fixup - restores red-black properties to search tree
 *
 * @root: pointer to root node of tree
 * @x: node to fix
 *
 * Return: new pointer to root
 */
rb_tree_t *rb_delete_fixup(rb_tree_t *root, rb_tree_t *x)
{
	while (x != NULL && x->color == BLACK)
	{
		if (x == x->parent->left)
			x = rb_delete_fix_right(&root, x);
		else
			x = rb_delete_fix_left(&root, x);
	}
	if (x)
		x->color = BLACK;
	return (root);
}

/**
 * rb_delete_fix_left - fixes left sibling
 *
 * @root: pointer to root of tree
 * @x: node to fix
 *
 * Return: pointer to updated node
 */
rb_tree_t *rb_delete_fix_left(rb_tree_t **root, rb_tree_t *x)
{
	rb_tree_t *y;

	y = x->parent->left;
	/* CASE 1 */
	if (y && y->color == RED)
	{
		y->color = BLACK;
		x->parent->color = RED;
		rb_rotate_right(root, x->parent);
		y = x->parent->left;
	}
	/* CASE 2 */
	if (y && y->right->color == BLACK && y->left->color == BLACK)
	{
		y->color = RED;
		x = x->parent;
	}
	/* CASE 3 */
	else if (y && y->left->color == BLACK)
	{
		y->right->color = BLACK;
		y->color = RED;
		rb_rotate_left(root, y);
		y = x->parent->left;
	}
	/* CASE 4 */
	y->color = x->parent->color;
	x->parent->color = BLACK;
	y->right->color = BLACK;
	rb_rotate_right(root, x->parent);
	x = *root;

	return (x);
}

/**
 * rb_delete_fix_right - fixes right sibling
 *
 * @root: pointer to root of tree
 * @x: node to fix
 *
 * Return: pointer to new root
 */
rb_tree_t *rb_delete_fix_right(rb_tree_t **root, rb_tree_t *x)
{
	rb_tree_t *y = NULL;

	y = x->parent->right;
		/* CASE 1 */
	if (y && y->color == RED)
	{
		y->color = BLACK;
		x->parent->color = RED;
		rb_rotate_left(root, x->parent);
		y = x->parent->right;
	}
	/* CASE 2 */
	if (y && y->left->color == BLACK && y->right->color == BLACK)
	{
		y->color = RED;
		x = x->parent;
	}
	/* CASE 3 */
	else if (y && y->right->color == BLACK)
	{
		y->left->color = BLACK;
		y->color = RED;
		rb_rotate_right(root, y);
		y = x->parent->right;
	}
	/* CASE 4 */
	y->color = x->parent->color;
	x->parent->color = BLACK;
	y->right->color = BLACK;
	rb_rotate_left(root, x->parent);
	x = *root;

	return (x);
}

/**
 * tree_min - finds the minimum in a RB Tree
 * @root: pointer to root of tree
 * Return: node with min
 */
rb_tree_t *tree_min(rb_tree_t *root)
{
	while (root->left)
		root = root->left;
	return (root);
}
