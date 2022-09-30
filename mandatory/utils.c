/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:20:23 by dmendonc          #+#    #+#             */
/*   Updated: 2022/09/30 17:03:07 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// -----------------------------------------------------------------------------
// Function that compares the command with another string. ex: ls.
// -----------------------------------------------------------------------------

int	compare(const char *s1, const char *s2)
{
	int	i;

	i = -1;
	while (s2[++i])
	{
		if (s1[i] != s2[i] && s2[i] != s1[i] - 32)
			return (i);
	}
	return (-2);
}

// -----------------------------------------------------------------------------
// Function counts how many paths.
// -----------------------------------------------------------------------------

int	how_many_paths(char const *s, char c)
{
	int	i;
	int	flag;
	int	how_many;

	i = 0;
	flag = 0;
	how_many = 0;
	while (s[i] != '\0')
	{
		while (!(s[i] == '\0' || s[i] == c))
		{
			i++;
			flag = 1;
		}
		while (s[i] == c)
			i++;
		if (flag == 0)
			continue ;
		how_many++;
		if (s[i - 1] == '\0')
			break ;
	}
	return (how_many);
}

// -----------------------------------------------------------------------------
// Function returns the size of the full path to the executable file.
// -----------------------------------------------------------------------------

int	path_size(t_info *info, int index, int i_p)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (info->paths[i_p][i])
		i++;
	while (info->cmdx[index][0][j])
		j++;
	return (i + j);
}

// -----------------------------------------------------------------------------
// Function outputs any failure or bad execution in the program.
// -----------------------------------------------------------------------------

void	safeties(t_info *info, int index, int saf)
{
	if (saf == 1)
		ft_printf("Infile reading error.\n");
	if (saf == 2)
		ft_printf("%s: command not found.\n", info->cmdx[index][0]);
	if (saf == 3)
		ft_printf("Error in the creation of the pipe.\n");
	if (info->argc < 5)
		ft_printf("You need to imput :\n./pipex infile cmd1 cmd2... outfile\n");
	exit(EXIT_FAILURE);
}

// -----------------------------------------------------------------------------
// Function copys the source string to another address, the destiny.
// -----------------------------------------------------------------------------

void	stringcpy(char *dest, char *src)
{
	int	i;

	i = -1;
	while (src[++i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}
