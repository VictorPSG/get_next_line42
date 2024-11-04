/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victda-s <victda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:05:04 by victda-s          #+#    #+#             */
/*   Updated: 2024/11/04 16:37:28 by victda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(const char *s, int c)
{
	int				i;
	int				lenght;
	unsigned char	cc;

	i = 0;
	lenght = ft_strlen(s);
	cc = (unsigned char)c;
	if (cc == '\0')
		return (lenght);
	while (s[i] && s[i] != cc)
	{
		i++;
		if (i == lenght)
			return (-1);
	}
	if (s[i] == cc)
		return (i);
	return (-1);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	int		i;
	char	*arr;

	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	arr = (char *)malloc(len_s1 + len_s2 + 1);
	if (!arr)
		return (NULL);
	while (s1[i])
	{
		arr[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		arr[len_s1] = s2[i];
		len_s1++;
		i++;
	}
	arr[len_s1] = '\0';
	return (arr);
}