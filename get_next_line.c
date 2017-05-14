/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 20:30:37 by phoreau           #+#    #+#             */
/*   Updated: 2017/04/22 20:31:01 by phoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int		read_line(const int fd, char **line)
{
	int		return_of_read;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	char	*saved = NULL;

	if (!saved)
		saved = ft_strdup("");
	//because malloc allows us to modify
	//if the str is on the stack we can't modify it/it will have strange behavr
	ft_bzero(buf, sizeof(char) * (BUFF_SIZE + 1));
	while ((return_of_read = read(fd, buf, BUFF_SIZE)))
	{
		if (!line || fd < 0 || read(fd, buf, 0) < 0 || BUFF_SIZE <= 0)
			return (-1);
		tmp = malloc(sizeof(char) * (ft_strlen(buf) + ft_strlen(saved) + 1));
		ft_strcpy(tmp, saved);
		ft_strcat(tmp, buf);
		free(saved);
		saved = tmp;
		*line = saved;
	}
	return (return_of_read);
}

int				get_next_line(const int fd, char **line)
{
	int			return_of_gnl;
	char		*saved = NULL;

	return_of_gnl = 0;
	if (read_line(fd, &saved))
		return (1);
	*line = saved;
	return (return_of_gnl);
}

/*
** check for the newline
** if i have stuff after the newline i have to free it
*/
