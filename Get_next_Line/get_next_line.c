/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanje <juanje@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:18:43 by jadalid-          #+#    #+#             */
/*   Updated: 2025/02/18 16:27:47 by juanje           ###   ########.fr       */
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
	{
		new_buffer = NULL;
		return (ft_free(&buffer));
	}
	len = ft_strlen(buffer) - (pos - buffer + 1);
	new_buffer = ft_substr(buffer, pos - buffer + 1, len);
	ft_free(&buffer);
	return (new_buffer);
}

//Lee el buffer hassta '\n' si lo hay y devuelve linea
char	*ft_getline(char *buffer)
{
	char	*result;
	char	*pos;
	int		len;

	pos = ft_strchr(buffer, '\n');
	len = (pos - buffer) + 1;
	result = ft_substr(buffer, 0, len);
	if (!result)
	{
		return (NULL);
	}
	return (result);
}

//Funcion que recibe el fd y el buffeer, lee el fd y guardaen buffer
//y lo leemos hasta encontrar el '\n'
char	*ft_readfile(int fd, char *buffer)
{
	char	*temp_buff;
	int		by_read;

	by_read = 1;
	temp_buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp_buff)
		return (NULL);
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
		ft_free(&buffer);
		return (buffer);
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
	{
		buffer = ft_readfile(fd, buffer);
	}
	if (!buffer)
		return (0);
	line = ft_getline(buffer);
	if (!line)
		return (NULL);
	buffer = ft_upload_buffer(buffer);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line = NULL;

// 	fd = open("prueba.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("ERROR AL ABRIR EL ARCHIVO");
// 		return (1);
// 	}
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf(" -> %s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }
