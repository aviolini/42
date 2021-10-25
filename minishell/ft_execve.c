/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 11:22:46 by aviolini          #+#    #+#             */
/*   Updated: 2021/08/04 10:28:01 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_minishell.h"

void	ft_do_execve(char *line, t_data *data)
{
	int	pid;
	int	status;

	pid = fork();
	if (pid == -1)
		ft_exit(strerror(errno), data);
	if (pid == 0)
	{
		execve(data->args[0], data->args, data->envp);
		ft_execve_failed(line, data);
	}
	else
	{
		ft_free_matrix(&data->args);
		g_pid = pid;
		signal(SIGQUIT, ft_sign_ign_quit);
		signal(SIGINT, ft_sign_ign_int);
		signal(SIGCHLD, ft_kill_child);
		waitpid(pid, &status, 0);
		if (!WIFSIGNALED(status))
			errno = status;
		pid = WEXITSTATUS(status);
		if (pid)
			errno = pid;
	}
}

int	ft_is_a_loc_com(t_data *data)
{
	char		*path;
	struct stat	fd_stat;

	path = getcwd(NULL, 0);
	ft_strjoin_over(&path, "/");
	ft_strjoin_over(&path, data->args[0]);
	if (!stat(path, &fd_stat))
	{
		free(data->args[0]);
		data->args[0] = ft_strdup(path);
		free(path);
		return (1);
	}
	free(path);
	return (0);
}

char	*ft_search_path(int len, t_data *data)
{
	t_read	*tmp;

	tmp = *data->env_head;
	while (tmp)
	{
		if (tmp && !ft_strncmp("PATH", tmp->line, len)
			&& (!ft_strncmp("PATH", tmp->line, len + 1)
				|| ft_strncmp("PATH", tmp->line, len + 1) == -61))
		{
			return (tmp->line + 5);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

int	ft_is_a_sys_com(t_data *data)
{
	char		*path;
	int			i;
	char		**path_matrix;
	struct stat	fd_stat;

	path = ft_search_path(4, data);
	if (!path)
		return (1);
	path_matrix = ft_split(path, ':');
	i = -1;
	while (path_matrix[++i])
	{	
		path = ft_strjoin(path_matrix[i], "/");
		ft_strjoin_over(&path, data->args[0]);
		if (!stat(path, &fd_stat))
		{
			free(data->args[0]);
			data->args[0] = ft_strdup(path);
			free(path);
			ft_free_matrix(&path_matrix);
			return (1);
		}
		free(path);
	}
	return (ft_free_matrix(&path_matrix));
}

int	ft_check_execve(char *line, t_data *data)
{
	int			r;
	struct stat	fd_stat;

	r = 0;
	if (line)
		data->args = ft_split(line, ' ');
	if (ft_strchr('/', data->args[0]) == 0)
	{
		if (!stat(data->args[0], &fd_stat))
			r = 1;
		else
			r = 0;
	}
	else if (ft_strchr('.', data->args[0]) == 0)
	{
		if (ft_is_a_loc_com(data))
			r = 1;
	}
	else if (ft_is_a_sys_com(data))
		r = 1;
	if (r == 0)
		ft_free_matrix(&data->args);
	return (r);
}

void	ft_sign_ign_quit(int sig)
{
	ft_write_2("Quit: 3");
	errno = 128 + sig;
}

void	ft_sign_ign_int(int sig)
{
	ft_write("\n");
	errno = 128 + sig;
}

void	ft_kill_child(int sig)
{
	kill(g_pid, SIGTERM);
	if (!errno)
		errno = 128 + sig;
}

void	ft_execve_failed(char *line, t_data *data)
{
	dup2(data->std_fd[1], 1);
	dup2(data->std_fd[0], 0);
	ft_write_2(strerror(errno));
	ft_free_matrix(&data->args);
	free(line);
	ft_exit_num(126, data);
}