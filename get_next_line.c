/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:49:38 by manuel            #+#    #+#             */
/*   Updated: 2022/07/10 14:46:50 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* this function checks if there is a line to copy, and stores it in a 
dynamic array and returns the new line with a line feed and a null.*/

char    *check_line(char *str)
{
	int     count;
	char    *line;
	
	count = 0;
	while(str[count] && str[count] != '\n')
		count++;
	line = ft_calloc(count + 2, 1);
	count = 0;
	while (str[count] && str[count] != '\n')
		line[count] = str[count++];
	return (line);
}


