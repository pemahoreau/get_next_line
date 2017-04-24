<<<<<<< HEAD
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

=======
#include "libft.h"

int		get_next_line(const int fd, char **line)
{
	char	buf[BUFFSIZE + 1];
	int		nbr_read;

	while (nbr_read = read(fd, buf, BUFFSIZE))
	{
		buf[nbr_read] = '\0';
		
	}
}



	while ((nbr_read = read(fd, buf, 20)) > 0)
	{
		buf[nbr_read] = '\0';
		tmp = malloc(sizeof(char) * (ft_strlen(buf) + ft_strlen(result) + 1));
		ft_strcpy(tmp, result);
		ft_strcat(tmp, buf);
		free(result);
		result = tmp;
	}
>>>>>>> d163cbe152bb26e2ed459ecc458ab1e998bd4f68
