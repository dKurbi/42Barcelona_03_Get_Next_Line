/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:46:39 by dkurcbar          #+#    #+#             */
/*   Updated: 2024/01/18 16:24:20 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	if (str)
	{
		i = 0;
		while (str[i])
			i++;
		return (i);
	}
	return (0);
}

int	where_is_nl(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i] && str[i] != '\n')
			i++;
		if (str[i] == '\n')
			return (i + 1);
	}
	return (-1);
}

char	*my_free(char **str1, char **str2, char **str3)
{
	if (str1 != NULL && *str1 != NULL)
	{
		free(*str1);
		*str1 = NULL;
	}
	if (str2 && *str2)
	{
		free(*str2);
		*str2 = NULL;
	}
	if (str3 && *str3)
	{
		free(*str3);
		*str3 = NULL;
	}
	return (NULL);
}

int	my_free_int(char **str1, char **str2, char **str3, int rtn)
{
	if (str1 != NULL && *str1 != NULL)
	{
		free(*str1);
		*str1 = NULL;
	}
	if (str2 && *str2)
	{
		free(*str2);
		*str2 = NULL;
	}
	if (str3 && *str3)
	{
		free(*str3);
		*str3 = NULL;
	}
	return (rtn);
}

char	*ft_strljoin(char *str1, char *str2, int len)
{
	int		i;
	int		j;
	char	*rtn;
	int		size;

	if (len < 0)
		size = ft_strlen(str1) + ft_strlen(str2);
	else
		size = ft_strlen(str1) + len;
	rtn = malloc(sizeof(char) * (size + 1));
	if (rtn)
	{
		i = 0;
		while (str1 && str1[i])
		{
			rtn[i] = str1[i];
			i++;
		}
		j = 0;
		while (str2 && str2[j] && i < size)
			rtn[i++] = str2[j++];
		rtn[i] = '\0';
	}
	my_free(&str1, NULL, NULL);
	return (rtn);
}
