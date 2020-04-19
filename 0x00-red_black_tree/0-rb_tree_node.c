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
