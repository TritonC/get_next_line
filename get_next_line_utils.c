/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:09:57 by manuel            #+#    #+#             */
/*   Updated: 2022/07/11 17:09:56 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	num;
	size_t	counter;
	char	*mem;

	num = count * size;
	counter = 0;
	mem = NULL;
	if (num < size && num < count)
		return (NULL);
	mem = malloc(num);
	if (!mem)
		return (NULL);
	while (counter < num)
		mem[counter++] = 0;
	return ((void *)mem);
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count])
	{
		count++;
	}
	return (count);
}

char	*ft_strchr(const char *string, int ch)
{
	char	*str;

	str = (char *)string;
	while (*str != ch && *str != 0)
		str++;
	if (*str == ch)
		return (str);
	else
		return (NULL);
}

char	*ft_strjoin(char const *dest, char const *src)
{
	int		sizetotal;
	char	*res;
	int		i;
	int		j;

	i = 0;
	sizetotal = ft_strlen(dest) + ft_strlen(src);
	res = malloc(sizeof(char) * (sizetotal + 1));
	if (!res || !dest || !src)
		return (NULL);
	while (dest[i] != 0)
	{
		res[i] = dest[i];
		i++;
	}
	j = 0;
	while (src[j] != 0)
	{
		res[i] = src[j];
		i++;
		j++;
	}
	res[sizetotal] = 0;
	return (res);
}
