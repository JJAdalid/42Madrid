/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadalid- <jadalid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:32:17 by jadalid-          #+#    #+#             */
/*   Updated: 2025/05/23 15:19:02 by jadalid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_rectangular(t_game *game)
{
	int		i;
	int		len;

	i = 0;
	while (i < game->rows)
	{
		len = ft_strlen(game->map[i]);
		if (game->map[i][len - 1] == '\n')
			len--;
		if (len != game->cols)
			return (0);
		i++;
	}
	return (1);
}

int	check_walls(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->cols)
	{
		if (game->map[0][x] != '1' || game->map[game->rows - 1][x] != '1')
			return (0);
		x++;
	}
	y = 1;
	while (y < game->rows - 1)
	{
		if (game->map[y][0] != '1' || game->map[y][game->cols - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	check_elements(t_game *game, int p_found, int e_found, int c_found)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->cols)
		{
			if (game->map[y][x] == 'P')
				p_found++;
			else if (game->map[y][x] == 'E')
				e_found++;
			else if (game->map[y][x] == 'C')
				c_found++;
			else if (game->map[y][x] != '1' && game->map[y][x] != '0' &&
					game->map[y][x] != '\n')
				return (0);
			x++;
		}
		y++;
	}
	if (p_found != 1 || e_found < 1 || c_found < 1)
		return (0);
	return (1);
}

void	validate_map(t_game *game)
{
	if (!check_walls(game))
		ft_error("El mapa no esta rodeado de muros", game);
	if (!check_elements(game, 0, 0, 0))
		ft_error("El mapa no contiene los elementos necesarios", game);
	if (!check_possible(game, 'C') || !check_possible(game, 'E'))
		ft_error("El player no puede llegar a todas las monedas o la salida", \
			game);
}
