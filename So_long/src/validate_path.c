/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadalid- <jadalid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:51:21 by jadalid-          #+#    #+#             */
/*   Updated: 2025/05/23 12:55:20 by jadalid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	**create_visited(t_game *game)
{
	int	**visited;
	int	i;
	int	j;

	i = 0;
	visited = malloc(sizeof(int *) * game->rows);
	if (!visited)
		return (NULL);
	while (i < game->rows)
	{
		visited[i] = malloc(sizeof(int) * game->cols);
		if (!visited[i])
			return (NULL);
		j = 0;
		while (j < game->cols)
		{
			visited[i][j] = 0;
			j++;
		}
		i++;
	}
	return (visited);
}

static void	free_visited(int **visited, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

static void	flood_fill(int x, int y, t_game *game, int **visited)
{
	if (x < 0 || x >= game->cols || y < 0 || y >= game->rows)
		return ;
	if (game->map[y][x] == '1' || visited[y][x])
		return ;
	visited[y][x] = 1;
	flood_fill(x + 1, y, game, visited);
	flood_fill(x - 1, y, game, visited);
	flood_fill(x, y + 1, game, visited);
	flood_fill(x, y - 1, game, visited);
}

int	check_possible(t_game *game, char object)
{
	int	**visited;
	int	found;
	int	y;
	int	x;

	visited = create_visited(game);
	found = 1;
	flood_fill(game->player_x, game->player_y, game, visited);
	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->cols)
		{
			if (game->map[y][x] == object && !visited[y][x])
				found = 0;
			x++;
		}
		y++;
	}
	free_visited(visited, game->rows);
	return (found > 0);
}
