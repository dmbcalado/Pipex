/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 22:32:58 by dmendonc          #+#    #+#             */
/*   Updated: 2022/09/26 19:35:22 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 40
# endif
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

//	UTILS :
int		search_for_size(const char *buffer, int chr);
int		search_for_bl(char *buffer);
char	*join_buffer(char *temporary, char *buff, int size);

//	MAIN :

char	*get_next_line(int fd);
#endif