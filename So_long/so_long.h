/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadalid- <jadalid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:22:10 by jadalid-          #+#    #+#             */
/*   Updated: 2025/04/22 17:33:58 by jadalid-         ###   ########.fr       */
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

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_game
{
	void			*mlx_ptr;
	void			*mlx_win;
	int				x;
	int				y;
	t_player		*player;

}	t_game;

int	handle_input(int keysym, t_game *game);
int	check_argv(char *av, char *extension);


#endif