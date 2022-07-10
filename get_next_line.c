/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <manuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:49:38 by manuel            #+#    #+#             */
/*   Updated: 2022/07/10 15:22:11 by manuel           ###   ########.fr       */
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

/*this function, is to store the remaining content of the file 
(remaining content == to content after the line to be displayed)
we create a dynamic array with the size of the BUFFER_SIZE + 1, 
and there we store what we want to be copied from the line, we join to save that is
the function passed by parameter to be returned, and line is released just at the end of the function
*/
char	*read_and_save(int fd, char *buff)
{
	char	*sub_buff;
	size_t	bytes_count;

	sub_buff = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!sub_buff)
		return (NULL);
	bytes_count = 1;
	while (!ft_strchr(buff, '\n') && bytes_count != 0)
	{
		bytes_count = read(fd, sub_buff, BUFFER_SIZE);
		if (bytes_count = -1)
		{
			free (sub_buff);
			return (NULL);
		}
		buff = ft_strjoin(buff, sub_buff);
	}
	free (sub_buff);
	return (buff);
}

char	*rest_of_file(char *buffer)
{
	int		i;
	int		j;
	char	*sub_buffer;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	sub_buffer = ft_calloc(ft_strlen(buffer) - i + 1, 1);
	if (!sub_buffer)
		return (NULL);
	i++;
	j = 0;
	while(buffer[i])
		sub_buffer[j++] = buffer [i++];
	free (buffer);
	return (sub_buffer);
}

char	*get_next_line(int fd)
{
	char		*line_print;
	static char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line_print = read_and_save (fd, line);
	if (!line_print)
		return (NULL);
	line = check_line(line_print);
	line_print = rest_of_file(line_print);
	return (line);
}