/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:06:05 by aviolini          #+#    #+#             */
/*   Updated: 2021/06/07 10:57:01 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	pid_t		pid;
	t_data		all;
	int			status;

	all.com_matrix = NULL;
	all.path = NULL;
	if (ac != 5)
		ft_exit_strerror(EINVAL, &all);
	if (pipe(all.fd_pipe) == -1)
		ft_exit_perror("Error pipe", &all);
	pid = fork();
	if (pid == -1)
		ft_exit_perror("Error fork", &all);
	else if (pid == 0)
		ft_command_one(av, env, &all);
	else
	{
		wait(&status);
		ft_command_two(av, env, &all);
	}
	return (0);
}

void	ft_do_execve(char *command, t_data *all, char **env)
{
	int	fd;

	if (ft_strchr(command, '/') == 0)
	{
		fd = open(all->com_matrix[0], O_RDONLY);
		if (fd > 0)
		{
			close(fd);
			all->path = ft_strdup(all->com_matrix[0]);
		}
		else
			ft_exit_perror(all->com_matrix[0], all);
	}
	else if (ft_strchr(command, '.') == 0)
	{
		if (!ft_is_a_local_command(env, all))
			ft_exit_perror(all->com_matrix[0], all);
	}
	else if (!ft_is_a_system_command(env, all))
		ft_exit_perror(all->com_matrix[0], all);
	execve(all->path, all->com_matrix, env);
	ft_exit_perror("Error exec command", all);
}

void	ft_command_one(char **av, char **env, t_data *all)
{
	close(all->fd_pipe[0]);
	if (dup2(all->fd_pipe[1], 1) < 0)
		ft_exit_perror("Error file descriptor", all);
	close(all->fd_pipe[1]);
	all->fd_in = open(av[1], O_RDONLY);
	if (all->fd_in < 0)
		ft_exit_perror("Error file descriptor", all);
	if (dup2(all->fd_in, 0) < 0)
		ft_exit_perror("Error file descriptor", all);
	close(all->fd_in);
	all->com_matrix = ft_split(av[2], ' ');
	ft_do_execve(av[2], all, env);
}

void	ft_command_two(char **av, char **env, t_data *all)
{
	close(all->fd_pipe[1]);
	if (dup2(all->fd_pipe[0], 0) < 0)
		ft_exit_perror("Error file descriptor", all);
	close(all->fd_pipe[0]);
	all->fd_out = open(av[4], O_RDWR | O_TRUNC | O_CREAT, 0666);
	if (all->fd_out < 0)
		ft_exit_perror("Error file descriptor", all);
	if (dup2(all->fd_out, 1) < 0)
		ft_exit_perror("Error file descriptor", all);
	close(all->fd_out);
	all->com_matrix = ft_split(av[3], ' ');
	ft_do_execve(av[3], all, env);
}
