/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:45:13 by ppiques           #+#    #+#             */
/*   Updated: 2021/11/09 16:57:50 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_pipex(void)
{
	char *error;

	error = strerror(errno);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd(error_msg, 2);
	ft_putstr_fd("\n", 1);
	exit(errno);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	*pipex;

	pipex = malloc_pipex(argc);
	parsing(pipex, argc, argv, env);
	run_pipeline(pipex, env);
	free_pipex(pipex);

	return(0);
}