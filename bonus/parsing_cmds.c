/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 23:40:02 by dmendonc          #+#    #+#             */
/*   Updated: 2022/09/30 16:45:30 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// -----------------------------------------------------------------------------
// Function performs the parsing of the arguments given by the user using the
// 							  function arg_copy().
// -----------------------------------------------------------------------------

void	parsing_cmds(t_info *info, char **argv, int argc)
{
	int	i;

	info->argc = argc;
	if (check_if_heredoc(argv, "heredoc") < 0)
		info->cmd_nbr = argc - 3;
	else
		info->cmd_nbr = argc - 4;
	info->cmdx = (char ***)malloc((info->cmd_nbr + 1) * sizeof(char **));
	info->path_cmd = (char **)malloc((info->cmd_nbr + 1) * sizeof(char *));
	info->cmdx[info->cmd_nbr] = NULL;
	info->path_cmd[info->cmd_nbr] = NULL;
	i = -1;
	while (++i < info->cmd_nbr)
	{
		if (check_if_heredoc(argv, "heredoc") < 0)
			info->cmdx[i] = spliting(argv[i + 2], ' ');
		else
			info->cmdx[i] = spliting(argv[i + 3], ' ');
	}
}

// -----------------------------------------------------------------------------

// Function performs the parsing of the arguments given by the user using the
// 							  function arg_copy().
// FAZ O PRETENDIDO
// -----------------------------------------------------------------------------

int	acessing_cmd(t_info *info, int index)
{
	int	i;
	int	c;
	int	ret;

	c = 0;
	i = -1;
	while (info->paths[c])
		c++;
	while (++i < c)
	{
		path_join(info, index, i);
		ret = access(info->path_cmd[index], X_OK);
		if (ret == 0)
			return (1);
		else
			free(info->path_cmd[index]);
	}
	return (0);
}

void	redirect_fds(int infd, int outfd)
{
	dup2 (infd, STDIN_FILENO);
	dup2 (outfd, STDOUT_FILENO);
}
