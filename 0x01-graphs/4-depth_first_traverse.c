#include "graphs.h"

/**
 * depth_first_traverse - goes through graph using depth-first algorithm
 * @graph: pointer to graph to traverse
 * @action: pointer to function to be called for each visited vertex
 * Return: biggest vertex depth or 0 on failure
 */
size_t depth_first_traverse(const graph_t *graph, void (*action)
							(const vertex_t *v, size_t depth))
{
	size_t max_depth = 0;
	int *visited;

	if (!graph || !action)
		return (0);
	visited = calloc(graph->nb_vertices, sizeof(*visited));
	if (!visited)
		return (0);
	dfs(graph->vertices, action, visited, 0, &max_depth);
	free(visited);
	return (max_depth);
}

/**
 * dfs - recursive function to find max depth using depth-first search
 * @vertex: vertex to search
 * @action: pointer to function to be called for each visited vertex
 * @visited: boolean
 * @depth: current depth
 * @max_depth: max depth
 * Return: max_depth or 0 on failure
 */
void dfs(vertex_t *vertex, void (*action)(const vertex_t *v, size_t depth),
			int *visited, size_t depth, size_t *max_depth)
{
	edge_t *edges;

	if (!vertex || visited[vertex->index])
		return;

	action(vertex, depth);
	visited[vertex->index] = 1;

	if (depth > *max_depth)
		*max_depth = depth;
	depth++;

	edges = vertex->edges;
	while (edges)
	{
		dfs(edges->dest, action, visited, depth, max_depth);
		edges = edges->next;
	}
}
