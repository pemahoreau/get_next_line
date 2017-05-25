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
	int			ret_of_read;
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	static char	*saved;

	//because malloc allows us to modify
	//if the str is on the stack we can't modify it/it will have strange behavr
	if (!saved)
		tmp = ft_strdup("");
	ft_bzero(buf, BUFF_SIZE + 1);
	while (!(ft_strchr(buf, '\n')) && (ret_of_read = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (read(fd, buf, 0) < 0)
			return (-1);
		// tmp = malloc(sizeof(char) * (ft_strlen(buf) + ft_strlen(saved) + 1));
		// ft_strcpy(tmp, saved);
		// ft_strcat(tmp, buf);
		tmp = ft_strjoin(tmp, buf);
	}
	*line = ft_strsub(tmp, 0, (ft_strchr(tmp, '\n') - tmp));
	saved = ft_strsub(tmp, (ft_strchr(tmp, '\n') - tmp + 1), ft_strlen(tmp));
	return (ret_of_read);
}

int				get_next_line(const int fd, char **line)
{
	char	*saved = NULL;

	if (!line || fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	if (read_line(fd, line))
	{
		saved = *line;
		return (1);
	}
	return (0);
}
