#include "pathfinding.h"

/**
 * get_min_distance - finds the vertex with lowest distance from source
 *
 * @graph: pointer to graph
 * @distance: array of distances from start vertex
 * @visited: array of if vertex has been visited
 * @index: current index
 *
 * Return: index with minimum distance or NULL
 */
vertex_t *get_min_distance(graph_t *graph, size_t *distance, size_t *visited,
		size_t *index)
{
	size_t min = ULONG_MAX;
	size_t i;
	vertex_t *vertex;

	vertex = graph->vertices;
	if (vertex == NULL)
		return (NULL);

	*index = ULONG_MAX;

	for (i = 0; i < graph->nb_vertices; i++)
	{
		if (visited[i] == 0 && min > distance[i])
		{
			min = distance[i];
			*index = i;
		}
	}
	if (*index == ULONG_MAX)
		return (NULL);

	while (vertex->next)
	{
		if (vertex->index == *index)
			return (vertex);
		vertex = vertex->next;
	}
	return (vertex);
}


/**
 * insert_into_queue - inserts vertices into queue
 *
 * @graph: pointer to graph with vertices
 * @path: pointer to path array
 * @path_via: pointer to path_via node
 * @start: start vertex
 * @target: target vertex
 *
 * Return: void
 */
void insert_into_queue(graph_t *graph, queue_t *path, vertex_t **path_via,
			vertex_t const *start, vertex_t const *target)
{
	size_t i = target->index;

	if (!path_via[i])
		return;

	if (!queue_push_front(path, strdup(target->content)))
		queue_delete(path);

	while (path_via[i] && i < graph->nb_vertices)
	{
		if (!queue_push_front(path, strdup(path_via[i]->content)))
			queue_delete(path);
		i = path_via[i]->index;
		if (i == start->index)
			return;
	}
}


/**
 * recursive_dijkstra - recursive utility to find shortest path using Dijkstra
 *
 * @graph: pointer to graph to go through
 * @distance: array of distances from start vertex
 * @visited: keeps track of which vertices have been visited
 * @path_via: keeps track of path_via nodes for each vertex
 * @start: pointer to starting vertex
 * @target: pointer to target vertex
 * @idx: pointer to current index
 *
 * Return: queue of shortest path or NULL
 */
void recursive_dijkstra(graph_t *graph, size_t *distance, size_t *visited,
							vertex_t **path_via, vertex_t const *start,
							vertex_t const *target, size_t idx)
{
	vertex_t *current;
	edge_t *edge;
	size_t i = 0, temp;

	current = get_min_distance(graph, distance, visited, &idx);
	if (!current)
		return;

	printf("Checking %s, distance from %s is %ld\n", current->content,
			start->content, distance[current->index]);
	i = current->index;
	edge = current->edges;
	while (edge && visited[i] == 0)
	{
		temp = distance[i] + edge->weight;
		if (distance[edge->dest->index] > temp)
		{
			distance[edge->dest->index] = distance[i] + edge->weight;
			path_via[edge->dest->index] = current;
		}
		edge = edge->next;
	}
	visited[i] = 1;
	if (visited[target->index] == 1)
		return;

	recursive_dijkstra(graph, distance, visited, path_via, start, target, idx);
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
	size_t i, *distance = 0, *visited = 0;
	queue_t *queue = NULL;
	vertex_t **path_via = NULL;

	if (!graph || !start || !target)
		return (NULL);

	visited = calloc(graph->nb_vertices, sizeof(*visited));
	if (!visited)
		return (NULL);
	path_via = calloc(graph->nb_vertices, sizeof(**path_via));
	if (!path_via)
	{
		free(visited);
		return (NULL);
	}
	distance = malloc(graph->nb_vertices * sizeof(*distance));
	if (!distance)
	{
		free(visited);
		free(path_via);
		return (NULL);
	}
	for (i = 0; i < graph->nb_vertices; i++)
		distance[i] = ULONG_MAX;

	queue = queue_create();
	distance[start->index] = 0;
	recursive_dijkstra(graph, distance, visited, path_via, start, target, 0);

	insert_into_queue(graph, queue, path_via, start, target);
	free(visited);
	free(distance);
	free(path_via);
	if (!queue->front)
	{
		free(queue);
		return (NULL);
	}
	return (queue);
}
