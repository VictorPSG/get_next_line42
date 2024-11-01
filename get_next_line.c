/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victda-s <victda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:05:09 by victda-s          #+#    #+#             */
/*   Updated: 2024/11/01 18:51:20 by victda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char 		*buffer;
	static char *a;

	buffer = (char *)calloc(BUFFER_SIZE, sizeof(char) + 1);
	while(!ft_strchr(buffer, '\n'))
	{
		a = buffer;
		read(fd, buffer, BUFFER_SIZE);
	}
	buffer = ft_strjoin(buffer, a);
	return (buffer);
}

int	main(void)
{
	int	fd;
	static char *file;

	fd = open("test.txt", O_RDONLY);
	for (int i = 0; i <2 ; i++)
	{
		file = get_next_line(fd);
		printf("%s", file);
	}
}

