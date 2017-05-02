/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 20:02:01 by phoreau           #+#    #+#             */
/*   Updated: 2017/05/01 20:02:29 by phoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int ac, char **av)
{
	char			*line;
	int				fd;

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
