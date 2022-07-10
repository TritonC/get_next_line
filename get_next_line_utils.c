/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:09:57 by manuel            #+#    #+#             */
/*   Updated: 2022/07/10 18:23:10 by mluis-fu         ###   ########.fr       */
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
	while (str[count])
		count++;
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
	size_t	i;
	size_t	j;
	char	*aux;
	size_t	len;

	i = 0;
	j = 0;
	if (!dest || !src)
		return (NULL);
	len = ft_strlen(dest) + ft_strlen(src);
	aux = ft_calloc(len + 1, 1);
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
	return (aux);
}
