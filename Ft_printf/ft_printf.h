/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanje <juanje@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:25:04 by juanje            #+#    #+#             */
/*   Updated: 2025/03/12 16:00:22 by juanje           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
//<stdin.h> uintptr_t para punteros!

size_t		ft_strlen(const char *str);
void		ft_putchar(int c, size_t *count);
void		ft_putstr(const char *str, size_t *count);
void		ft_putnbr(int n, size_t	*count);
void		ft_type_format(char c, va_list args, size_t *count);
void		ft_putnbr_base(unsigned long n, char *base, size_t *count);
void		ft_put_ptr(void *ptr, size_t *count);
int			ft_printf(const char *str, ...);

#endif
