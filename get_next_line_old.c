/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:56:31 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/07/18 14:20:10 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif


int	len_str(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*join_str(char *o_str, char *s_str, int lo)
{
	char	*j_str;
	int		size;
	int		i;
	int		j;

	i = 0;
	j = 0;
	size = len_str(o_str) + lo;
	if (lo == 0)
		size = len_str(o_str) + len_str(s_str);
	j_str = (char *) malloc((size + 1) * sizeof (char));
	while (o_str)
	{
		j_str[i] = o_str[i];
		o_str++;
	}
	while (i <= size)
		j_str[i++] = s_str[j++];
	j_str[i] = '\0';
	return (j_str);
}

char	*strd_up(char *s1, int size)
{
	char	*rtn;
	int		i;

	i = 0;
	if (size == 0)
		size = len_str(s1);
	rtn = (char *)malloc((size + 1) * sizeof (char));
	if (!rtn)
		return (NULL);
	while (i < size)
	{
		rtn[i] = s1[i];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}

void	my_free(char *tofree)
{
	free(tofree);
}

int	check(char **str, char **storage, char **rtn)
{
	int		i;

	i = 0;
	while ((*str)[i] != '\0' && (*str)[i] != '\n') 
		i++;
	if (i == len_str(*str))
	{
		*rtn = join_str(*rtn, *str, 0);
		return (0);
	}
	else if ((*str)[i] == '\n')
	{
		*storage = join_str (NULL, &str[i + 1], len_str(&str[i + 1]));
	}
	else
	{
		my_free(*storage);
	}
	*rtn = join_str(*rtn, *str, i);
	return (1);
}

char	*get_next_line(int fd)
{
	static char 	*storage = NULL;
	char			*rtn;
	char			*read_str;
	int				nb;
	
	rtn = NULL;
	if (storage && check(&storage, &storage, &rtn))
	{
		my_free(storage);
		return (rtn);
	}
	read_str = (char *) malloc (BUFFER_SIZE * sizeof (char));
	nb = read(fd, read_str, BUFFER_SIZE);
	while (check(&read_str, &storage, &rtn) && nb == BUFFER_SIZE)
		nb = read(fd, read_str,BUFFER_SIZE);
	return (rtn);
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
	str = get_next_line(fd);
	printf("se leyo: %s\n", str );
	close(fd);
}