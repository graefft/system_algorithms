#ifndef __HEAP_H__
#define __HEAP_H__

#include <stdio.h>
#include <stdlib.h>

/**
 * struct binary_tree_node_s - Binary tree node data structure
 *
 * @data: Data stored in a node
 * @left: Pointer to the left child
 * @right: Pointer to the right child
 * @parent: Pointer to the parent node
 */
typedef struct binary_tree_node_s
{
	void *data;
	struct binary_tree_node_s *left;
	struct binary_tree_node_s *right;
	struct binary_tree_node_s *parent;
} binary_tree_node_t;

/**
 * struct heap_s - Heap data structure
 *
 * @size: Size of the heap (number of nodes)
 * @data_cmp: Function to compare two nodes data
 * @root: Pointer to the root node of the heap
 */
typedef struct heap_s
{
	size_t size;
	int (*data_cmp)(void *, void *);
	binary_tree_node_t *root;
} heap_t;

heap_t *heap_create(int (*data_cmp)(void *, void *));
binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data);

binary_tree_node_t *heap_insert(heap_t *heap, void *data);

void *heap_extract(heap_t *heap);
void heap_delete(heap_t *heap, void (*free_data)(void *));

binary_tree_node_t *heapify(heap_t *heap, binary_tree_node_t *inserted);
binary_tree_node_t *nth_node(binary_tree_node_t *root, int n);
int binary_tree_is_perfect(binary_tree_node_t *tree);
size_t binary_tree_height(binary_tree_node_t *tree);
void sift_down(heap_t *heap);
void swap_nodes(binary_tree_node_t *x, binary_tree_node_t *y);

#endif /*__HEAP_H__*/
