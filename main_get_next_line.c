/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:45:48 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/07/26 18:03:17 by dkurcbar         ###   ########.fr       */
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
	str = "readme.txt";
	printf("El archivo %s contiene:\n--------------------------------------------------\n", str);
	while (str != NULL)
	{
			str = get_next_line(fd);
			if (str != NULL)	
				printf("%s",str );
	}
	close(fd);
} 
