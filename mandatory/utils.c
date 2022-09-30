/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:20:23 by dmendonc          #+#    #+#             */
/*   Updated: 2022/09/30 16:51:33 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// -----------------------------------------------------------------------------
// Function function that compares the command with another string. ex: ls.
// -----------------------------------------------------------------------------

int	compare(char *s1, char *s2, int len)
{
	int	i;

	i = -1;
	while (++i < len)
	{
		if (s2[i] != s1[i] && s1[i] != 0)
			return (i);
	}
	i = -1;
	while (++i < len)
	{
		if (s1[i] != s2[i] && s1[i] != 0)
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
	while (info->cmdx[index][0][j] != 0)
		j++;
	return (i + j);
}

// -----------------------------------------------------------------------------
// Function outputs any failure or bad execution in the program.
// -----------------------------------------------------------------------------

void	safeties(int argc, int saf)
{
	if (argc < 5)
	{
		ft_printf("You need to imput :\n./pipex infile cmd1 cmd2\
... outfile\n ");
		exit(EXIT_FAILURE);
	}
	if (saf == 1)
	{
		ft_printf("Open on infile or outfile error.");
		exit(EXIT_FAILURE);
	}
	if (saf == 2)
	{
		ft_printf("Outfile reading error.");
		exit(EXIT_FAILURE);
	}
	if (saf == 3)
	{
		ft_printf("Error detected in the creation of the pipe.");
		exit(EXIT_FAILURE);
	}
	if (saf == 4)
	{
		ft_printf("Error detected in the creation of the fork.");
		exit(EXIT_FAILURE);
	}
}

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
