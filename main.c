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
			ft_putendl("YOLOOOO");
			line = NULL;
		}
		ft_putendl(line);
	}
	return (0);
}




// int get_next_line(int const fd, char ** line)
// {
// 	static char	*stock = NULL;
// 	char		*endl_index;
//     int         ret;

//     if (!stock && (stock = (char *)ft_memalloc(sizeof(char))) == NULL)
//         return (-1);
// 	endl_index = ft_strchr(stock, ENDL);
// 	while (endl_index == NULL)
// 	{
//         ret = read_from_fd_into_stock(fd, &stock);
//         if (ret == 0)
//         {
//             if ( (endl_index = ft_strchr(stock, '\0')) == stock )
//                 return (0);
//         } else if (ret < 0)
//             return (-1);
//         else
//             endl_index = ft_strchr(stock, ENDL);
// 	}
//     *line = ft_strsub(stock, 0, endl_index - stock);
//     if (!*line)
//         return (-1);
//     endl_index = ft_strdup(endl_index + 1);
//     free(stock);
//     stock = endl_index;
// 	return (1);
