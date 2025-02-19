/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanje <juanje@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:18:43 by jadalid-          #+#    #+#             */
/*   Updated: 2025/02/19 15:05:17 by juanje           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//Funcion que se encarga de liberar memoria.
char	*ft_free(char **buffer)
{
	free(*buffer);
	*buffer = NULL;
	return (NULL);
}

//Funcion que se encarga de limpiar buffer
char	*ft_upload_buffer(char *buffer)
{
	char	*new_buffer;
	char	*pos;
	int		len;

	pos = ft_strchr(buffer, '\n');
	if (!pos)
		return (ft_free(&buffer));
	len = ft_strlen(pos + 1);
	new_buffer = ft_substr(buffer, pos - buffer + 1, len);
	ft_free(&buffer);
	if (!new_buffer || *new_buffer == '\0')
		return (ft_free(&new_buffer));
	return (new_buffer);
}

//Lee el buffer hassta '\n' si lo hay y devuelve linea
char	*ft_getline(char *buffer)
{
	char	*result;
	char	*pos;
	int		len;

	pos = ft_strchr(buffer, '\n');
	if (pos)
		len = (pos - buffer) + 1;
	else
		len = ft_strlen(buffer);
	result = ft_substr(buffer, 0, len);
	if (!result)
		return (NULL);
	return (result);
}

//Funcion que lee el fd y guardaen buffer y lo leemos hasta encontrar el '\n'
char	*ft_readfile(int fd, char *buffer)
{
	char	*temp_buff;
	int		by_read;

	by_read = 1;
	if (!buffer)
		buffer = ft_calloc(sizeof(char), 1);
	temp_buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp_buff)
		return (ft_free(&buffer));
	while (by_read > 0 && !ft_strchr(buffer, '\n'))
	{
		by_read = read(fd, temp_buff, BUFFER_SIZE);
		if (by_read == -1)
		{
			free(temp_buff);
			return (ft_free(&buffer));
		}
		if (by_read == 0)
			break ;
		temp_buff[by_read] = '\0';
		buffer = ft_strjoin(buffer, temp_buff);
	}
	free(temp_buff);
	if (*buffer == '\0')
		return (ft_free(&buffer));
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_readfile(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_getline(buffer);
	if (!line)
		return (ft_free(&buffer));
	buffer = ft_upload_buffer(buffer);
	return (line);
}
