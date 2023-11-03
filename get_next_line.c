/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 21:18:45 by marvin            #+#    #+#             */
/*   Updated: 2023/11/03 08:42:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char	*ft_join_and_free(char *text, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(text, buffer);
	free(text);
	return (temp);
}

char	*read_line(int fd, char *text)
{
	char	*buffer;
	int		bytes_read;

	if (!text)
		text = ft_calloc(1, 1);
		/* if (!text)
			return (NULL); */
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(text), free(buffer), NULL);
		buffer[bytes_read] = '\0';
		text = ft_join_and_free(text, buffer);
		if (!text)
			return (NULL);
		if (ft_strchr(text, '\n'))
			break ;
	}
	return (free(buffer), text);
}

char	*extract_line(char *text)
{
	int		i;
	char	*str;

	i = 0;
	if (!text[i])
		return (NULL);
	while (text[i] != '\n' && text[i] != '\0')
		i++;
	str = ft_calloc(i + 2, sizeof(char));
	//added this 
	if(!str)
		return (NULL);
	i = 0;
	while (text[i] != '\n' && text[i] != '\0')
	{
		str[i] = text[i];
		i++;
	}
	if (text[i] == '\n' && text[i] != '\0')
		str[i++] = '\n';
	return (str);
}

char	*clean_line(char *text)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (text[i] != '\n' && text[i] != '\0')
		i++;
	if (!text[i])
	{
		free (text);
		return (NULL);
	}
	str = ft_calloc((ft_strlen(text) - i + 1), sizeof(*text));
	if (!str)
		return (NULL);
	while (text[++i])
		str[j++] = text[i];
	str[j] = '\0';
	free (text);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*output_text;
	static char	*text;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	text = read_line(fd, text);
	if (!text)
		return (NULL);
	output_text = extract_line(text);
	text = clean_line(text);
	return (output_text);
}

int	main(void)
{
	int	file;
	char *buffer;
	
	buffer = NULL;
	file = open("test.txt", O_RDONLY);
	buffer = get_next_line(file);
	if(buffer == NULL)
		return (-1);
	while (buffer != NULL)
	{
		printf("%s", buffer);
		free(buffer);
		buffer = get_next_line(file); 	
	}
	//read_line(file, buffer);
	//printf("%s", buffer);
	free(buffer);
	close(file);
	return (0);
} 
/* int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *a;

	while ((a = get_next_line(fd) ) != NULL)
	{
		printf("%s", a);
		free(a);
	}
	free(a);
	// printf("%s", get_next_line(fd));

	return 0;
} */
