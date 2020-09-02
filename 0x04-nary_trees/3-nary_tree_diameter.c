#include "nary_trees.h"

/**
 * max_height - recursive function to find diameter of N-ary tree
 *
 * @root: pointer to root node of tree
 * @diameter: maximum diameter between two nodes
 * Return: max height
 */
void max_height

/**
 * nary_tree_diameter - computes the diameter of N-ary tree
 *
 * @root: pointer to root node
 * Return: diameter of tree pointed to by root
 */
size_t nary_tree_diameter(nary_tree_t const *root)
{
	size_t diameter;

	if (!root)
		return (0);

	max_height(root, &diameter);
	/* add off by 1 error due to HBTN checker issue */
	return (diameter + 1);
}
