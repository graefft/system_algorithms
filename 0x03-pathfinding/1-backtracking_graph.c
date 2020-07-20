#include "pathfinding.h"

/**
 * recursive_backtrack_graph - recursive backtracking function for graphs
 *
 * @path: current path queue
 * @visited: array of vertices already visited
 * @current: current vertex
 * @target: target vertex
 *
 * Return: 1 on success, 0 on failure
 */
int recursive_backtrack_graph(queue_t **path, int *visited,
					vertex_t const *current, vertex_t const *target)
{
	char *city;
	edge_t *edges;

	if (current == NULL || visited[current->index] == 1)
		return (0);

	printf("Checking %s\n", current->content);

	if (strcmp(current->content, target->content) == 0)
	{
		city = strdup(current->content);
		queue_push_front(*path, city);
		return (1);
	}
	visited[current->index] = 1;
	for (edges = current->edges; edges; edges = edges->next)
	{
		if (recursive_backtrack_graph(path, visited, edges->dest, target))
		{
			city = strdup(current->content);
			queue_push_front(*path, city);
			return (1);
		}
	}
	visited[current->index] = 0;
	return (0);
}

/**
 * backtracking_graph - searches for first path from a starting point to a
 *						target point in a graph
 *
 * @graph: pointer to graph to go through
 * @start: pointer to starting vertex
 * @target: pointer to target vertex
 *
 * Return: queue in which each node is a char * corresponding to a vertex,
 *         forming a path from start to target
 */
queue_t *backtracking_graph(graph_t *graph, vertex_t const *start,
							vertex_t const *target)
{
	int *visited = NULL;
	int it_worked;
	queue_t *path;

	if (!graph || !start || !target)
		return (NULL);

	path = queue_create();
	if (!path)
		return (NULL);

	visited = calloc(graph->nb_vertices, sizeof(*visited));
	if (!visited)
	{
		queue_delete(path);
		return (NULL);
	}

	it_worked = recursive_backtrack_graph(&path, visited, start, target);
	free(visited);
	if (it_worked)
		return (path);

	queue_delete(path);
	return (NULL);
}
