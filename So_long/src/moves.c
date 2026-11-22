/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadalid- <jadalid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:59:19 by jadalid-          #+#    #+#             */
/*   Updated: 2025/05/22 11:28:37 by jadalid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	redraw_last_tile(t_game *game, int last_x, int last_y)
{
	if (game->map[last_y][last_x] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
			game->object->exit,
			last_x * 64, last_y * 64);
	else
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
			game->object->floor,
			last_x * 64, last_y * 64);
}

static void	is_collectable(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'C')
	{
		game->collected++;
		game->map[new_y][new_x] = '0';
	}
}

static int	is_exit_and_win(t_game *game, int new_x, int new_y)
{
	return (game->map[new_y][new_x] == 'E'
		&& game->collected == game->collectibles);
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (game->map[new_y][new_x] == '1')
		return ;
	redraw_last_tile(game, game->player_x, game->player_y);
	is_collectable(game, new_x, new_y);
	if (is_exit_and_win(game, new_x, new_y))
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
			game->object->exit,
			new_x * 64, new_y * 64);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, \
			game->object->player,
			new_x * 64, new_y * 64);
		ft_printf("¡Has ganado en %d movimientos!\n", game->moves + 1);
		close_window(game);
	}
	game->player_x = new_x;
	game->player_y = new_y;
	ft_printf("Te has movido: %d veces!\n", ++game->moves);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->object->player,
		new_x * 64, new_y * 64);
}

int	handle_key(int keysym, t_game *game)
{
	if (keysym == ESC)
		close_window(game);
	else if (keysym == UP_ARROW || keysym == W_KEY)
		move_player(game, 0, -1);
	else if (keysym == DOWN_ARROW || keysym == S_KEY)
		move_player(game, 0, 1);
	else if (keysym == LEFT_ARROW || keysym == A_KEY)
		move_player(game, -1, 0);
	else if (keysym == RIGHT_ARROW || keysym == D_KEY)
		move_player(game, 1, 0);
	return (0);
}
