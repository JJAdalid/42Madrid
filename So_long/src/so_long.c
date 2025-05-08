/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadalid- <jadalid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:30:05 by jadalid-          #+#    #+#             */
/*   Updated: 2025/05/08 17:07:07 by jadalid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../minilibx-linux/mlx.h"


int	check_argv(char *av, t_game *game)
{
	int	len;

	len = ft_strlen(av);
	if (len > 4 && av[len - 4] == '.' && av[len - 3] == 'b'
		&& av[len - 2] == 'e' && av[len - 1] == 'r')
		return (1);
	else
		return (0);
}

int	handle_input(int keysym, t_game *game)
{
	if (keysym == ESC)
	{
		printf("The %d key (ESC) has been pressed\n\n", keysym);
		close_window(game);
	}
	printf("The %d key has been pressed\n\n", keysym);

	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		ft_error("Número de argumentos inválido\n", NULL);
	if (!check_argv(av[1], &game))
		ft_error("El mapa debe tener extensión .ber\n", NULL);
	read_file(av[1], &game);
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		ft_error("mlx_init falló", &game);
	game.mlx_win = mlx_new_window(game.mlx_ptr, game.win_width, \
					game.win_height, "So longo!");
	if (!game.mlx_win)
		free(game.mlx_ptr);
	mlx_hook(game.mlx_win, 17, 1L << 2, close_window, &game);
	mlx_key_hook(game.mlx_win, handle_input, &game);
	mlx_loop(game.mlx_ptr);
	mlx_destroy_display(game.mlx_ptr);
	free(game.mlx_ptr);
}
