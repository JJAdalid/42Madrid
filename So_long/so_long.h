/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadalid- <jadalid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:22:10 by jadalid-          #+#    #+#             */
/*   Updated: 2025/04/30 17:17:51 by jadalid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include "./minilibx-linux/mlx_int.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <X11/keysym.h>

# define ESC 65307
# define UP_ARROW 65362
# define DOWN_ARROW 65364
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100

typedef struct s_object
{
	void	*player;
	void	*collectable;
	void	*wall;
	void	*exit;
	void	*floor;
}	t_object;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*mlx_win;
	int			x;
	int			y;
	char		**map;
	int			rows;
	int			cols;
	int			win_width;
	int			win_height;
	int			player_x;
	int			player_y;
	int			exit_x;
	int			exit_y;
	int			collectibles;
	int			collected;
	int			moves;
	t_object	object;
}	t_game;

int		handle_input(int keysym, t_game *game);
int		check_argv(char *av, t_game *game);
void	read_file(char *filename, t_game *game);
void	close_window(t_game *game);
#endif