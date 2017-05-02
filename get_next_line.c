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

// static int		each_line()
// {
// 	int		*tmp;

// 	tmp = ;
// 	return (0);
// }

int				get_next_line(const int fd, char **line)
{
	char	buf[BUFF_SIZE + 1];
	int		nbr_read;

	while (nbr_read = read(fd, buf, BUFF_SIZE))
	{
		if (fd < 0 || read(fd, buf, 0) < 0)
			return (0);
		buf[nbr_read] = '\0';
	}
}



// while ((nbr_read = read(fd, buf, 20)) > 0)
// {
// 	buf[nbr_read] = '\0';
// 	tmp = malloc(sizeof(char) * (ft_strlen(buf) + ft_strlen(result) + 1));
// 	ft_strcpy(tmp, result);
// 	ft_strcat(tmp, buf);
// 	free(result);
// 	result = tmp;
// }



int		main(int ac, char **av)
{
	char	*line;
	int		fd;

	fd = 0;
	if (ac == 1)
	{
		while (get_next_line(fd, &line) > 0)
		{
			ft_putendl(line);
			line = NULL;
		}
	}
	else if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		while (get_next_line(fd, &line) > 0)
		{
			ft_putendl(line);
			line = NULL;
		}
	}
	return (0);
}