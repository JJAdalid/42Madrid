/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadalid- <jadalid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:25:04 by juanje            #+#    #+#             */
/*   Updated: 2025/03/07 13:02:35 by jadalid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
//<stdin.h> uintptr_t para punteros!

void		ft_putchar(int c, size_t *count);
void		ft_putstr(const char *str, size_t *count);
void		ft_putnbr(int n, size_t	*count);
void		ft_type_format(char c, va_list args, size_t *count);
int			ft_printf(const char *str, ...);

#endif
