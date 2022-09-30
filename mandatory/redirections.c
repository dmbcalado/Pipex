/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:34:57 by dmendonc          #+#    #+#             */
/*   Updated: 2022/09/30 19:54:29 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	redirect_fds(int infd, int outfd)
{
	dup2 (infd, STDIN_FILENO);
	dup2 (outfd, STDOUT_FILENO);
}

int	compare_paths(char *s1, char *s2)
{
	int	i;

	i = -1;
	while (s2[++i])
	{
		if (s1[i] != s2[i])
			return (i);
	}
	i = -1;
	return (-2);
}
