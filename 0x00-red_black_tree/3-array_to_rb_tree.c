#include "rb_trees.h"

/**
 * array_to_rb_tree - builds a Binary Search Tree from an array
 *
 * @array: pointer to the first element of array to be converted
 * @size: number of elements in the array
 *
 * Return: pointer to root node of created RB Tree, or NULL on failure
 */
rb_tree_t *array_to_rb_tree(int *array, size_t size)
{
	size_t i;
	rb_tree_t *new_RB_tree = NULL;

	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		rb_tree_insert(&new_RB_tree, array[i]);

	return (new_RB_tree);
}
