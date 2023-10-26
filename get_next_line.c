/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:28:25 by juitz             #+#    #+#             */
/*   Updated: 2023/10/26 17:01:47 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char	*s_line
	int		n;


	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (n != 0)
	{
		n = read(fd, &buffer, BUFFER_SIZE);
		*s_line++;
	}
	if (*s_line == '\n')
	{
		s_line = '\0';
		return (ft_strdup(s_line));
	}
}
