/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanje <juanje@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:30:05 by jadalid-          #+#    #+#             */
/*   Updated: 2025/04/14 17:15:54 by juanje           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../minilibx-linux/mlx.h"

int	handle_input(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
	{
		printf("The %d key (ESC) has been pressed\n\n", keysym);
		mlx_destroy_window(game->mlx_ptr, game->mlx_win);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		exit(1);
	}
	printf("The %d key (ESC) has been pressed\n\n", keysym);
	return (0);
}

int	main(void)
{
	t_game	game;

	game.mlx_ptr = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx_ptr, 600, 500, "So longo!");

	if (NULL == game.mlx_win)
	{
		mlx_destroy_display(game.mlx_win);
		free(game.mlx_ptr);
	}

	mlx_loop(game.mlx_ptr);

	mlx_key_hook(game.mlx_win, handle_input, &game);
	mlx_destroy_display(game.mlx_ptr);
	free(game.mlx_ptr);

}

