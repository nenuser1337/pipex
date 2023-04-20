/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-oul <yait-oul@student.1337.ma >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 04:43:10 by yait-oul          #+#    #+#             */
/*   Updated: 2023/03/26 02:53:07 by yait-oul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mypipex.h"

int	main(int argc, char *argv[], char **envp)
{
	t_bipex	pipex;
	int		err;

	check_args(argc, argv);
	scriptchecking(argv[2]);
	scriptchecking(argv[3]);
	pipex.file1 = open(argv[1], O_RDONLY);
	if (pipex.file1 < 0)
	{
		message_erreur(argv[1]);
		return (1);
	}
	pipex.file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex.file2 < 0)
	{
		message_erreur(argv[4]);
		return (1);
	}
	err = pipexx(argv, envp, pipex);
	return (err);
}
