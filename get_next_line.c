/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victda-s <victda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:05:09 by victda-s          #+#    #+#             */
/*   Updated: 2024/11/11 20:20:03 by victda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
static char	*get_suffix(char *stash)
{
	int		i;
	char	*suffix;

	i = 0;
	while(stash[i] != '\n')
		i++;
	i++;
	suffix = ft_substr(stash, i, BUFFER_SIZE);
	return (suffix);
}
static char	*get_line(char *stash)
{
	int		i;
	char	*get_line;

	i = 0;
	// printf("stash:%s\n", stash);
	while(stash[i] != '\n')
		i++;
	// printf("i: %d\n", i);
	get_line = ft_substr(stash, 0, i);
	return (get_line);
}
static char	*read_line(int fd, char *buffer, char *stash)
{
	int		read_bytes;
	char	*temp;

	while(!ft_strchr(stash, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if(read_bytes == 0 && stash[0] == '\0')
		{
			free(stash);
			return (NULL);
		}
		if(read_bytes <= 0)
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
	char *buffer;
	char	*line;
	static char	*stash;

	if(fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char) + 1);
	if(!buffer)
		return (NULL);

	if(!stash)
		stash = ft_strdup("");
	stash = read_line(fd, buffer, stash);
	free(buffer);
	if(!stash)
		return (NULL);
	if(ft_strlen(stash) == 1)
		return (stash);
	line = get_line(stash);
	stash = get_suffix(stash);
	return (line);
}
// int	main(void)
// {
// 	int	fd;
// 	char *stash;

// 	fd = open("test.txt", O_RDONLY);
// 	for (int i = 0; i < 10 ; i++)
// 	{
// 		stash = get_next_line(fd);
// 		printf("result :%s\n", stash);
// 	}
// }

