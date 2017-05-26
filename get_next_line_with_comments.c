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

static int	get_line(char **line, char **saved)
{
	// int		ret_of_read;
	char	*first_null_char_set;
	char	*after_new_line;

	//if first_null_char_set string found
	if ((first_null_char_set = ft_strchr(*saved, '\n')))
	{
		//we set the first null character instead of the first new line
		*first_null_char_set = '\0';

		//we move from +1 the location of the first null character which used to be the first newline
		first_null_char_set++;

		// strdup will duplicate the string to a different memory address
		// it will just set a string
		//the string after the newline becomes from this location to the last null character
		after_new_line = ft_strdup(first_null_char_set);

		//we set the string of *saved and then we free it as we don't need it anymore
		*line = ft_strdup(*saved);
		//we free the pointer of saved which is the first pointer of saved that we declared at the top
		free(*saved);

		//we just move the pointer to the location of the new pointer of our string after the newline
		//set as null character
		*saved = after_new_line;

		//managed to make it all work
		return (1);
	}
	// no more newlines
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	int			ret_of_read;
	char		*tmp;
	char		buf[BUFF_SIZE + 1];
	static char	*saved = NULL;

	//if saved is null set it as the buffer
	if (!saved)
		saved = ft_strnew(BUFF_SIZE);

	// error checking
	if (!line || fd < 0 || BUFF_SIZE <= 0)
		return (-1);

	//just calling the function before
	if (get_line(line, &saved))
		return (1);

	// we call the reading function
	while ((ret_of_read = read(fd, buf, BUFF_SIZE)))
	{
		//checking the error
		if (ret_of_read == -1)
			return (-1);

		//sets the null character
		buf[ret_of_read] = '\0';

		//use a tmp for the pointer of saved
		tmp = saved;
		//saved is the new memory area from strjoin
		saved = ft_strjoin(saved, buf);
		//free the old pointer
		free(tmp);

		//the return 1 of the file read
		if (get_line(line, &saved))
			return (1);
	}

	//reading the file last part that we haven't read after the last newline until the '\0'
	//after finding the last newline, what's after?
	if (*saved)
	{
		// we set the dble array of line to read until the end of the file
		//copy the caracthers of saved into the last line
		*line = ft_strcpy(saved);
		//deletes whatever is in saved because it has been copied into line
		ft_strdel(&saved);
		//the final return 1 
		return (1);
	}

	//we finished reading the file
	return (0);
}




//to save lines

static int	get_line_extra_after_last_new_line(char **line, char **saved)
{
	*line = ft_strdup(*saved);
	ft_strdel(saved);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	int			ret_of_read;
	char		*tmp;
	char		buf[BUFF_SIZE + 1];
	static char	*saved = NULL;

	if (!saved)
		saved = ft_strnew(BUFF_SIZE);
	if (!line || fd < 0 || read(fd, buf, 0) < 0 || BUFF_SIZE <= 0)
		return (-1);
	if (get_line(line, &saved))
		return (1);
	while ((ret_of_read = read(fd, buf, BUFF_SIZE)))
	{
		if (ret_of_read == -1)
			return (-1);
		buf[ret_of_read] = '\0';
		tmp = saved;
		saved = ft_strjoin(saved, buf);
		free(tmp);
		if (get_line(line, &saved))
			return (1);
	}
	if (*saved)
		return (get_line_extra_after_last_new_line(line, &saved));
	return (0);
}
