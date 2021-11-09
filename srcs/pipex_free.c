/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:50:34 by ppiques           #+#    #+#             */
/*   Updated: 2021/11/09 17:04:57 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	free_pipex(t_pipex *pipex)
{
	delete_pipex(*pipex);
	free(pipex);
}

void	delete_pipex(t_pipex *pipex)
{
	int	i;

	i = 0
	while (i < pipex.cmd)
	{
		ft_tab_free(pipex.args[i]);
		i++;
	}
	i = 0;
	while (i < pipex.pipe)
	{
		free(pipex.pipe[i]);
		i++;
	}
	free(pipex.args);
	free(pipex.pipe);
	ft_tab_free(pipex.env);
	ft_tab_free(pipex.cmds);
	free(pipex.child);
	ft_memset(&pipex, 0, sizeof(t_pipex));
}