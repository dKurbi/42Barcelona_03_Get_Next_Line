/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:59:14 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/07/20 18:52:24 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
int		len_str(char *str);
char	*join_str(char *o_str, char *s_str, int lo);
int		check_n(char *str);
int		manage_storage(char **rtn, char **stor);
void	my_free(char **str1, char **str2, char **str3);
int		get_read(int fd, char **read_str);
int		save_storage(char **storage, char **read_str);
int		read_line(int fd, char **read_str, char **rtn);
int		get_read(int fd, char **read_str);

#endif