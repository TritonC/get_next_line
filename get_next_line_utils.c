/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:09:57 by manuel            #+#    #+#             */
/*   Updated: 2022/07/10 17:33:10 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t n, size_t size)
{
	size_t	c;
	void	*ptr;

	c = 0;
	ptr = malloc(n * size);
	if (ptr != NULL)
		while (c++ < n)
			((unsigned char *)ptr)[c - 1] = 0;
	return (ptr);
}

size_t	ft_strlen(char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_strchr(const char *str, int ch)
{
	int	len;

	len = ft_strlen((char *)str);
	if (ch == 0)
		return ((char *)str + len);
	while (*str)
	{
		if (*str == (char)ch)
			return ((char *)str);
		str++;
	}
	return (0);
}

char	*ft_strjoin(char const *dest, char *src)
{
	size_t	i;
	size_t	j;
	char	*aux;
	size_t	len;

	i = 0;
	j = 0;
	if (!dest || !src)
		return (NULL);
	len = ft_strlen((char *)dest) + ft_strlen(src);
	aux = (char *)malloc(sizeof(char) * (len + 1));
	if (!aux)
		return (NULL);
	while (dest[i])
	{
		aux[i] = dest[i];
		i++;
	}
	while (src[j])
	{
		aux[i + j] = src[j];
		j++;
	}
	aux[i + j] = '\0';
	return (aux);
}
