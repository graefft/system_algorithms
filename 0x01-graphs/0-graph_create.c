#include "graphs.h"

/**
 * graph_create - allocates memory to store a graph_t structure and initializes
 *				  its content
 *
 * struct vertex_s {
 *		size_t		nb_vertices;
 *		vertex_t	*vertices;
 * };
 *
 * Return: pointer to allocated structure or NULL on failure
 */
graph_t *graph_create(void)
{
	graph_t *new_graph;

	new_graph = malloc(sizeof(graph_t));
	if (!new_graph)
		return (NULL);

	return (new_graph);
}
