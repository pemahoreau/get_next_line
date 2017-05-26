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

// int		main(int ac, char **av)
// {
// 	char	*line;
// 	int		fd;

// 	fd = 0;
// 	if (ac == 2)
// 	{
// 		fd = open(av[1], O_RDONLY);
// 		ft_putendl("---------------------------------");
// 		while (get_next_line(fd, &line) > 0)
// 		{
// 			ft_putendl(line);
// 			ft_putendl("---------------------------------");
// 			line = NULL;
// 		}
// 	}
// 	return (0);
// }


int main(int argc, char **argv)
{
    int fd;
    int ret;
    char *line;
	int i;

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
        if (ret == 0 || ret == -1)
		{
			close(fd);
            return (0);
		}
		printf("(%d) %d: %s\n", ret, i, line);
        i++;
    }
	close(fd);
    return (0);
}