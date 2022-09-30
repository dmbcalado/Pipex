/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:53:40 by dmendonc          #+#    #+#             */
/*   Updated: 2022/09/30 16:51:02 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
// -----------------------------------------------------------------------------
// In the child fork, we want to separate the argv[] into "cmd" "arg1" ...
// after that, colect the paths that exist in the envp, join the paths
// with "/cmd" create a copy of infile.txt using dup2(), run the execve().
// -----------------------------------------------------------------------------

void	run_processes(t_info *info, char **envp, int index)
{
	if (acessing_cmd (info, index) == 0)
	{
		ft_printf ("%s: command not found.\n", info->cmdx[index][0]);
		exit (0);
	}
	if (pipe (info->pfd[index]) != 0)
		safeties (info->argc, 3);
	info->id = fork();
	if (info->id == 0)
	{
		close (info->pfd[index][0]);
		if (index == 0)
			redirect_fds(info->ffd[0], info->pfd[index][1]);
		else if (index == info->cmd_nbr - 1)
			redirect_fds(info->pfd[index - 1][0], info->ffd[1]);
		else
			redirect_fds (info->pfd[index - 1][0], info->pfd[index][1]);
		execve (info->path_cmd[index], info->cmdx[index], envp);
	}
	else
		run_father (info, index);
}

void	run_father(t_info *info, int index)
{
	close (info->pfd[index][1]);
	wait (NULL);
	if (info->ffd[1] == STDOUT_FILENO)
		exit(0);
	else
		dup2(info->pfd[index][0], STDIN_FILENO);
}

void	free_all(t_info *info)
{
	int	i;

	i = -1;
	free (info->p_str);
	while (info->spaths[++i])
		free (info->spaths[i]);
	free (info->spaths);
	i = -1;
	while (info->paths[++i])
		free (info->paths[i]);
	free (info->paths);
	i = -1;
	while (info->path_cmd[++i])
		free (info->path_cmd[i]);
	free (info->path_cmd);
	free_cmds (info);
}

void	free_cmds(t_info *info)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (info->cmdx[++j])
	{
		while (info->cmdx[j][++i])
			free (info->cmdx[j][i]);
		i = -1;
		free (info->cmdx[j]);
	}
	free (info->cmdx);
	i = -1;
	while (++i < info->cmd_nbr)
		free (info->pfd[i]);
	free (info->pfd);
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	t_info	info;

	parsing_paths (&info, envp);
	handle_redirections(&info, argv, argc);
	if (info.ffd[0] == -1 || info.ffd[1] == -1)
		safeties (argc, 1);
	parsing_cmds (&info, argv, argc);
	info.pfd = (int **)malloc(info.cmd_nbr * sizeof(int *));
	i = -1;
	while (++i < info.cmd_nbr)
		info.pfd[i] = (int *)malloc(2 * sizeof(int));
	i = -1;
	while (++i < info.cmd_nbr)
		run_processes (&info, envp, i);
	free_all (&info);
}
