/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadalid- <jadalid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:16:50 by jadalid-          #+#    #+#             */
/*   Updated: 2025/04/22 17:43:49 by jadalid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


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

