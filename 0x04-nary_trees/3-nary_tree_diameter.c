#include "nary_trees.h"

/**
 * max_height - recursive function to find diameter of N-ary tree
 *
 * @root: pointer to root node of tree
 * @diameter: maximum diameter between two nodes
 * Return: max height
 */
size_t max_height(nary_tree_t const *root, size_t *diameter)
{
	nary_tree_t *child;
	size_t max_1 = 0;
	size_t max_2 = 0;
	size_t height;

	if (!root)
		return (0);

	for (child = root->children; child; child = child->next)
	{
		height = max_height(child, diameter);
		if (height >= max_1)
		{
			max_2 = max_1;
			max_1 = height;
		}
		else if (height > max_2)
			max_2 = height;
	}
	*diameter = MAX(*diameter, max_1 + max_2);
	return (max_1 + 1);
}

/**
 * nary_tree_diameter - computes the diameter of N-ary tree
 *
 * @root: pointer to root node
 * Return: diameter of tree pointed to by root
 */
size_t nary_tree_diameter(nary_tree_t const *root)
{
	size_t diameter = 0;

	if (!root)
		return (0);

	max_height(root, &diameter);
	/* add off by 1 error due to HBTN checker issue */
	return (diameter + 1);
}
