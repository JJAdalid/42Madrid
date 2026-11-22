/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadalid- <jadalid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:54:09 by jadalid-          #+#    #+#             */
/*   Updated: 2025/05/27 12:15:34 by jadalid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_window(t_game *game)
{
	free_game(game);
	exit(EXIT_SUCCESS);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->rows)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	free_game(t_game *game)
{
	if (game->object)
	{
		if (game->object->wall)
			mlx_destroy_image(game->mlx_ptr, game->object->wall);
		if (game->object->player)
			mlx_destroy_image(game->mlx_ptr, game->object->player);
		if (game->object->floor)
			mlx_destroy_image(game->mlx_ptr, game->object->floor);
		if (game->object->collectable)
			mlx_destroy_image(game->mlx_ptr, game->object->collectable);
		if (game->object->exit)
			mlx_destroy_image(game->mlx_ptr, game->object->exit);
		free(game->object);
	}
	if (game->mlx_ptr)
	{
		mlx_destroy_window(game->mlx_ptr, game->mlx_win);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	free_map(game);
}

void	ft_error(char *message, t_game *game)
{
	if (game)
		free_game(game);
	write(1, message, ft_strlen(message));
	exit(EXIT_FAILURE);
}
