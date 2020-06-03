#include "graphs.h"

/**
 * graph_delete - completely deletes a graph
 * @graph: graph to delete
 */
void graph_delete(graph_t *graph)
{
	vertex_t *temp;

	if (!graph)
		return;

	while (graph->vertices)
	{
		temp = graph->vertices;
		graph->vertices = graph->vertices->next;
		delete_edge(temp->edges);
		free(temp->content);
		free(temp);
	}
	free(graph);
}

/**
 * delete_edge - deletes edges from a vertex
 * @edges: pointer to list of edges to delete
 */
void delete_edge(edge_t *edges)
{
	edge_t *temp;

	if (!edges)
		return;

	while (edges)
	{
		temp = edges;
		edges = edges->next;
		free(temp);
	}
}
