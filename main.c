/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:39:37 by juitz             #+#    #+#             */
/*   Updated: 2023/10/31 14:54:54 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*read_line(int fd, char *buffer, char *s_line)
{
	int		bytes_read;
	char	*temp;

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
	if (bytes_read == 0 || bytes_read == -1)
		return (0);
	return (s_line);
}

int	main(void)
{
	int	file;
	char *buffer;
	
	
	file = open("testtext.txt", O_RDONLY);
	printf("%s", buffer); 
	while (buffer != NULL)
	{
		buffer = get_next_line(file); 
		
	}
	
	read_line(file, buffer, 5);
	printf("%s", buffer);
	free(buffer);
	close(file); 
	
}