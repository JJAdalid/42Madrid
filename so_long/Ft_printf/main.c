/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadalid- <jadalid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:49:11 by jadalid-          #+#    #+#             */
/*   Updated: 2025/03/17 13:14:26 by jadalid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

//gcc -o test main.c -L. -lftprintf

int main()
{
    int count, count2, count3, count4;
    int x = 0;
    count = ft_printf("Hello, world! %c %s %d %p\n", 48, "Test1", 42,(void*)&x);
    count2 = printf("Hello, world! %c %s %d %p\n", 48, "Test2", 42, (void*)&x);
    count3 = ft_printf("Characters printed: %q no comprendo\n");
    count4 = printf("Characters printed: %q no comprendo\n");
    printf("Characters printed: %d\n", count2);
    ft_printf("Characters printed: %d\n", count);
    ft_printf("Characters printed: %d\n", count3);
    printf("Characters printed: %d\n", count4);
    return 0;
}