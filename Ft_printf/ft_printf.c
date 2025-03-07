/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadalid- <jadalid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:48:24 by juanje            #+#    #+#             */
/*   Updated: 2025/03/07 13:25:25 by jadalid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_format(char c, va_list args, size_t *count)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (c == 'd')
			ft_putnbr(va_arg(args, int), count);
	/* else if (*str == 'p')
		ft_printptr(va_arg(args, void *), count);
	else if (*str == 'd' || *str == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (*str == 'u')
		ft_print.....
	else if (*str == 'x')
		ft_print.... */
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
			write(1, str, 1);
			count++;
			str++;
		}
	}
	va_end(args);
	return (count);
}
