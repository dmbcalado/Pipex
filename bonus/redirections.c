/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:34:57 by dmendonc          #+#    #+#             */
/*   Updated: 2022/09/26 19:57:50 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	handle_redirections(t_info *info, char **argv, int argc)
{
	if (check_if_heredoc(argv, "heredoc") < 0)
	{
		info->ffd[0] = open (argv[1], O_RDONLY);
		info->ffd[1] = open (argv[argc - 1], O_CREAT | O_TRUNC | O_RDWR, 0644);
	}
	else
	{
		save_key(info, argv[2]);
		heredoc(info, argv, argc);
	}
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

void	save_key(t_info *info, char *key)
{
	int	i;

	i = 0;
	while (key[i])
		i++;
	info->heredoc_key = (char *)malloc((i + 1) * sizeof(char));
	info->heredoc_key[i] = 0;
	i = -1;
	while (key[++i])
		info->heredoc_key[i] = key[i];
}

void	heredoc(t_info *info, char **argv, int argc)
{
	int		len;
	char	*buffer;

	len = len_str(info->heredoc_key);
	info->ffd[0] = open (".heredoc_temp", O_CREAT | O_TRUNC | O_RDWR, 0644);
	info->ffd[1] = open (argv[argc - 1], O_CREAT | O_APPEND | O_RDWR, 0644);
	while (1)
	{
		write(1, "> ", 2);
		buffer = get_next_line(0);
		if (buffer)
		{
			if (len == len_str(buffer) - 1)
			{
				if (compare(buffer, info->heredoc_key) < 0)
				{
					free (buffer);
					break ;
				}
			}
			write(info->ffd[1], buffer, len_str(buffer));
			free (buffer);
		}
	}
}

int	len_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
