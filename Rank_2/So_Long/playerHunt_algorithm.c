/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerHunt_algorithm.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lawences <lawences@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:35:58 by lawences          #+#    #+#             */
/*   Updated: 2024/10/15 16:35:59 by lawences         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 15
#define COLS 29
#define INF 1000000

typedef struct s_point {
	int	row;
	int	col;
}	t_point;

typedef struct s_node {
	t_point pos;
	int g_cost;
	int f_cost;
}	t_node;

typedef struct s_priority_queue {
	t_node	nodes[ROWS * COLS];
	int		size;
}	t_priority_queue;

int		dir_row[] = {0, 1, 0, -1};
int		dir_col[] = {1, 0, -1, 0};

void	init_priority_queue(t_priority_queue *pq)
{
	pq->size = 0;
}

void	enqueue(t_priority_queue *pq, t_node node)
{
	int	i;
	t_node temp;

	pq->nodes[pq->size++] = node;
	i = pq->size - 1;
	while (i > 0 && pq->nodes[i].f_cost < pq->nodes[(i - 1) / 2].f_cost)
	{
		temp = pq->nodes[i];
		pq->nodes[i] = pq->nodes[(i - 1) / 2];
		pq->nodes[(i - 1) / 2] = temp;
		i = (i - 1) / 2;
	}
}

t_node	dequeue(t_priority_queue *pq)
{
	int		i;
	int		child;
	t_node	root;
	t_node	temp;

	root = pq->nodes[0];
	pq->nodes[0] = pq->nodes[--pq->size];
	i = 0;
	while (2 * i + 1 < pq->size)
	{
		child = 2 * i + 1;
		if (child + 1 < pq->size && pq->nodes[child + 1].f_cost < pq->nodes[child].f_cost)
			child++;
		if (pq->nodes[i].f_cost <= pq->nodes[child].f_cost)
			break ;
		temp = pq->nodes[i];
		pq->nodes[i] = pq->nodes[child];
		pq->nodes[child] = temp;
		i = child;
	}
	return (root);
}

bool	is_queue_empty(t_priority_queue *pq)
{
	return (pq->size == 0);
}

int	heuristic(t_point a, t_point b)
{
	return (abs(a.row - b.row) + abs(a.col - b.col));
}

bool	valid_move(char maze[ROWS][COLS], int new_row, int new_col)
{
	if (new_row >= 0 && new_row < ROWS && new_col >= 0 && new_col < COLS)
		if (maze[new_row][new_col] != '1')
			return (true);
	return (false);
}

bool	a_star(char maze[ROWS][COLS], t_point start, t_point *player_pos, t_point prev[ROWS][COLS])
{
	t_priority_queue	pq;
	int					g_cost[ROWS][COLS];
	bool				visited[ROWS][COLS] = {false};
	int					i, new_row, new_col, new_g_cost, h_cost, f_cost;
	t_node				curr_node;
	t_point				curr;

	init_priority_queue(&pq);
	for (i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
			g_cost[i][j] = INF;
	g_cost[start.row][start.col] = 0;
	enqueue(&pq, (t_node){start, 0, heuristic(start, *player_pos)});
	while (!is_queue_empty(&pq))
	{
		curr_node = dequeue(&pq);
		curr = curr_node.pos;
		if (maze[curr.row][curr.col] == 'P' || maze[curr.row][curr.col] == 'p')
		{
			*player_pos = curr;
			return (true);
		}
		visited[curr.row][curr.col] = true;
		for (i = 0; i < 4; i++)
		{
			new_row = curr.row + dir_row[i];
			new_col = curr.col + dir_col[i];
			if (valid_move(maze, new_row, new_col) && !visited[new_row][new_col])
			{
				new_g_cost = g_cost[curr.row][curr.col] + 1;
				if (new_g_cost < g_cost[new_row][new_col])
				{
					g_cost[new_row][new_col] = new_g_cost;
					h_cost = heuristic((t_point){new_row, new_col}, *player_pos);
					f_cost = new_g_cost + h_cost;
					prev[new_row][new_col] = curr;
					enqueue(&pq, (t_node){{new_row, new_col}, new_g_cost, f_cost});
				}
			}
		}
	}
	return (false);
}

void	print_maze_with_color(char maze[ROWS][COLS], t_point prev[ROWS][COLS], t_point start, t_point player_pos)
{
	char	path_marker[ROWS][COLS] = {0};
	t_point	at;
	int		i, j;

	at = player_pos;
	while (at.row != start.row || at.col != start.col)
	{
		path_marker[at.row][at.col] = 1;
		at = prev[at.row][at.col];
	}
	path_marker[start.row][start.col] = 1;
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			if (path_marker[i][j])
				printf("\033[1;31m%c\033[0m", maze[i][j]);
			else
				printf("%c", maze[i][j]);
		}
		printf("\n");
	}
}

int	read_maze(char maze[ROWS][COLS], const char *file_path, t_point *enemy_pos, t_point *player_pos)
{
	FILE	*file;
	char	line[COLS + 2];
	int		row = 0;

	file = fopen(file_path, "r");
	if (!file)
		return (0);
	while (fgets(line, sizeof(line), file) && row < ROWS)
	{
		for (int col = 0; col < COLS; col++)
		{
			maze[row][col] = line[col];
			if (line[col] == 'i')
				*enemy_pos = (t_point){row, col};
			if (line[col] == 'P' || line[col] == 'p')
				*player_pos = (t_point){row, col};
		}
		row++;
	}
	fclose(file);
	return (1);
}

int	main(int argc, char **argv)
{
	char	maze[ROWS][COLS];
	t_point	enemy_pos;
	t_point	player_pos;
	t_point	prev[ROWS][COLS];

	if (argc != 2)
	{
		printf("Usage: %s <map_file>\n", argv[0]);
		return (1);
	}
	if (!read_maze(maze, argv[1], &enemy_pos, &player_pos))
	{
		printf("Error reading map file.\n");
		return (1);
	}
	if (a_star(maze, enemy_pos, &player_pos, prev))
		print_maze_with_color(maze, prev, enemy_pos, player_pos);
	else
		printf("Player not found!\n");
	return (0);
}
