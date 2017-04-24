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