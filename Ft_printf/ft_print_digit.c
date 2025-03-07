/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadalid- <jadalid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:49:20 by jadalid-          #+#    #+#             */
/*   Updated: 2025/03/07 13:04:27 by jadalid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, size_t	*count)
{
	char	num;

	if (n == -2147483648)
	{
		(*count) += write (1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		(*count) += 1;
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, count);
	}
	num = (n % 10) + '0';
	(*count) += write (1, &num, 1);
}
