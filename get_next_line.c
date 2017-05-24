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

static int		read(const int fd, char **dbl_array)
{
	int		ret_of_read;
	char	*string;
	char	buf[BUFF_SIZE + 1];

	if ((ret_of_read = read(fd, buf, BUFF_SIZE)) = -1)
		return (-1);
	buf[ret_of_read] = '\0';
	string = *dbl_array;
	*dbl_array = ft_strjoin(*dbl_array, buf);
	if (*dbl_array != 0)
		free(string);
	return (ret_of_read);
}

static int		get_line(const int fd, char **line)
{
	int		ret_of_read;
	char	buf[BUFF_SIZE + 1];
	char	*tmp_join;
	char	**str;
	char	*saved;

	index = 0;
	if (!saved)
		saved = ft_strdup("");
	buf[ret_of_read] = read(fd, *line);
	tmp = ft_strnew(0);
	end_line = ft_strchr(buf[ret_of_read], '\n');
	while (end_line == NULL)
	{
		if ((ret_of_read = read(fd, buf, BUFF_SIZE)) > 0)
        {
            buffer[ret] = '\0';
            endl = ft_strchr(buf, '\n');
            tmp = ft_strjoin(tmp, buf);
        }
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	int				ret_of_read;
	char			*s;
	static char		*saved;

	if (!line || fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	while (line)
	{
		*line = saved;
		ret_of_read = read(fd, &str);
		if (ret_of_read == -1)
			return (-1);
	}
	return (0);
}


// -----------------------------------------------------------------------------

static int		ft_get_line(const int fd, char **line)
{
	int		i;
	char	*tmp_join;
	char	**str;
	char	*saved;

	index = 0;
	if (*saved == '\n')
		index = 1;
	*saved = 0;
	*line = ft_strjoin("", *str);
	if (index == 0 && ft_strlen(*str) != 0)
	{
		*str = ft_strnew(1);
		return (1);
	}
	else if (index == 0 && !(ft_strlen(*str)))
		return (0);
	tmp_join = *str;
	*str = ft_strjoin(saved + 1, "");
	free(tmp_join);
	return (index);
}

int				get_next_line(int const fd, char **line)
{
	int			ret;
	char		*s;
	static char	*str;

	if (!line || BUFF_SIZE < 1)
		return (-1);
	ret = BUFF_SIZE;
	while (line)
	{
		saved = str;
		while (*saved || ret < BUFF_SIZE)
		{
			if (*saved == '\n' || *saved == 0 || *saved == -1)
				return (ft_get_line(&str, line, s));
			saved++;
		}
		ret = ft_read(&str, fd);
		if (ret == -1)
			return (-1);
	}
	return (0);
}

// -----------------------------------------------------------------------------

// static int		read_line(const int fd, char **line)
// {
// 	int		ret_of_read;
// 	char	*tmp;
// 	char	*saved = NULL;

// 	//because malloc allows us to modify
// 	//if the str is on the stack we can't modify it/it will have strange behavr
// 	if (!saved)
// 		saved = ft_strdup("");
	
// 	while (!(ft_strchr(buf, '\n')) &&
// 		(ret_of_read = read(fd, buf, BUFF_SIZE)) > 0)
// 	{
// 		if (read(fd, buf, 0) < 0)
// 			return (-1);
// 		tmp = malloc(sizeof(char) * (ft_strlen(buf) + ft_strlen(saved) + 1));
// 		ft_strcpy(tmp, saved);
// 		ft_strcat(tmp, buf);
// 		free(saved);
// 		saved = tmp;
// 		*line = saved;
// 	}
// 	return (ret_of_read);
// }

// int				get_next_line(const int fd, char **line)
// {
// 	char		*saved = NULL;
// 	int			ret_of_read;

// 	if (!line || fd < 0 || BUFF_SIZE <= 0)
// 		return (-1);
// 	while (read_line(fd, *line))
// 	{
// 		*line = saved;
// 		return (1);
// 	}
// 	return (0);
// }
