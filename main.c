/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:39:37 by juitz             #+#    #+#             */
/*   Updated: 2023/11/01 15:40:05 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	file;
	char *buffer;
	char *backup;
	
	
	file = open("testtext.txt", O_RDONLY);
	printf("%s", buffer); 
	while (buffer != NULL)
		buffer = get_next_line(file);
	read_line(file, buffer, backup);
	printf("%s", buffer);
	free(buffer);
	close(file); 
}