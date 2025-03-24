/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadalid- <jadalid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:18:43 by jadalid-          #+#    #+#             */
/*   Updated: 2025/02/19 22:00:26 by jadalid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char **buffer)
{
	free(*buffer);
	*buffer = NULL;
	return (NULL);
}

char	*ft_upload_buffer(char *buffer)
{
	char	*new_buffer;
	char	*pos;
	int		end;

	pos = ft_strchr(buffer, '\n');
	if (!pos)
		return (ft_free(&buffer));
	end = ft_strlen(pos + 1);
	new_buffer = ft_substr(buffer, pos - buffer + 1, end);
	ft_free(&buffer);
	if (!new_buffer || *new_buffer == '\0')
		return (ft_free(&new_buffer));
	return (new_buffer);
}

char	*ft_getline(char *buffer)
{
	char	*result;
	char	*pos;
	int		end;

	if (!buffer[0])
		return (NULL);
	pos = ft_strchr(buffer, '\n');
	if (pos)
		end = (pos - buffer) + 1;
	else
		end = ft_strlen(buffer);
	result = ft_substr(buffer, 0, end);
	if (!result)
		return (NULL);
	return (result);
}

char	*ft_readfile(int fd, char *buffer)
{
	char	*temp_buff;
	int		by_read;

	if (!buffer)
		buffer = ft_calloc(sizeof(char), 1);
	temp_buff = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!temp_buff)
		return (NULL);
	by_read = 1;
	while (by_read != 0 && !ft_strchr(buffer, '\n'))
	{
		by_read = read(fd, temp_buff, BUFFER_SIZE);
		if (by_read == -1)
		{
			free(temp_buff);
			return (ft_free(&buffer));
		}
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
	static char	*buffer[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (NULL);
	buffer[fd] = ft_readfile(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_getline(buffer[fd]);
	buffer[fd] = ft_upload_buffer(buffer[fd]);
	return (line);
}
