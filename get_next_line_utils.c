/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:46:39 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/07/19 14:59:26 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	if (lo == -1)
		size = len_str(o_str) + len_str(s_str);
	else
		size = len_str(o_str) + lo;
	j_str = (char *) malloc((size + 1) * sizeof (char));
	while (o_str != NULL && o_str[i])
	{
		j_str[i] = o_str[i];
		i++;
	}
	while (i <= size)
		j_str[i++] = s_str[j++];
	j_str[i] = '\0';
	return (j_str);
}

int	check_n(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0' && str[i] != '\n') 
		i++;
	if (str[i] == '\0')
		return (-1);
	return (i);
}