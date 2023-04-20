/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-oul <yait-oul@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 04:43:57 by yait-oul          #+#    #+#             */
/*   Updated: 2023/03/16 05:42:34 by yait-oul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mypipex.h"

int	child_one(t_bipex pipex, char **argv)
{
	int	err;

	err = 77;
	if_awk(pipex, argv);
	pipex.mycmdargs = ft_split(argv[2], ' ');
	pipex.comd = pathcmmd(pipex.mypaths, pipex.mycmdargs[0], &err);
	dup2(pipex.end_pipe[1], 1);
	close(pipex.end_pipe[0]);
	dup2(pipex.file1, 0);
	close(pipex.file1);
	close(pipex.end_pipe[1]);
	if (!pipex.comd)
	{
		freeing_childs(&pipex);
		exit(1);
	}
	execve(pipex.comd, pipex.mycmdargs, pipex.envp);
	return (err);
}

int	child_two(t_bipex pipex, char **argv)
{
	int	err;

	err = 127;
	pipex.mycmdargs = ft_split(argv[3], ' ');
	pipex.comd = pathcmmd(pipex.mypaths, pipex.mycmdargs[0], &err);
	dup2(pipex.end_pipe[0], 0);
	close(pipex.end_pipe[1]);
	dup2(pipex.file2, 1);
	close(pipex.file2);
	close(pipex.end_pipe[0]);
	if (!pipex.comd)
	{
		freeing_childs(&pipex);
		exit(1);
	}
	execve(pipex.comd, pipex.mycmdargs, pipex.envp);
	return (err);
}
