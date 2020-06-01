#include "graphs.h"

/**
 * graph_add_vertex - adds a vertex to an existing graph
 * @graph: graph to add vertex to
 * @str: string to store in new vertex
 *
 * struct vertex_s {
 *	size_t		index;		<-- index of the vertex in adjacency list
 *	char		*content;	<-- custom data stored in the vertex
 *  size_t		nb_edges;	<-- number of connections with other vertices
 *  edge_t		*edges;		<-- pointer to head node of edges linked-list
 *	vertex_s	*next;		<-- pointer to next vertex in the graph
 *}
 *
 * Return: pointer to created vertex or NULL on failure
 */
vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{
	vertex_t *graph_vertex, *new_vertex;

	if (!graph || !str)
		return (NULL);
	new_vertex = malloc(sizeof(vertex_t));
	if (!new_vertex)
		return (NULL);
	graph_vertex = graph->vertices;
	while (graph_vertex)
	{
		if (!strcmp(graph_vertex->content, str))
			return (NULL);
		if (graph_vertex->next)
			graph_vertex = graph_vertex->next;
		else
			break;
	}
	graph->nb_vertices++;
	if (!graph_vertex)
	{
		graph->vertices = new_vertex;
		new_vertex->index = 0;
	}
	else
	{
		graph_vertex->next = new_vertex;
		new_vertex->index = graph_vertex->index + 1;
	}
	new_vertex->content = strdup(str);
	if (!new_vertex->content)
	{
		free(new_vertex);
		return (NULL);
	}
	new_vertex->nb_edges = 0;
	new_vertex->edges = NULL;
	new_vertex->next = NULL;
	return (new_vertex);
}
