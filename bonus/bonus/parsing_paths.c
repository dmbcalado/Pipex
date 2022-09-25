/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:13:18 by dmendonc          #+#    #+#             */
/*   Updated: 2022/08/25 18:10:16 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// ----------------------------------------------------------------------------

// Function trims the beggining of the envp[i] = PATH:(...)

// ----------------------------------------------------------------------------

void	path_str(t_info *info, char **envp)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	j = -1;
	k =  4;
	while(envp[++i] != 0)
	{
		if (compare(envp[i], "PATH") == -2)
			break;
	}
	while(envp[i][++j]);
	info->p_str = malloc((j + 1) * sizeof(char));
	while(envp[i][++k] != 0)
		info->p_str[k - 5] = envp[i][k];
	info->p_str[k - 5] = '\0';
}

// ----------------------------------------------------------------------------

// Function ataches the bar '/' to the paths.

// ----------------------------------------------------------------------------

void	joinbar(t_info *info, int index)
{
	int		i;

	i = -1;
	while(info->spaths[index][++i]!= '\0');
	info->paths[index] = (char *)malloc((i + 2) * sizeof(char));
	i = -1;
	while(info->spaths[index][++i])
		info->paths[index][i] = info->spaths[index][i];
	info->paths[index][i] = '/';
	info->paths[index][i + 1] = '\0';
}

// -----------------------------------------------------------------------------

// Function uses path_returner() to colect the PATH from the envp given by the
// the environment, and uses split to get each path seperatly. After that stores
// in info->paths each seperate path with '/' atached. ex: /usr/bin/

// -----------------------------------------------------------------------------

void	parsing_paths(t_info *info, char **envp)
{
	int	i;
	
	i = -1;
	path_str(info, envp);
	info->spaths = spliting(info->p_str, ':');
	info->paths = (char **)malloc((how_many_paths(info->p_str, 58) + 1) * sizeof(char *));
	while(info->spaths[++i])
		joinbar(info, i);
	info->paths[i] = NULL;
}

// -----------------------------------------------------------------------------

// Function joins the path/ with the command.

// -----------------------------------------------------------------------------

void	path_join(t_info *info, int index, int i_p)
{
	int		i;
	int		j;

	i = -1;
	j = -1;

	info->path_cmd[index] = (char *)malloc((path_size(info, index, i_p) + 1)* sizeof(char));
	while(info->paths[i_p][++i])
		info->path_cmd[index][i] = info->paths[i_p][i];
	info->path_cmd[index][0] = '/';
	while(info->cmdx[index][0][++j])
		info->path_cmd[index][i++] = info->cmdx[index][0][j];
	info->path_cmd[index][i] = '\0';
}

