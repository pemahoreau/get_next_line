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

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	*line;
	int		i;

	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
	{
		fd = 0;
		return (0);
	}

	i = 0;
	while (1)
	{
		ret = get_next_line(fd, &line);  
		printf("(%d) %d: %s\n", ret, i, line); 
		if (ret == 0 || ret == -1)
		{
			close(fd);
			return (0);
		}
		i++;
	}
	close(fd);
	return (0);
}