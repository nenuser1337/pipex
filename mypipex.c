/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mypipex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-oul <yait-oul@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 04:43:25 by yait-oul          #+#    #+#             */
/*   Updated: 2023/03/16 05:14:30 by yait-oul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mypipex.h"

int	pipexx(char **argv, char **envp, t_bipex pipex)
{
	int	err;

	pipex.envp = envp;
	pipex.paths = envp_path(envp);
	pipex.mypaths = ft_split(pipex.paths, ':');
	if (pipe(pipex.end_pipe) < 0)
		message_erreur("Pipe");
	send_to_pipex(pipex, argv);
	close(pipex.end_pipe[0]);
	close(pipex.end_pipe[1]);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	freeing_par(&pipex);
	err = code_exit(pipex, envp, argv);
	return (err);
}
