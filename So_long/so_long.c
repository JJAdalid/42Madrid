/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadalid- <jadalid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:30:05 by jadalid-          #+#    #+#             */
/*   Updated: 2025/05/27 12:18:02 by jadalid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../minilibx-linux/mlx.h"

int	check_argv(char *av)
{
	int	len;

	len = ft_strlen(av);
	if (len > 4 && av[len - 4] == '.' && av[len - 3] == 'b'
		&& av[len - 2] == 'e' && av[len - 1] == 'r')
		return (1);
	else
		return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		ft_error("Número de argumentos inválido\n", &game);
	if (!check_argv(av[1]))
		ft_error("El mapa debe tener extensión .ber\n", &game);
	ft_bzero(&game, sizeof(t_game));
	read_file(av[1], &game);
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		ft_error("mlx_init falló", &game);
	game.mlx_win = mlx_new_window(game.mlx_ptr, game.win_width, \
					game.win_height, "So longo!");
	if (!game.mlx_win)
		ft_error("mlx_new_window falló", &game);
	load_sprites(&game);
	draw_map(&game);
	mlx_hook(game.mlx_win, 17, 1L << 2, close_window, &game);
	mlx_key_hook(game.mlx_win, handle_key, &game);
	mlx_loop(game.mlx_ptr);
	free_game(&game);
}
