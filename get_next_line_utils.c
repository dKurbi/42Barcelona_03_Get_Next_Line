/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:46:39 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/07/20 19:46:55 by dkurcbar         ###   ########.fr       */
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
	j_str = NULL;
	if (lo == -1)
		size = len_str(o_str) + len_str(s_str);
	else
		size = len_str(o_str) + lo;
	j_str = (char *) malloc((size + 1) * sizeof (char));
	if (j_str == NULL)
		return (NULL);
	while (o_str != NULL && o_str[i])
	{
		j_str[i] = o_str[i];
		i++;
	}
	while (i <= size && s_str != NULL)
		j_str[i++] = s_str[j++];
	j_str[i] = '\0';
	my_free(&o_str, NULL, NULL);
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


void	my_free(char **str1, char **str2, char **str3)
{
	if (str1 != NULL && *str1 != NULL)
	{
		free(*str1);
		*str1 = NULL;
	}
	if (str2 != NULL && *str2 != NULL)
	{
		free(*str2);
		*str2 = NULL;
	}
	if (str3 != NULL && *str3 != NULL)
	{
		free(*str3);
		*str3 = NULL;
	}
}

