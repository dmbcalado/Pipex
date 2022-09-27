/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinhosujo <ratinhosujo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:57:17 by ratinhosujo       #+#    #+#             */
/*   Updated: 2022/09/27 18:58:14 by ratinhosujo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
