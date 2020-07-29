#ifndef __PATHFINDING_H__
#define __PATHFINDING_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include "graphs.h"
#include "queues.h"

#define NUM_DIRECTIONS 4
#define h(x1, y1, x2, y2)  (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)))

/**
 * enum direction_s - which way to go
 * @RIGHT: go east
 * @BOTTOM: go down
 * @LEFT: go west
 * @TOP: go up
 */
enum direction_s
{
	RIGHT,
	BOTTOM,
	LEFT,
	TOP
};

/**
 * struct point_s - Structure storing coordinates
 *
 * @x: X coordinate
 * @y: Y coordinate
 */
typedef struct point_s
{
	int x;
	int y;
} point_t;


queue_t *backtracking_array(char **map, int rows, int cols,
							point_t const *start, point_t const *target);

queue_t *backtracking_graph(graph_t *graph, vertex_t const *start,
							vertex_t const *target);
queue_t *dijkstra_graph(graph_t *graph, vertex_t const *start,
						vertex_t const *target);
queue_t *a_star_graph(graph_t *graph, vertex_t const *start,
					  vertex_t const *target);

#endif /* __PATHFINDING_H__ */
