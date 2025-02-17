/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanje <juanje@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:18:43 by jadalid-          #+#    #+#             */
/*   Updated: 2025/02/17 22:03:23 by juanje           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <fcntl.h>   // Para open y O_RDONLY
#include <stdio.h>   // Para printf y perror
#include <stdlib.h>  // Para free
#include <stddef.h>  // Para NULL
#include "get_next_line.h"  // Para get_next_line

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
		printf("fallo segunda vuelta en hacer substr \n");
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
	while (by_read > 0 && !ft_strchr(buffer, '\n'))
	{
		printf("Estoy leyendo \n");
		by_read = read(fd, temp_buff, BUFFER_SIZE);
		if (by_read > 0)
		{
			temp_buff[by_read] = '\0';
			printf("Voy a copiar \n");
			buffer = ft_strjoin(buffer, temp_buff);
		}
	}
	printf("He leido \n");
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
		printf("Voy a redfile \n");
		buffer = ft_readfile(fd, buffer);
	}
	if (!buffer)
		return (0);
	printf("Voy a imprimir \n");
	line = ft_getline(buffer);
	if (!line)
	{
		printf("Falle en hacer segubdo getline \n");
		return (NULL);
	}
	//hacer que lo de buffer se libere para guardar la nueva line si la hay
	buffer = ft_upload_buffer(buffer);
	return (line);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*dest;
	size_t			leng;
	unsigned int	i;
	unsigned int	j;

	if (!s1)
	{
		printf("Algo esta vacion en strjoin \n");
		s1 = malloc(sizeof(char) + 1);
		if (!s1)
			return (NULL);
		s1[0] = 0;
	}
	leng = ft_strlen(s1) + ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) * (leng + 1));
	if (dest == NULL)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		dest[i + j] = s2[j];
		j++;
	}
	printf("Copie las string \n");
	dest[i + j] = '\0';
	return (dest);
}

size_t	ft_strlen(const char *nptr)
{
	unsigned int	i;
	
	if (!nptr)
		return (0);
	i = 0;
	while (nptr[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!s)
	{
		printf("Fallo porque 2 sub buffer nulll \n");
		return (0);
	}
	if (start > ft_strlen(s))
	{
		substr = malloc(sizeof(char) * (1));
		if (!substr)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (0);
	i = 0;
	while (len--)
	{
		substr[i++] = s[start++];
	}
	substr[i] = '\0';
	return (substr);
}

int	main(void)
{
	int		fd;
	char	*line = NULL;

	fd = open("prueba.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("ERROR AL ABRIR EL ARCHIVO");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf(" -> %s", line);
		free(line);
	}
	close(fd);
	return (0);
}
