/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victda-s <victda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:05:09 by victda-s          #+#    #+#             */
/*   Updated: 2024/11/04 17:31:06 by victda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char 		*buffer;
	static char *a;
	int	i;

	i = 1;
	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char) + 1);
	read(fd, buffer, BUFFER_SIZE);
	a = NULL;
	while(ft_strchr(&buffer[i], '\n') && i < BUFFER_SIZE)
	{
		printf("%c", buffer[i]);
		i++;
	}
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
		// printf("%s", file);
	}
}

