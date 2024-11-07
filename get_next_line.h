/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victda-s <victda-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:05:15 by victda-s          #+#    #+#             */
/*   Updated: 2024/11/07 19:46:00 by victda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 10

char	*get_next_line(int fd);
int		ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
#endif