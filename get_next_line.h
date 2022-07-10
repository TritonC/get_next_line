/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:19:59 by manuel            #+#    #+#             */
/*   Updated: 2022/07/07 22:37:09 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE.H
# define GET_NEXT_LINE.H

# include <stdio.h>
# include <stdlib.h>

void	*ft_calloc(size_t n, size_t size);
size_t	ft_strlen(char *str);
char	*ft_strchr(const char *str, int ch);
char	*ft_strjoin(char const *dest, char const *src);

#endif