#include "graphs.h"

/**
 * graph_add_edge - adds an edge between two vertices to an existing graph
 *
 * @graph: pointer to graph to add edge to
 * @src: string identifying the vertex to make the connection
 * @dest: string identifying the vertex to connect to
 * @type: type of edge (unidirectional / bidirectional)
 *
 * Return: 1 on success, 0 on failure
 *
 * typedef struct edge_s {
 *	vertex_t		*dest;
 *	struct edge_s	*next;
 * } edge_t
 *
 */
int graph_add_edge(graph_t *graph, const char *src, const char *dest,
				   edge_type_t type)
{
	edge_t *src_edge, *dest_edge;
	vertex_t *src_vertex, *dest_vertex;

	if (!graph || !src || !dest)
		return (0);

	src_vertex = check_if_in_graph(graph, src);
	dest_vertex = check_if_in_graph(graph, dest);
	if (!src_vertex || !dest_vertex ||
		(type != UNIDIRECTIONAL && type != BIDIRECTIONAL))
		return (0);

	src_edge = malloc(sizeof(*src_edge));
	if (!src_edge)
		return (0);
	add_edge_to_vertex(src_vertex, dest_vertex, src_edge);
	if (type == BIDIRECTIONAL)
	{
		dest_edge = malloc(sizeof(*dest_edge));
		if (!dest_edge)
		{
			free(src_edge);
			return (0);
		}
		add_edge_to_vertex(dest_vertex, src_vertex, dest_edge);
	}
	return (1);
}

/**
 * add_edge_to_vertex - adds edge to end of edges list of vertex
 * @src: vertex to add to
 * @dest: destination vertex for edge
 * @edge: edge to add
 * Return: 1 on success, 0 on failure
 */
int add_edge_to_vertex(vertex_t *src, vertex_t *dest, edge_t *edge)
{
	edge_t *vertex_edge;

	if (src->nb_edges > 0)
		vertex_edge = find_last_edge(src->edges);
	edge->dest = dest;
	edge->next = NULL;
	if (src->nb_edges == 0)
		src->edges = edge;
	else
		vertex_edge->next = edge;
	src->nb_edges++;
	return (1);
}

/**
 * check_if_in_graph - checks if vertex exists in graph
 * @graph: graph to check
 * @string: string that defines vertex
 * Return: pointer to vertex if true, NULL on false
 */
vertex_t *check_if_in_graph(graph_t *graph, const char *string)
{
	vertex_t *vertex;

	vertex = graph->vertices;
	while (vertex)
	{
		if (!strcmp(vertex->content, string))
		{
			return (vertex);
		}
		if (vertex->next)
		{
			vertex = vertex->next;
		}
		else
		{
			break;
		}
	}
	return (NULL);
}

/**
 * find_last_edge - finds last edge in linked list of edges
 * @edges: list of edges in vertex to loop through
 * Return: pointer to last edge
 */
edge_t *find_last_edge(edge_t *edges)
{
	edge_t *edge;

	edge = edges;
	while (edge && edge->next)
		edge = edge->next;

	return (edge);
}
