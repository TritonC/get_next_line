/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:09:57 by manuel            #+#    #+#             */
/*   Updated: 2022/07/11 16:15:52 by mluis-fu         ###   ########.fr       */
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

char	*ft_strchr(const char *str, int ch)
{
	int	len;

	len = ft_strlen(str);
	if (ch == 0)
		return ((char *)str + (char)len);
	while (*str)
	{
		if (*str == (char)ch)
			return ((char *)str);
		str++;
	}
	return (0);
}

char	*ft_strjoin(char const *dest, char const *src)
{
	char	*join;
	size_t	len;

	if (!dest && !src)
		return (NULL);
	len = ft_strlen(dest) + ft_strlen(src) + 1;
	join = ft_calloc(len, sizeof(char));
	if (!join)
		return (NULL);
	if (dest)
	{
		while (dest)
			*join++ = *dest++;
	}
	if (src)
	{
		while (*src)
			*join++ = *src++;
	}
	return (join - len);
}
