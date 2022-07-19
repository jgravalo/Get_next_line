/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:40:27 by jgravalo          #+#    #+#             */
/*   Updated: 2022/07/14 15:48:22 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*maketext(char *text, int fd)
{
	char	*buffer;
	int		num;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	num = 1;
	while (!ft_strchr(text, '\n') && num != 0)
	{
		num = read(fd, buffer, BUFFER_SIZE);
		if (num == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[num] = '\0';
		text = ft_strjoin(text, buffer);
	}
	free(buffer);
	return (text);
}

char	*makeline(char *text)
{
	int		i;
	char	*line;

	i = 0;
	if (!text[i])
		return (NULL);
	while (text[i] && text[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (text[i] && text[i] != '\n')
	{
		line[i] = text[i];
		i++;
	}
	if (text[i] == '\n')
	{
		line[i] = text[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*modifytext(char *text)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	while (text[i] && text[i] != '\n')
		i++;
	if (!text[i])
	{
		free(text);
		return (NULL);
	}
	new = (char *)malloc(sizeof(char) * (ft_strlen(text) - i + 1));
	if (!new)
		return (NULL);
	i++;
	j = 0;
	while (text[i])
		new[j++] = text[i++];
	new[j] = '\0';
	free(text);
	return (new);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*text;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	text = maketext(text, fd);
	if (!text)
		return (NULL);
	line = makeline(text);
	text = modifytext(text);
	return (line);
}
