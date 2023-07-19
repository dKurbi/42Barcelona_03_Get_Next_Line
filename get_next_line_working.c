/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:56:31 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/07/19 15:00:17 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	static char 	*storage = NULL;
	char			*rtn;
	char			*read_str;
	int				nb;
	int				i;

	rtn = NULL;

	if (storage)
	{
		i = check_n(storage);
		rtn = join_str(NULL, storage, i);
		if (i > -1)
		{
			storage = join_str(NULL, &storage[i + 1], -1);
			return (rtn);
		}
		else
		{
			free(storage);
			storage = NULL;
		}
	}
	read_str = (char *) malloc ((BUFFER_SIZE + 1)* sizeof (char));
	
	nb = read(fd,read_str, BUFFER_SIZE);
	read_str[nb] = '\0';
	if (nb < 1) 
	{
		free(read_str);
		return (rtn);
	}
	i = check_n(read_str);
	while (i == -1 && nb == BUFFER_SIZE)
	{
		rtn = join_str(rtn, read_str, i);
		nb = read(fd, read_str, BUFFER_SIZE);
		read_str[nb] = '\0';
		i = check_n(read_str);
	}
	rtn = join_str(rtn, read_str, i);
	if (i != -1)
		storage = join_str (NULL, &read_str[i+1], -1);
	free(read_str);
	return (rtn);
}
/* int main (void)
{
	char	*dict;
	int		fd;
	char 	*str;
	int 	i;
	
	
	i = 1;
	dict = "readme.txt";
	fd = open(dict, O_RDONLY);
	if (fd == -1)
		return (1);
	str = get_next_line(fd);
	while (i < 18)
	{
			printf("%d > %s", i, str );
			str = get_next_line(fd);
			i++;
	}
	close(fd);
} */