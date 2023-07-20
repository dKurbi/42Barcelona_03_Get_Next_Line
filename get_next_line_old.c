/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_old.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:56:31 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/07/20 18:35:25 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_next_line(int fd)
{
	static char		*storage = NULL;
	char			*rtn;
	char			*read_str;
	long			nb;
	long			n_pos;

	rtn = NULL;
	read_str = NULL;
	n_pos = -1;
	nb = BUFFER_SIZE;

	if (fd == -1 || manage_storage (&rtn, &storage))
		return (rtn);
	
	if (n_pos > -1 && n_pos < BUFFER_SIZE )
		storage = join_str (NULL, &read_str [n_pos + 1], -1);
	my_free(&read_str, NULL, NULL);
	return (rtn);
}

