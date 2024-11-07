/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victda-s <victda-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:05:09 by victda-s          #+#    #+#             */
/*   Updated: 2024/11/07 19:47:57 by victda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*stash;
	int	i;

	i = 0;
	stash = NULL;
	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char) + 1);
	read(fd, buffer, BUFFER_SIZE);
	while(ft_strchr(&buffer[i], '\n') && buffer[i])
		i++;
	buffer = ft_substr(buffer, 0, i);
	if(stash != NULL)
		ft_strlcat(stash, buffer, ft_strlen(stash) + i + 1);
	else
		stash = buffer;
	if(i == BUFFER_SIZE)

		get_next_line(fd);
	else if (stash != NULL)
		buffer = ft_substr(buffer, i, BUFFER_SIZE);
	return (stash);
}
int	main(void)
{
	int	fd;
	static char *stash;

	fd = open("test.txt", O_RDONLY);
	for (int i = 0; i < 3 ; i++)
	{
		stash = get_next_line(fd);
		printf("result :%s\n", stash);
	}
}

