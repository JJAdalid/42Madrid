/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadalid- <jadalid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:19:16 by jadalid-          #+#    #+#             */
/*   Updated: 2025/03/07 13:18:08 by jadalid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(int c, size_t *count)
{
	write (1, &c, 1);
	(*count)++;
}

void	ft_putstr(const char *str, size_t *count)
{
	if (!str)
	{
		write(1, "ERROR", 5);
		(*count) += 5;
		return ;
	}
	while (*str)
	{
		write (1, str, 1);
		str++;
		(*count)++;
	}
}
