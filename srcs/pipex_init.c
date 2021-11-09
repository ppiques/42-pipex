/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:47:56 by ppiques           #+#    #+#             */
/*   Updated: 2021/11/09 17:49:37 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_pipex	*malloc_pipex(int argc)
{
	t_pipex *pipex;

	if (argc != 5)
		error_pipex();
	pipex = (t_pipex *)malloc(sizeof(t_pipex));
	if (!pipex)
		error_pipex();
	*pipex = initialize();
	return (pipex);
}

t_pipex initialize(void)
{
	t_pipex pipex;

	ft_memset(&pipex, 0, sizeof(t_pipex));
	pipex.cmds = NULL;
	pipex.child = NULL;
	pipex.paths = NULL;
	pipex.args = NULL;
	pipex.pipe = NULL;
	return (pipex);
}

t_pipex get_cmds(t_pipex *pipex, int **argv)
{
	pipex.cmds1 = ft_split(argv[2], ' ');
	pipex.cmds2 = ft_split(argv[3], ' ');
	return (pipex);
}

t_pipex get_path(t_pipex *pipex, char **env)
{
	int	i;
	char *temp;

	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH", 4))
		{
			temp = ft_strchr(env[i], '/');
			pipex.paths = ft_split(temp, ':')
			break ;
		}
		i++;
	}
	return (pipex);
}