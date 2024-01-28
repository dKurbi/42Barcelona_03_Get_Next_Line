/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:59:14 by dkurcbar          #+#    #+#             */
/*   Updated: 2024/01/28 21:11:38 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42 
# endif
# define OK 0
# define ERROR -1
# define NO_NL -1
# define STOP 1
# define ALL -1
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

char	*get_next_line(int fd);
int		manage_exit(char **rtn, char **line, char **storage);

//UTILS
int		ft_strlen(char *str);
int		where_is_nl(char *str);
char	*my_free(char **str1, char **str2, char **str3);
int		my_free_int(char **str1, char **str2, char **str3, int rtn);
char	*ft_strljoin(char *str1, char *str2, int len);

#endif
