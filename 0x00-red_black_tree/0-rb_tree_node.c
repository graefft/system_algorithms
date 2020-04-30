#include "rb_trees.h"

/**
 * rb_tree_node - creates a Red-Black Tree node
 * @parent: pointer to parent node
 * @value: value to put in the new node
 * @color: color of the node
 * Return: pointer to new node, or NULL on failure
 */
rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color)
{
	rb_tree_t *new;

	new = malloc(sizeof(rb_tree_t));
	if (!new)
		return (NULL);

	new->parent = parent;
	new->n = value;
	new->color = color;
	new->left = NULL;
	new->right = NULL;

	return (new);
}

/**
 * rb_rotate_left - rotates subtree to left
 *
 * @tree: root node
 * @x: node to rotate
 */
void rb_rotate_left(rb_tree_t **tree, rb_tree_t *x)
{
	rb_tree_t *y = NULL;

	y = x->right;
	x->right = y->left;
	if (y->left)
		y->left->parent = x;
	y->parent = x->parent;
	if (x->parent == NULL)
		*tree = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;
	y->left = x;
	x->parent = y;
}

/**
 * rb_rotate_right - rotates subtree to right
 *
 * @tree: root node
 * @y: node to rotate
 */
void rb_rotate_right(rb_tree_t **tree, rb_tree_t *y)
{
	rb_tree_t *x = NULL;

	x = y->left;
	y->left = x->right;
	if (x->right)
		x->right->parent = y;
	x->parent = y->parent;
	if (y->parent == NULL)
		*tree = x;
	else if (y == y->parent->left)
		y->parent->left = x;
	else
		y->parent->right = x;
	x->right = y;
	y->parent = x;
}
