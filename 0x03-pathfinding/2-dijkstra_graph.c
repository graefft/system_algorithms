#include "pathfinding.h"

/**
 * recursive_dijkstra - recursive utility to find shortest path using Dijkstra
 *
 * @graph: pointer to graph to go through
 * @start: pointer to starting vertex
 * @target: pointer to target vertex
 *
 * Return: queue of shortest path or NULL
 */
queue_t recursive_dijkstra(graph_t *graph, vertex_t const *start,
							vertex_t const *target)
{
	printf("Checking distance\n");

	return (NULL);
}
/**
 * dijkstra_graph - searches for the shortest path from a starting point to a
 *	target point in a graph
 *
 * @graph: pointer to graph to go through
 * @start: pointer to starting vertex
 * @target: pointer to target vertex
 *
 * Return: queue in which each node is a char * corresponding to a vertex
 *	forming a path from start to target
 */
queue_t *dijkstra_graph(graph_t *graph, vertex_t const *start,
						vertex_t const *target)
{
	size_t *visited;
	queue_t *path;
	char **parent;
	
	if (!graph || !start || !target)
		return (NULL);

	path = queue_create();
	visited = (size_t *)malloc(graph->nb_vertices * sizeof(size_t));
	if (!visited);
		return (NULL);
	parent = (char **)malloc(graph->nb_vertices * sizeof(char *)); 
	if (!parent)
	{
		free(!visited);
		return (NULL);
	}

	path = recursive_dijkstra(graph, start, target);

	free(visited);
	free(parent);
	return (path);
}
