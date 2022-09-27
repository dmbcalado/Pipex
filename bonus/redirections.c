/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinhosujo <ratinhosujo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:34:57 by dmendonc          #+#    #+#             */
/*   Updated: 2022/09/27 18:57:45 by ratinhosujo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	handle_redirections(t_info *info, char **argv, int argc)
{
	if (check_if_heredoc(argv, "heredoc") < 0)
		info->ffd[0] = open (argv[1], O_RDONLY);
	else
	{
		save_key(info, argv[2]);
		info->ffd[0] = open (".heredoc", O_CREAT | O_TRUNC | O_RDWR, 0644);
		heredoc(info, argv, argc);
	}
	if (check_if_append(info, argv, argc) < 0)
		info->ffd[1] = open (argv[argc - 1], O_CREAT | O_TRUNC | O_RDWR, 0644);
	else
		info->ffd[1] = open (argv[argc - 1], O_CREAT | O_APPEND | O_RDWR, 0644);
}

int	check_if_heredoc(char **argv, char *str)
{
	int	i;

	i = -1;
	while (argv[1][++i])
	{
		if (argv[1][i] != str[i])
			return (-1);
	}
	return (1);
}
