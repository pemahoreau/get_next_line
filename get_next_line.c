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

// static int		end_of_line(char *str)
// {
// 	int		index;
// 	int		end_of_line;

// 	end_of_line = \
// }

static int		read_file(const int fd, char **line)
{
	int		return_of_read;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	char	*saved = NULL;

	if (!saved)
		saved = ft_strdup("");
	//because malloc allows us to modify
	//if the str is on the stack we can't modify it/it will have strange behavr
	while ((return_of_read = read(fd, buf, BUFF_SIZE)))
	{
		if (!line || fd < 0 || read(fd, buf, 0) < 0)
			return (-1);
		// if (ft_strchr(buf, '\n'))
		// 	break ;
		buf[return_of_read] = '\0';
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
	int			result;
	char		*end_of_line;
	char		*saved = NULL;

	if (fd < 0)
		return (-1);
	end_of_line = ft_strchr(saved, '\n');
	while (end_of_line == NULL)
	{
		result = read_file(fd, &saved);
	}
	*line = saved;
	return (result);
}

/*
** check for the newline
** if i have stuff after the newline i have to free it
*/
