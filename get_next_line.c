/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victda-s <victda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:05:09 by victda-s          #+#    #+#             */
/*   Updated: 2024/11/13 22:29:12 by victda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_suffix(char *stash)
{
	int		i;
	char	*suffix;

	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	suffix = ft_substr(stash, i + 1, ft_strlen(stash) - i);
	free(stash);
	stash = NULL;
	return (suffix);
}

static char	*get_line(char *stash)
{
	int		i;
	char	*get_line;

	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	if (stash[i] == '\0')
		return (ft_strdup(stash));
	get_line = ft_substr(stash, 0, i + 1);
	return (get_line);
}

static char	*read_line(int fd, char *buffer, char *stash)
{
	int		read_bytes;
	char	*temp;

	while (!ft_strchr(stash, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if ((read_bytes == 0 && stash[0] == '\0') || read_bytes < 0)
		{
			free(stash);
			stash = NULL;
			return (NULL);
		}
		if (read_bytes == 0)
			return (stash);
		buffer[read_bytes] = '\0';
		temp = ft_strjoin(stash, buffer);
		free(stash);
		stash = temp;
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (stash)
		{
			free(stash);
			stash = NULL;
		}
		return (NULL);
	}
	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!buffer)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	stash = read_line(fd, buffer, stash);
	free(buffer);
	if (!stash)
		return (NULL);
	line = get_line(stash);
	stash = get_suffix(stash);
	return (line);
}
