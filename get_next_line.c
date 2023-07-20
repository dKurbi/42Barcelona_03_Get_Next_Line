/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:46:53 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/07/20 19:45:02 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
int	init (char **rtn, char **read_str, int *i_rtn, int fd)
{
	int		check;
	char	c;

	check =  read(fd, &c, 0);
	if (fd == -1 || check == -1)
		return (-1);
	*rtn = NULL;
	i_rtn = 0;
	*read_str = (char *) malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (*read_str == NULL)
			return(-1);
	return (0);
}

int	manage_storage(char **rtn, char **stor)
{
	int		n_pos;
	char 	*swap;

	swap = NULL;
	if (stor && *stor) 
	{
		
		n_pos = check_n(*stor);
		*rtn = join_str(NULL, *stor, n_pos);
		if (*rtn == NULL)
			return (-1);	
		if (n_pos > -1)
		{
			swap = join_str(NULL, &(*stor)[n_pos + 1], -1);
			my_free(stor, NULL, NULL);
			if (swap == NULL)
				return (-1);
			*stor = swap;
			return (1);
		}
		else
			my_free(stor, NULL, NULL);
	}
	return (0);
}

int	get_read(int fd, char **read_str)
{
	long	nb;

	if (!(*read_str))
	{
		*read_str = (char *) malloc ( (BUFFER_SIZE + 1) * sizeof (char));
		if (!read_str)
			return (-1);
	}
	nb = read(fd, *read_str, BUFFER_SIZE);
	if (nb == -1 || nb == 0)
		my_free(read_str, NULL, NULL);
	else
		*read_str = join_str(*read_str, "\0", 1);
	return (nb);
}

int	read_line(int fd, char **read_str, char **rtn)
{
	long	nb;
	long	n_pos;

	nb = BUFFER_SIZE;
	n_pos = -1;

	while ((n_pos == -1 && nb == BUFFER_SIZE))
	{
		nb = read(fd, *read_str, BUFFER_SIZE);	
		if (nb == -1)
			return (-1);
		if (nb == 0) 
			return (1);
		n_pos = check_n(*read_str);
		*rtn = join_str(*rtn, *read_str, n_pos);
		if (*rtn == NULL)
			return (-1);
	}
	return (0);
}

int save_storage(char **storage, char **read_str)
{
	int	n_pos;

	n_pos = check_n (*read_str);
	*storage = join_str(NULL, &(*read_str)[n_pos + 1], -1);
	if (*storage == NULL)
		return (-1);
	return (0);

}
char	*get_next_line(int fd)
{
	static char		*storage = NULL;
	char			*rtn;
	char			*read_str;
	int				i_rtn;

	if (init(&rtn, &read_str, &i_rtn, fd) == -1)
		return (NULL);
	i_rtn = manage_storage (&rtn, &storage);
	if (i_rtn == 1)
	{
		my_free(&read_str, NULL, NULL);
		return (rtn);
	}
	else if (i_rtn == -1)
	{
		my_free(&storage, &read_str, NULL);
		return (NULL);
	}
	i_rtn = read_line(fd, &read_str, &rtn);
	if (i_rtn == 1)
	{
		my_free(&read_str, NULL, NULL);
		return (rtn);
	} 
	else if (i_rtn == -1)
	{
		my_free(&read_str, NULL, NULL);
		return (NULL);
	}
	if (save_storage(&storage, &read_str) == -1)
	{
		my_free(&read_str, NULL, NULL);
		return (NULL);
	}
	my_free(&read_str, NULL, NULL);
	return (rtn);
}
