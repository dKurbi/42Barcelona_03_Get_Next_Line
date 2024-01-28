/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:23:33 by dkurcbar          #+#    #+#             */
/*   Updated: 2024/01/18 16:12:53 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_storage(char **storage, char **rtn)
{
	int		nl;
	char	*s;

	s = NULL;
	nl = where_is_nl(*storage);
	if (nl > NO_NL && nl < ft_strlen(*storage))
	{
		*rtn = ft_strljoin(NULL, *storage, nl);
		if (!*rtn)
			return (my_free_int(storage, rtn, NULL, ERROR));
		s = *storage;
		if (nl < ft_strlen(s))
		{
			*storage = ft_strljoin(NULL, &s[nl], ALL);
			if (!*storage)
				return (my_free_int(storage, rtn, &s, ERROR));
		}
		my_free(&s, NULL, NULL);
		return (STOP);
	}
	*rtn = *storage;
	*storage = NULL;
	if (nl != NO_NL)
		return (STOP);
	return (OK);
}

static int	read_until_nl(int fd, char **b, char **line)
{
	int		nb;
	int		nl;
	char	*buffer;

	buffer = *b;
	nb = BUFFER_SIZE;
	nl = NO_NL;
	while (nb == BUFFER_SIZE && nl == NO_NL)
	{
		nb = read(fd, buffer, BUFFER_SIZE);
		if (nb < 0)
			return (ERROR);
		if (nb == 0 && !*line)
			return (STOP);
		buffer[nb] = '\0';
		nl = where_is_nl(buffer);
		*line = ft_strljoin(*line, buffer, ALL);
		if (!*line)
			return (ERROR);
	}
	return (OK);
}

int	read_line(int fd, char **line)
{
	char	*buffer;
	int		exit_code;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (ERROR);
	exit_code = read_until_nl(fd, &buffer, line);
	my_free(&buffer, NULL, NULL);
	return (exit_code);
}

int	manage_exit(char **rtn, char **line, char **storage)
{
	int		nl;
	char	*l;

	nl = where_is_nl(*line);
	*rtn = ft_strljoin(*rtn, *line, nl);
	if (!*rtn)
	{
		my_free(line, storage, NULL);
		return (ERROR);
	}
	if (nl > NO_NL && nl < ft_strlen(*line))
	{
		l = *line;
		*storage = ft_strljoin(NULL, &l[nl], -1);
		if (!*storage)
		{
			my_free(line, storage, NULL);
			return (ERROR);
		}
	}
	my_free(line, NULL, NULL);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*rtn;
	char		*line;
	int			exit_code;		

	rtn = NULL;
	line = NULL;
	exit_code = OK;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (my_free(&storage, NULL, NULL));
	if (storage)
		exit_code = check_storage(&storage, &rtn);
	if (exit_code == OK)
		exit_code = read_line(fd, &line);
	if (exit_code == OK)
		exit_code = manage_exit(&rtn, &line, &storage);
	if (exit_code == ERROR)
		return (my_free(&storage, &rtn, NULL));
	return (rtn);
}
