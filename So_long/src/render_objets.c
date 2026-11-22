/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_objets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadalid- <jadalid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:49:51 by jadalid-          #+#    #+#             */
/*   Updated: 2025/05/23 15:19:02 by jadalid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_sprites(t_game *game)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	game->object = malloc(sizeof(t_object));
	if (!game->object)
		ft_error("Error: Game allocation failes", game);
	game->object->floor = mlx_xpm_file_to_image(game->mlx_ptr, \
		"sprites/floor.xpm", &w, &h);
	game->object->wall = mlx_xpm_file_to_image(game->mlx_ptr, \
		"sprites/wall.xpm", &w, &h);
	game->object->player = mlx_xpm_file_to_image(game->mlx_ptr, \
		"sprites/player_right.xpm", &w, &h);
	game->object->collectable = mlx_xpm_file_to_image(game->mlx_ptr, \
		"sprites/collectable.xpm", &w, &h);
	game->object->exit = mlx_xpm_file_to_image(game->mlx_ptr, \
		"sprites/arenero.xpm", &w, &h);
}

static void	draw_tile(t_game *game, int x, int y)
{
	void	*img;

	img = NULL;
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
		game->object->floor, x * 64, y * 64);
	if (game->map[y][x] == '1')
		img = game->object->wall;
	else if (game->map[y][x] == 'C')
		img = game->object->collectable;
	else if (game->map[y][x] == 'E')
		img = game->object->exit;
	if (img)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			img, x * 64, y * 64);
}

static void	draw_player_if_here(t_game *game, int x, int y)
{
	if (game->player_x == x && game->player_y == y)
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->object->player, x * 64, y * 64);
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->cols)
		{
			draw_tile(game, x, y);
			draw_player_if_here(game, x, y);
			x++;
		}
		y++;
	}
}
