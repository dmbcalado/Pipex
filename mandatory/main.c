/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:53:40 by dmendonc          #+#    #+#             */
/*   Updated: 2022/09/30 17:23:08 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// -----------------------------------------------------------------------------
// In the child fork, we want to separate the argv[] into "cmd" "arg1" ...
// after that, colect the paths that exist in the envp, join the right path
// with "/cmd", use dup2() to manipulate the file descriptors & run the execve()
// -----------------------------------------------------------------------------

void	run_processes(t_info *info, char **envp, int index)
{
	if (acessing_cmd (info, index) == 0)
		safeties(info, index, 2);
	if (pipe (info->pfd) != 0)
		safeties (info, index, 3);
	info->id = fork();
	if (info->id == 0)
	{
		close (info->pfd[0]);
		if (index == 1)
		{
			dup2 (info->pfd[0], STDIN_FILENO);
			dup2 (info->ffd[1], STDOUT_FILENO);
			execve (info->path_cmd[index], info->cmdx[index], envp);
		}
		else
		{
			dup2 (info->ffd[0], STDIN_FILENO);
			dup2 (info->pfd[1], STDOUT_FILENO);
			execve (info->path_cmd[index], info->cmdx[index], envp);
		}
	}
	else
		run_father (info);
}

// -----------------------------------------------------------------------------
// In the FATHER fork, we want to wait for the child to finish executing,
// and if its the last command, free all and exit.
// -----------------------------------------------------------------------------

void	run_father(t_info *info)
{
	close (info->pfd[1]);
	wait (NULL);
	if (info->ffd[1] == STDOUT_FILENO)
	{
		free_all(info);
		exit(0);
	}
}

// -----------------------------------------------------------------------------
// In the main function we want to parse the paths from the envoirnment, then 
// parse the commands given, use open to read the input file, and create/ 
// truncate/ read&write to an output file. check if open() ran smothly, then
// start running the processes in the run_processes().
// -----------------------------------------------------------------------------

int	main(int argc, char **argv, char **envp)
{
	int		i;
	t_info	info;

	i = -1;
	parsing_paths (&info, envp);
	parsing_cmds (&info, argv, argc);
	info.ffd[0] = open(argv[1], O_RDONLY);
	info.ffd[1] = open(argv[argc - 1], O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (info.ffd[0] == -1 || info.ffd[1] == -1)
		safeties(&info, 0, 1);
	while (++i < info.cmd_nbr)
		run_processes(&info, envp, i);
}

// -----------------------------------------------------------------------------
// Function that frees all remaining information.
// -----------------------------------------------------------------------------

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

// -----------------------------------------------------------------------------
// Function that frees the cmdx triple pointer.
// -----------------------------------------------------------------------------

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
}
