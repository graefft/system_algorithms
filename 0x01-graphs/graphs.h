#ifndef __GRAPHS_H__
#define __GRAPHS_H__


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * enum edge_type_e - Enumerates the different types of
 * connection between two vertices
 *
 * @UNIDIRECTIONAL: The connection is made only in one way
 * @BIDIRECTIONAL: The connection is made in two ways
 */
typedef enum edge_type_e
{
	UNIDIRECTIONAL = 0,
	BIDIRECTIONAL
} edge_type_t;


/* Define the structure temporarily for usage in the edge_t */
typedef struct vertex_s vertex_t;


/**
 * struct edge_s - Node in the linked list of edges for a given vertex
 * A single vertex can have many edges
 *
 * @dest: Pointer to the connected vertex
 * @next: Pointer to the next edge
 */
typedef struct edge_s
{
	vertex_t    *dest;
	struct edge_s   *next;
} edge_t;


/**
 * struct vertex_s - Node in the linked list of vertices in the adjency list
 *
 * @index: Index of the vertex in the adjency list.
 * @content: Custom data stored in the vertex (here, a string)
 * @nb_edges: Number of conenctions with other vertices in the graph
 * @edges: Pointer to the head node of the linked list of edges
 * @next: Pointer to the next vertex in the adgency linked list
 *   This pointer points to another vertex in the graph, but it
 *   doesn't stand for an edge between the two vertices
 */
struct vertex_s
{
	size_t      index;
	char        *content;
	size_t      nb_edges;
	edge_t      *edges;
	struct vertex_s *next;
};


/**
 * struct graph_s - Representation of a graph
 * We use an adjency linked list to represent our graph
 *
 * @nb_vertices: Number of vertices in our graph
 * @vertices: Pointer to the head node of our adjency linked list
 */
typedef struct graph_s
{
	size_t      nb_vertices;
	vertex_t    *vertices;
} graph_t;


/**
 * struct queue_s - doubly linked list representation of a stack (or queue)
 * @size: size of queue
 * @head: points to the first element of the stack (or queue)
 * @tail: points to the last element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct queue_s
{
        size_t size;
        struct queue_t *head;
        struct queue_t *tail;
} queue_t;


/*  0-graph_create.c  */
graph_t *graph_create(void);


/*  1-graph_add_vertex.c  */
vertex_t *graph_add_vertex(graph_t *graph, const char *str);


/*  2-graph_add_edge.c  */
int graph_add_edge(graph_t *graph, const char *src, const char *dest,
				   edge_type_t type);
int add_edge_to_vertex(vertex_t *src, vertex_t *dest, edge_t *edge);
vertex_t *check_if_in_graph(graph_t *graph, const char *string);
edge_t *find_last_edge(edge_t *edges);


/*  3-graph_delete.c  */
void graph_delete(graph_t *graph);
void delete_edge(edge_t *edges);


/*  4-depth_first_traverse.c  */
size_t depth_first_traverse(const graph_t *graph,
							void (*action)(const vertex_t *v, size_t depth));
void dfs(vertex_t *vertex, void (*action)(const vertex_t *v, size_t depth),
		 int *visited, size_t depth, size_t *max_depth);


/*  5-breadth_first_traverse.c  */
size_t breadth_first_traverse(const graph_t *graph,
							  void (*action)(const vertex_t *v, size_t depth));
size_t bfs(vertex_t *vertex, void (*action)(const vertex_t *v, size_t depth),
		 int *visited, size_t depth, size_t *max_depth);
void push_to_queue(queue_t *queue, vertex_t *vertex);
void pop_from_queue(queue_t *queue, vertex_t **vertex);

/*  graph_display  */
void graph_display(const graph_t *graph);


#endif /*__GRAPHS_H__*/
