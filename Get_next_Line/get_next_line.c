/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadalid- <jadalid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:18:43 by jadalid-          #+#    #+#             */
/*   Updated: 2025/02/10 17:02:20 by jadalid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//variable estatica que vaya guardando todo lo que vamos leyendo y asi saber por donde vamos.
//recibimos el fd y lo leemos hasta encontrar el '\n'

//Funcion que recibe el fd y el buffeer , lo lee y devuelve
char	*ft_readfile(int fd, char *buffer)
{
	char	*temp_buff;
	int		bytes_read;

	//validacines correspondientes
	bytes_read 
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if ((buffer && !ft_strchr(buffer, '\n')) || !buffer)
		buffer = ft_readfile(fd, buffer);
	if (!buffer)
		return (0);
	line = /* Funcion que me va dando linea por linea */
	return (line);
}
