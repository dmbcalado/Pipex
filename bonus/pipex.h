/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:58:54 by dmendonc          #+#    #+#             */
/*   Updated: 2022/09/30 16:54:10 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <string.h>
# include "../gnl/get_next_line.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_info
{
	pid_t	id;
	int		flag;
	int		argc;
	int		ffd[2];
	int		**pfd;
	int		cmd_nbr;
	char	*p_str;
	char	**paths;
	char	**spaths;
	char	**cmd;
	char	***cmdx;
	char	**path_cmd;
	char	*heredoc_key;
}			t_info;

void	stringcpy(char *dest, char *src);
int		count_rows(char *s, char c);
int		find_c(char *s, char c, int index);
int		find_len(char *s, char c, int index);
char	**spliting(char *s, char c);
char	*substring(char *s, int start, int len);

//	^V^V^V^V^         UTILS          ^V^V^V^V^

int		compare_paths(char *s1, char *s2);
int		compare(char *s1, char *s2, int len);
int		how_many_paths(char const *s, char c);
void	safeties(int argc, int saf);
void	redirect_fds(int infd, int outfd);

//	^V^V^V^V^      REDIRECTIONS       ^V^V^V^V^

int		len_str(char *str);
int		check_if_heredoc(char **argv, char *str);
void	handle_redirections(t_info *info, char **argv, int argc);
void	save_key(t_info *info, char *key);
void	heredoc(t_info *info);

//	^V^V^V^V^    PARSING THE PATHS    ^V^V^V^V^

int		path_size(t_info *info, int index, int i_p);
void	path_str(t_info *info, char **envp);
void	path_join(t_info *info, int index, int i_p);
void	parsing_paths(t_info *info, char **envp);
void	joinbar(t_info *info, int index);

//	^V^V^V^V^    PARSING THE CMDS    ^V^V^V^V^

void	parsing_cmds(t_info *info, char **argv, int argc);
void	cmd_adaptation(t_info *info, char **argv);
int		acessing_cmd(t_info *info, int index);

//	^V^V^V^V^     MAIN FUNCTIONS     ^V^V^V^V^

void	run_processes(t_info *info, char **envp, int index);
void	run_father(t_info *info, int index);
void	free_cmds(t_info *info);
void	free_all(t_info *info);
#endif