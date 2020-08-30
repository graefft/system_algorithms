#include "nary_trees.h"

/**
 * nary_tree_insert - inserts a node into an N-ary tree
 *
 * @parent: pointer to the parent node
 * @str: string to be stored in the parent node
 * Return: pointer to newly-created node or NULL on failure
 */
nary_tree_t *nary_tree_insert(nary_tree_t *parent, char const *str)
{
	nary_tree_t *new_tree_node;
	char *string_dup;

	new_tree_node = malloc(sizeof(nary_tree_t));
	if (!new_tree_node)
		return (NULL);

	string_dup = strdup((char *)str);
	new_tree_node->content = string_dup;

	new_tree_node->nb_children = 0;
	new_tree_node->parent = parent;
	new_tree_node->children = NULL;
	if (parent)
	{
		new_tree_node->next = parent->children;
		parent->children = new_tree_node;
		parent->nb_children++;
	}
	else
		new_tree_node->next = NULL;
	free(string_dup);
	return (new_tree_node);
}
