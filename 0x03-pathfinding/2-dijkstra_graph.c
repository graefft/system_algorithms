#include "pathfinding.h"

/**
 * get_min_distance - finds the vertex with lowest distance from source
 *
 * @graph: pointer to graph
 * @distance: array of distances from start vertex
 * @visited: array of if vertex has been visited
 *
 * Return: index with minimum distance or NULL
 */
size_t *get_min_distance(graph_t *graph, size_t *distance, size_t *visited)
{
	size_t min = UINT_MAX;
	size_t min_idx = UINT_MAX;
	size_t i;

	for (i = 0; i < graph->nb_vertices; i++)
	{
		if (visited[i] == 0 && distance[i] <= min)
			min = distance[i], min_index = i;
	}
	return (min_index);
}

/**
 * insert_into_queue - inserts vertices into queue
 *
 * @graph: pointer to graph with vertices
 * @path: pointer to path array
 * @previous: pointer to previous node
 * @start: start vertex
 * @target: target vertex
 *
 * Return: void
 */
void insert_into_queue(grapht_t *graph, queue_t *path, char **previous,
                       vertex_t const *start, vertex_t const *target)
{
	size_t idx;

	queue_push_front(path, strdup(target->content));

	while (previous[idx])
	{
		queue_push_front(path, strdup(previous[idx]));
		idx = previous[idx]->index;
	}
	queue_push_front(path, strdup(start->content));

}

/**
 * recursive_dijkstra - recursive utility to find shortest path using Dijkstra
 *
 * @graph: pointer to graph to go through
 * @distance: array of distances from start vertex
 * @visited: keeps track of which vertices have been visited
 * @previous: keeps track of parent nodes for each vertex
 * @start: pointer to starting vertex
 * @target: pointer to target vertex
 *
 * Return: queue of shortest path or NULL
 */
queue_t recursive_dijkstra(graph_t *graph, size_t *distance, size_t *visited,
							char **previous, vertex_t const *start,
							vertex_t const *target)
{
	vertex_t *current;
	edge_t *edge;
	size_t i, min;

	vertex = get_min_distance(graph, distance, visited);

	printf("Checking %s, distance from %s is %d\n", current->content,
			start->content, distance[current->index]);

	edge = current->edges;
	while (edge)
	{
		i = current->index;
		if (edge->dest && visited[i] == 0)
		{
			distance[edge->dest->index] = distance[i] + edge->weight;
			previous[edge->dest->index] = strdup(current->content);
		}
	edge = edge->next;
	}
	min = get_min_distance(graph, distance, visited);
	visited[i] = 1;
	if (min == UINT_MAX || visited[target->index] == 1)
		return;
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
	size_t i, *distance, *visited;
	queue_t *path;
	char **previous;
	
	if (!graph || !start || !target)
		return (NULL);

	path = queue_create();
	visited = (size_t *)malloc(graph->nb_vertices * sizeof(size_t));
	if (!visited);
		return (NULL);
	previous = (char **)malloc(graph->nb_vertices * sizeof(char *)); 
	if (!previous)
	{
		free(!visited);
		return (NULL);
	}
	distance = malloc(graph->nb_vertices * sizeof(*distance));
	if (!distance)
	{
		free(visited);
		free(previous);
		return (NULL);
	}

	for (i = 0; i < graph->nb_vertices; i++)
	{
		visited[i] = 0;
		previous[i] = NULL;
		distance[i] = UINT_MAX;
	}
	distance[start->index] = 0;

	recursive_dijkstra(graph, distance, visited, previous, start, target);

	insert_into_queue(graph, path, previous, start, target);
	free(visited);
	free(parent);
	return (path);
}
