/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadalid- <jadalid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:30:05 by jadalid-          #+#    #+#             */
/*   Updated: 2025/04/22 17:43:05 by jadalid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../minilibx-linux/mlx.h"

void close_window(t_game *game)
{
	
}

int	handle_input(int keysym, t_game *game)
{
	if (keysym == ESC)
	{
		printf("The %d key (ESC) has been pressed\n\n", keysym);
		mlx_destroy_window(game->mlx_ptr, game->mlx_win);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		exit(1);
	}
	printf("The %d key has been pressed\n\n", keysym);

	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		write(1, "Number of argmunts invalid", 26);
		exit(EXIT_FAILURE);
	}
	if (!check_argv(av[1], game))
		exit(EXIT_FAILURE);
	game.mlx_ptr = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx_ptr, 600, 500, "So longo!");

	if (NULL == game.mlx_win)
	{
		mlx_destroy_display(game.mlx_win);
		free(game.mlx_ptr);
	}

	mlx_hook(game.mlx_win, 17, 0, close_window, &game);
	mlx_key_hook(game.mlx_win, handle_input, &game);
	mlx_loop(game.mlx_ptr);
	mlx_destroy_display(game.mlx_ptr);
	free(game.mlx_ptr);

}
