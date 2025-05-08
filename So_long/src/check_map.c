/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadalid- <jadalid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:16:50 by jadalid-          #+#    #+#             */
/*   Updated: 2025/04/30 17:10:51 by jadalid-         ###   ########.fr       */
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
		ft_error("Error reading file", &game);
	game->map = malloc(sizeof(char *) * (game->rows + 1));
	if (!game->map)
		ft_error("Memory allocation error", &game);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error("Error opening file", &game);
	while ((line = get_next_line(fd)))
		game->map[i++] = line;
	game->map[i] = NULL;
	game->cols = ft_strlen(game->map[0]) - 1;
	validate_map(game);
	close(fd);
	game->win_width = game->cols * 64;
	game->win_height = game->rows * 64;
}
