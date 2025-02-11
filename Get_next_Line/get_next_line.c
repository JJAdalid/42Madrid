/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadalid- <jadalid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:18:43 by jadalid-          #+#    #+#             */
/*   Updated: 2025/02/11 17:38:40 by jadalid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//variable estatica que vaya guardando todo lo que vamos leyendo y asi saber por donde vamos.
//recibimos el fd y lo leemos hasta encontrar el '\n'

//Funcion que se encarga de liberar memoria.

//Funcion que lee el buffeer y lo copia en linea para retornar la linea a imprimir
char	*ft_getline(char *buffer)
{
	char	*result;
	char	*pos;
	int		len;

	pos = ft_strchr(buffer, '\n');
	len = (pos - buffer) + 1;
	result = ft_substr(buffer, 0, len);
	if (!result)
		return (0);
	return (result);
}

//Funcion que recibe el fd y el buffeer , lo lee y devuelve
char	*ft_readfile(int fd, char *buffer)
{
	char	*temp_buff;
	int		by_read;

	by_read = 1;
	temp_buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));

	while (by_read > 0 && !ft_strchr(buffer, '\n'))
	{
		by_read = read(fd, temp_buff, BUFFER_SIZE);
		if (by_read > 0)
		{
			temp_buff[by_read] = '\0';
			buffer = ft_strjoin(buffer, temp_buff);
		}
	}
	free(temp_buff);
	if (by_read == -1)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
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
	line = ft_getline(buffer);
	if (!line)
		return (NULL);
	//hacer que lo de buffer se libere para guardar la nueva line si la hay
	
	return (line);
}
