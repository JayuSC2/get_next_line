/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:28:25 by juitz             #+#    #+#             */
/*   Updated: 2023/11/01 16:15:37 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *buffer, char *backup)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
		if (!backup)
			backup = ft_strdup("");
		temp = backup;
		backup = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (bytes_read == 0 || bytes_read == -1)
		return (0);
	return (backup);
}

char	*extract_line(char *text)
{
	char	*backup;
	int		i;

	i = 0;
	if (!text)
	{
		free(text);
		return (NULL);
	}
	while (text[i] != '\n' || text[i] != '\0')
	{
		backup = malloc(sizeof(char) * BUFFER_SIZE + 1);
		backup[i] = text[i];
		i++;
	}
	free (text);
	if (text[i] == '\n')
		backup[i++] = '\n';
	return (backup);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*text;
	static char	*backup;

	backup = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return(0);
	text = read_line(fd, buffer, backup);
	free(buffer);
	buffer = 0;
	if (!text)
		return (0);
	backup = extract_line(text);
	return (text);
}

/* char	*get_next_line(int fd)
{
	char	buffer;
	char	backup[7000000];
	int		bytes_read;
	int		i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = read(fd, &buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		backup[i++] = buffer;
		if (buffer == '\n')
			break ;
		bytes_read = read (fd, &buffer, BUFFER_SIZE);
	}
	backup = '\0';
	if (bytes_read <= 0)
		return (NULL);
	return (ft_strdup(backup));
}
 */