/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:03:49 by ppiques           #+#    #+#             */
/*   Updated: 2021/11/09 17:40:24 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <memory.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <errno.h>

typedef struct	s_pipex
{
	int	cmd;
	int	path;
	int	pipe;
	int	fd1;
	int	fd2;
	int **pipes;
	char	**paths;
	char	**cmds1;
	char	**cmds2;
	char	**args;
	pid_t	*child;
}				t_pipex;

void	error_pipex(void);
void	parsing(t_pipex *pipex, int argc, char **argv, char **env);
void	bonus_parsing(t_pipex *pipex, int argc, char **argv, char **env);
void	normal_parsing(t_pipex *pipex, int argc, char **argv, char **env);
void	open_files(t_pipex *pipex, char *file1, char file2);
void	pipe_create(t_pipex *pipex);
void	child_create(t_pipex *pipex);
void	delete_pipex(t_pipex pipex);
void	free_pipex(t_pipex *pipex);
void	parse_cmd(t_pipex *pipex, int argc, char **argv, char ***env);
void	await_children(t_pipex *pipex);
void	run_pipeline(t_pipex *pipex, char **env);
void	run_first_cmd(t_pipex *pipex, char **env);
void	check_here_doc_parent(t_pipex *pipex);
void	check_here_doc_child(t_pipex *pipex);
void	run_middle_cmd(t_pipex *pipex, char **env);
void	run_last_cmd(t_pipex *pipex);
void	cmd_handler(t_pipex *pipex);
void	bonus_here_doc_parsing(t_pipex *pipex, int argc,
								char **argv, char **env);
void	bonus_here_doc_stdin(t_pipex *pipex);
void	bonus_here_doc_open(t_pipex *pipex, char *file2);
int		first_cmd_check(t_pipex *pipex);
int		find_path_line(char**env);
void	parse_env(t_pipex *pipex, char **env);
char	*ft_strjoinfree(char *s1, char *s2,
						int free_s1, int free_s2);
char	*ft_strappend(char *s1, char *s2, int free_s1, int free_s2);
t_pipex	*malloc_pipex(void);
t_pipex	initialize(void);


#endif
