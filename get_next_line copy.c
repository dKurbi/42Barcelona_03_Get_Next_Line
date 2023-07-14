/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:56:31 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/07/14 13:00:12 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*join_str(char *o_str, char *s_str, char, int *t)
{
	char	*rtn;
	int		i;
	int		j;

	i = 0;
	j = 0;
	rtn = (char *) malloc((*t * BUFFER_SIZE + 1) * sizeof(char));
	while (str[0][i])
		rtn[i++] = o_str[i];
	while (j < BUFFER_SIZE)
		rtn [i++] = s_str[j++];
	return (rtn);
}

int check_n(char *str, int *)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char			buffer;
	int				numbytes;
	static int		i;
	char			*str[3]; //

	i = 0;
	str[0] = (char) malloc((BUFFER_SIZE + 1) * sizeof(char));
	str[1] = (char) malloc((BUFFER_SIZE + 1) * sizeof(char));
	numbytes = read(fd, &str[0], BUFFER_SIZE);
	while ((numbytes > 0) && !check_n(str[0]))
	{
		join_str();
		
		numbytes = read(fd, &str[0], BUFFER_SIZE);
	}
	str[i] = '\n';
	return (&str);
}

int main (void)
{
	char	*dict;
	int		fd;
	char 	*str;

	dict = "readme.txt";
	fd = open(dict, O_RDONLY);
	if (fd == -1)
		return (1);
	str = get_next_line(fd);
	printf("se leyo: %s\n", str );
}