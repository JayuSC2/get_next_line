/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:28:25 by juitz             #+#    #+#             */
/*   Updated: 2023/10/30 15:41:49 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *buffer, char *s_line)
{
	int		bytes_read;
	char	*temp;
	char	*s_line;

	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
		if (!s_line)
			s_line = ft_strdup("");
		temp = s_line;
		s_line = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (bytes_read == 0)
		return (0);
	return (s_line);
}

/* char	*get_next_line(int fd)
{
	char	buffer;
	char	s_line[7000000];
	int		bytes_read;
	int		i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = read(fd, &buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		s_line[i++] = buffer;
		if (buffer == '\n')
			break ;
		bytes_read = read (fd, &buffer, BUFFER_SIZE);
	}
	s_line = '\0';
	if (bytes_read <= 0)
		return (NULL);
	return (ft_strdup(s_line));
}
 */