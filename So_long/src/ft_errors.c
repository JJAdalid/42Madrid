/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadalid- <jadalid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:54:09 by jadalid-          #+#    #+#             */
/*   Updated: 2025/05/08 10:51:30 by jadalid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


void	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
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

void	ft_error(char *message, t_game *game)
{
	if (game)
		free_map(game);
	{
		if (game->mlx_win)
			mlx_destroy_window(game->mlx_ptr, game->mlx_win);
		if (game->mlx_ptr)
			mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	write(1, message, ft_strlen(message));
	exit(EXIT_FAILURE);
}
