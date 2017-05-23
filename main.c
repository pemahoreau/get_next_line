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
#include <stdio.h>

int		main(int ac, char **av)
{
	char	*line;
	int		fd;

	fd = 0;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		while (get_next_line(fd, &line) > 0)
		{
			// get_next_line(fd, &line);
			// ft_putendl("YOLOOOO");
			printf("------------------------\n");
			printf("ça fait un tour\n");
			printf("------------------------\n");
			ft_putendl(line);
			line = NULL;
		}
		// ft_putendl(line);
	}
	return (0);
}
