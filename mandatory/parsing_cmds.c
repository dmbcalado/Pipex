/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 23:40:02 by dmendonc          #+#    #+#             */
/*   Updated: 2022/09/30 17:07:28 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
// -----------------------------------------------------------------------------
// Function allocates the cmdx triple pointer and gives its values. Also
// allocates the path_cmd, that later will save the path to the executable.
// -----------------------------------------------------------------------------

void	parsing_cmds(t_info *info, char **argv, int argc)
{
	int	i;

	info->argc = argc;
	info->cmd_nbr = argc - 3;
	info->cmdx = (char ***)malloc((info->cmd_nbr + 1) * sizeof(char **));
	info->path_cmd = (char **)malloc((info->cmd_nbr + 1) * sizeof(char *));
	info->cmdx[info->cmd_nbr] = NULL;
	info->path_cmd[info->cmd_nbr] = NULL;
	i = -1;
	while (++i < info->cmd_nbr)
		info->cmdx[i] = spliting(argv[i + 2], ' ');
}

// -----------------------------------------------------------------------------
// Function tests with the env paths where is the executable file of the command
// 					and stores the path/cmd in path_cmd.
// -----------------------------------------------------------------------------

int	acessing_cmd(t_info *info, int index)
{
	int	i;
	int	c;
	int	ret;

	i = -1;
	c = 0;
	while (info->paths[c])
		c++;
	while (++i < c)
	{
		path_join(info, index, i);
		ret = access(info->path_cmd[index], X_OK);
		if (ret == 0)
			return (1);
		else
			free (info->path_cmd[index]);
	}
	return (0);
}
