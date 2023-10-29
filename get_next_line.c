/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:28:25 by juitz             #+#    #+#             */
/*   Updated: 2023/10/29 22:58:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd,char *buffer, char *s_line)

int		bytes_read;
char	*temp;
char	*s_line

bytes_read = read(fd, buffer, BUFFER_SIZE);
while (bytes_read > 0)
{
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	buffer[bytes_read] = '\0';
	if (!s_line)
		s_line = ft_strdup("");
	temp = s_line;
	s_line = ft_strjoin(temp, buffer)
	free(temp);
	temp = NULL;
	if (ft_strchr(buffer, '\n'))
		break;
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