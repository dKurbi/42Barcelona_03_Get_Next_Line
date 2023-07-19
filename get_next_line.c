/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:56:31 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/07/19 18:47:01 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	storaging(char **rtn, char **stor)
{
	int		i;
	char	*storaging;

	if (stor && *stor) 
	{
		storaging = *stor;
		i = check_n(storaging);
		*rtn = join_str(NULL, storaging, i);
		if (i > -1)
		{
			*stor = join_str(NULL, &storaging[i + 1], -1);
			return (1);
		}
		else
			*stor = my_free(&storaging);
	}
	return (0);
}

char	*my_free(char **str)
{
	if (str != NULL)
		free(*str);
	return (NULL);
}

int	get_read(int fd, char **read_str)
{
	long	nb;
	
	if (fd == -1)
		return (-1);
	if (!(*read_str))
	{
		*read_str = (char *) malloc ( BUFFER_SIZE * sizeof (char));
		if (!read_str)
			return (-1);
	}
	nb = read(fd, *read_str, BUFFER_SIZE);
	if (nb == -1 || nb == 0)
		*read_str = my_free(read_str);
	else
		*read_str = join_str(*read_str, "\0", 1);
	return (nb);
}
char	*get_next_line(int fd)
{
	static char		*storage = NULL;
	char			*rtn;
	char			*read_str;
	long			nb;
	int				i;

	rtn = NULL;
	read_str = NULL;
	i = -1;
	nb = BUFFER_SIZE;
	if (storaging (&rtn, &storage))
		return (rtn);
	while ((i == -1 && nb == BUFFER_SIZE))
	{
		nb = get_read(fd, &read_str);	
		if (nb == 0) 
			return (rtn);
		else if (nb == -1)
		{	
			rtn = my_free(&rtn);
			return (NULL);
		}
		i = check_n(read_str);
		rtn = join_str(rtn, read_str, i);
	}
	if (i != -1)
		storage = join_str (NULL, &read_str [i + 1], -1);
	read_str = my_free(&read_str);
	return (rtn);
}

