/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadalid- <jadalid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:48:24 by juanje            #+#    #+#             */
/*   Updated: 2025/03/06 17:07:41 by jadalid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_type_format(const char *str, va_list args, size_t *count)
{
	if (*str == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (*str == 's')
		ft_putstr(va_arg(args, char *), count);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	size_t		count;

	if (!str)
		return (0);
	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_type_format(*str, args, &count);

		}
		else
		{
			write(1, &str, 1);
			count++;
			str++;
		}
	}
	va_end(args);
	return (count);
}
