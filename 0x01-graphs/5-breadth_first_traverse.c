#include "graphs.h"

/**
 * breadth_first_traverse - goes through graph using breadth-first algorithm
 * @graph: pointer to graph to traverse, starting from first vertex in list
 * @action: pointer to function to be called for each visited vertex
 * Return: biggest vertex depth, or 0 on failure
 */
size_t breadth_first_traverse(const graph_t *graph, void (*action)
	(const vertex_t *v, size_t depth))
{
	size_t max_depth = 0;

	if (!graph || !action)
		return (0);
			
	visited = calloc(graph->nb_vertices, sizeof(*visited));
	if (!visited)
		return (0);
	max_depth = dfs(graph->vertices, action, visited, 0, &max_depth);
	free(visited);
	return (max_depth);
}

/**
 * bfs - breadth-first search on graph
 * @vertex: vertex node to perform search
 * @action: pointer to function to be called for each visited vertex
 * @visited: boolean
 * @depth: current depth
 * @max_depth: max_depth
 * Return: max_depth or 0 on failure
 */
size_t bfs(vertex_t *vertex, void (*action)(const vertex_t *v, size_t depth),
		int *visited, size_t depth, size_t *max_depth)
{
	queue_t *queue;

	queue = calloc(1, sizeof(*queue));
	if (!queue)
		return (0);
	depth = 1;
	push_to_queue(queue, vertex);
	visited[vertex->index] = 1;

	while (queue)
	{
	}
	return (max_depth);
}
		
/**
 * push_to_queue - pushes vertex to queue
 * @queue: pointer to queue
 * @vertex: vertex to push
 */
void push_to_queue(queue_t *queue, vertex_t *vertex)
{
	queue_t *new = malloc(sizeof(*new));
	if (!new)
		return;

	new->head = vertex;
	new->tail = NULL;
	if (!queue->tail)
		queue->head = new;
	else
		queue->tail = new;

	queue->size++;
}


/**
 * pop_from_queue - deletes vertex from queue
 * @queue: queue to delete from
 * @vertex: vertex to delete
 * @depth: depth of vertex
 */
vertex_t pop_from_queue(queue_t **queue, vertex_t *vertex)
{
	queue_t *temp;

	if (!queue)
		return (NULL);

	temp = *queue;
	*queue = (*queue)->next;
	vertex = temp->;
	queue->size = 0;
	return (*vertex);
}
