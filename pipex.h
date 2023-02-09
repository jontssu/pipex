/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jole <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:05:20 by jole              #+#    #+#             */
/*   Updated: 2023/02/09 16:50:23 by jole             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>

typedef	struct	s_vars
{
	int	new[2];
	int	fd_in;
	int	fd_out;
	int	count;
	int	*pids;
}				t_vars;

char	**split_quote(char *str, int delim);
char	**add_filepath(char **argv, int cmd_i);
void	filepath_error(int *pids);
void	make_fd(int commands, t_vars *vars, int *old, char **argv);
void	child(t_vars *vars, int new[2], char **cmd, int commands);
void	parent(t_vars *vars, char **cmd);

#endif
