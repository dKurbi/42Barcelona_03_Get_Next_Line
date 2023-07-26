/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:45:48 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/07/26 16:53:16 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main (void)
{
	char	*dict;
	int		fd;
	char 	*str;
	
	dict = "readme.txt";
	fd = open(dict, O_RDONLY);
	if (fd == -1)
		return (1);
	str = "El fichero Readme.txt contiene:";
	printf("%s\n------------------------------------------------------------------\n",str);
	while (str != NULL)
	{
			str = get_next_line(fd);
			printf("%s",str);
	}
	close(fd);
} 
