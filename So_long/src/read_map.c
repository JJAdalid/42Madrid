/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadalid- <jadalid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:16:50 by jadalid-          #+#    #+#             */
/*   Updated: 2025/05/09 12:54:13 by jadalid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


int	ft_count_rows(char *filename)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	while ((line = get_next_line(fd)))
	{
		i++;
		free(line);
	}
	close(fd);
	return (i);
}



void	read_file(char *filename, t_game *game)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	game->rows = ft_count_rows(filename);
	if (game->rows <= 0)
		ft_error("Error al leer el archivo", &game);
	game->map = malloc(sizeof(char *) * (game->rows + 1));
	if (!game->map)
		ft_error("Error al lojar memoria", &game);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error("Error al abrir el arcvhivo", &game);
	while ((line = get_next_line(fd)))
		game->map[i++] = line;
	game->map[i] = NULL;
	game->cols = ft_strlen(game->map[0]) - 1;
	close(fd);
	validate_map(game);
	pos_elements(&game);
	game->win_width = game->cols * 64;
	game->win_height = game->rows * 64;
}

void	count_elements(t_game *game, int x, int y)
{
	char	c;

	c = game->map[y][x];

	if (c == 'P')
	{
		game->player_x = x;
		game->player_y = y;
		game->p_found++;
	}
	else if (c == 'E')
	{
		game->exit_x = x;
		game->exit_y = y;
		game->e_found++;
	}
	else if (c == 'C')
		game->collectibles++;
}

void	pos_elements(t_game *game)
{
	int	x;
	int	y;

	game->p_found = 0;
	game->e_found = 0;
	game->collectibles = 0;
	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->cols)
		{
			count_elements(game, x, y);
			x++;
		}
		y++;
	}
	if (game->p_found != 1 || game->e_found != 1)
		ft_error("Debe haber un solo jugador y una sola salida\n", game);
}

