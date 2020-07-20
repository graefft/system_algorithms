#include "pathfinding.h"

/**
 * isValid - checks if position is ok to go to and hasn't been visited
 * @map: 2d array to explore (0 is walkable, 1 is blocked)
 * @visited: array that keeps track of where we've been
 * @x: x coordinate of position to check
 * @y: y coordinate of position to check
 * @rows: number of rows
 * @cols: number of columns
 * Return: 1 if it's safe, 0 if not
 */
int isValid(char **map, int **visited, int x, int y, int rows, int cols)
{
	if (x < 0 || y < 0 || x >= cols || y >= rows)
		return (0);
	else if (map[y][x] == '1' || visited[y][x] == 1)
		return (0);
	else
		return (1);
}

/**
 * initialize_arrays - creates path queue, visited map, array of directions
 *
 * @path: path queue
 * @visited: pointer to visited 2d array
 * @direction: array of directions
 * @rows: number of rows
 * @cols: number of columns
 *
 * Return: 0 on success, -1 on failure
 */
int initialize_arrays(queue_t **path, int ***visited, point_t *direction,
					  int rows, int cols)
{
	int i;

	*path = queue_create();
	if (*path == NULL)
		return (-1);

	*visited = malloc(rows * sizeof(**visited));
	if (*visited == NULL)
		return (-1);
	for (i = 0; i < rows; i++)
	{
		(*visited)[i] = calloc(cols, sizeof(**visited));
		if ((*visited)[i] == NULL)
			return (-1);
	}

	direction[BOTTOM].x = 0, direction[BOTTOM].y = 1;
	direction[RIGHT].x = 1, direction[RIGHT].y = 0;
	direction[LEFT].x = -1, direction[LEFT].y = 0;
	direction[TOP].x = 0, direction[TOP].y = -1;
	return (0);
}

/**
 * update_path - adds point to queue
 *
 * @path: current queue
 * @x: current x coordinate
 * @y: current y coordinate
 *
 * Return: 1 on success, 0 on failure
 */
int update_path(queue_t **path, int x, int y)
{
	point_t *current;

	current = malloc(sizeof(*current));
	if (!current)
		return (0);
	current->x = x;
	current->y = y;

	queue_push_front(*path, current);
	return (1);
}

/**
 * recursive_backtracking_array - recursive backingtracking function
 *
 * @map: pointer to given 2D array to explore (0 is walkable, 1 is blocked
 * @visited: pointer to 2d array of coordinates visited
 * @x: current x coordinate
 * @y: current y coordinate
 * @target: target coordinates
 * @path: solution queue
 * @directions: array of possible directions to travel
 * @rows: number of rows
 * @cols: number of columns
 *
 * Return: 1 on success, 0
 */
int recursive_backtrack(char **map, int **visited, int x, int y,
						 point_t const *target, queue_t **path,
						 point_t *directions, int rows, int cols)
{
	int i;

	/* CHECK IF COORDINATES ARE VALID */
	if (isValid(map, visited, x, y, rows, cols) == 0)
		return (0);

	printf("Checking coordinates [%d, %d]\n", x, y);

	if (x == target->x && y == target->y)
		return (update_path(path, x, y));

	/* MARK VISITED */
	visited[y][x] = 1;

	/* CHECK EACH DIRECTION */
	for (i = 0; i < NUM_DIRECTIONS; i++)
	{
		if (recursive_backtrack(map, visited, x + directions[i].x,
			y + directions[i].y, target, path, directions, rows, cols) == 1)
			return (update_path(path, x, y));
	}
	return (0);
}
/**
 * backtracking_array - searches for first path from starting point to target
 *						within a two-dimensional array
 * @map: pointer to read-only 2D array (0 is walkable, 1 is blocked cell)
 * @rows: number of rows
 * @cols: number of columns
 * @start: coordinates of starting point
 * @target: coordinates of ending point
 *
 * Return: queue in which each node is a point in the path from start to end
 */
queue_t *backtracking_array(char **map, int rows, int cols,
							point_t const *start, point_t const *target)
{
	int **visited;
	int i, itWorked;
	queue_t *path;
	point_t directions[NUM_DIRECTIONS];

	if (!map || !*map || rows <= 0 || cols <= 0 || !start || !target)
		return (NULL);

	if (initialize_arrays(&path, &visited, directions, rows, cols) == -1)
		return (NULL);

	itWorked = (recursive_backtrack(map, visited, start->x, start->y,
							target, &path, directions, rows, cols));

	for (i = 0; i < rows; i++)
		free(visited[i]);
	free(visited);

	if (itWorked)
		return (path);

	else
	{
		queue_delete(path);
		return (NULL);
	}
}

