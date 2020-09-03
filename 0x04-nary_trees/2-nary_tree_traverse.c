#include "nary_trees.h"

/**
 * nary_tree_traversal - function that goes through an N-ary tree, node by node
 *
 * @root: pointer to root node of tree to traverse
 * @action: pointer to function to execute for each node being traversed
 *    - node is a pointer to the node being traverse
 *    - depth is the depth of the node being traversed
 *
 * Return: maximum depth of the tree
 */
size_t nary_tree_traverse(nary_tree_t const *root,
	void (*action)(nary_tree_t const *node, size_t depth))
{
	size_t depth = 0, this_max;

	if (!root)
		return (0);

	while (root)
	{
		action(root, depth);
		depth++;
		this_max = nary_tree_traverse(root->children, action);
		root = root->next;
		if (this_max > depth)
			depth  = this_max;
	}

	return (this_max);
}
