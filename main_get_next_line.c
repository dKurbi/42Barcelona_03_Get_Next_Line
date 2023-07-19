/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:45:48 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/07/19 16:07:23 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main (void)
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
	while (str != NULL)
	{
			printf("%d > %s", i, str );
			str = get_next_line(fd);
			i++;
	}
	close(fd);
} 