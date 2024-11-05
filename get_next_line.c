/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victda-s <victda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:05:09 by victda-s          #+#    #+#             */
/*   Updated: 2024/11/05 17:24:05 by victda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd, char *stash)
{
	char 		*buffer;
	int	i;

	i = 0;
	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char) + 1);
	read(fd, buffer, BUFFER_SIZE);
	printf("buffer:%s\n", buffer);
	while(ft_strchr(&buffer[i], '\n') && buffer[i])
	{
		i++;
	}
	// printf("valor i:%i\n", i);
	buffer = ft_substr(buffer, 0, i);
	if(stash != NULL)
	{
		ft_strlcat(stash, buffer, ft_strlen(stash) + i + 1);
		// printf("buffer sub: %s\n-----------------------------\n", buffer);
		// printf("stash: %s\n", stash);
		// printf("resultado: %s\n\n", stash);
	}
	else
	{
		stash = buffer;
		// printf("else ||%s||\n", stash);
	}
	// printf("buffer:%s | valor i: %d\n", buffer, i);
	if(i == BUFFER_SIZE)
	{
		get_next_line(fd, stash);
	}
	return (stash);
}
int	main(void)
{
	int	fd;
	static char *stash;

	fd = open("test.txt", O_RDONLY);
	for (int i = 0; i < 5 ; i++)
	{
		stash = get_next_line(fd, stash);
		// printf("result :%s\n", stash);
		stash = NULL;
	}
}

