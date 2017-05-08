/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 19:17:55 by phoreau           #+#    #+#             */
/*   Updated: 2016/10/07 19:40:52 by phoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	int		index;

	index = 0;
	while (s[index] != '\0')
	{
		s[index] = 0;
		index++;
	}
}