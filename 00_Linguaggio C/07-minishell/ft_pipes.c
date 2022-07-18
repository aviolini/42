/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 10:19:55 by fgradia           #+#    #+#             */
/*   Updated: 2021/08/04 10:04:46 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_minishell.h"

int	ft_init_pipes(char *line, int ***fd_pipes, t_data *data)
{
	int	x;
	int	num_pipes;

	num_pipes = ft_cntwrds(line, '|') - 1;
	(*fd_pipes) = (int **)malloc(sizeof(int *) * num_pipes);
	if (!(*fd_pipes))
		ft_exit(strerror(errno), data);
	x = -1;
	while (++x < num_pipes)
	{
		(*fd_pipes)[x] = (int *)malloc(sizeof(int) * 2);
		if (!(*fd_pipes)[x])
			ft_exit(strerror(errno), data);
	}
	x = -1;
	while (++x < num_pipes)
		if (pipe((*fd_pipes)[x]) == -1)
			ft_exit(strerror(errno), data);
	return (num_pipes);
}

void	ft_exec_pipes(char *line, t_data *data)
{
	int		num_pipes;
	int		i;
	int		**fd_pipes;
	char	**matr;
	int		pid;
	int		status;

	matr = ft_split(line, '|');
	if (!matr)
		ft_exit(strerror(errno), data);
	if (!matr[1])
	{
		ft_exec_cmd(matr[0], data);
		free(line);
		free(matr[1]);
		free(matr);
	}
	num_pipes = ft_init_pipes(line, &fd_pipes, data);
	i = -1;
	while (++i <= num_pipes)
	{
		pid = fork();
		if (pid == -1)
			ft_exit(strerror(errno), data);
		if (pid == 0)
		{
			if (i != 0 && dup2(fd_pipes[i - 1][0], 0) == -1)
				ft_exit(strerror(errno), data);
			if (i != num_pipes && dup2(fd_pipes[i][1], 1) == -1)
				ft_exit(strerror(errno), data);
			ft_close_all_fd_pipe(fd_pipes, num_pipes);			
			ft_exec_cmd(matr[i], data);
			ft_free_pipes(fd_pipes, num_pipes);
			ft_exit_num(errno, data);
		}
		if (i != 0 && (close(fd_pipes[i - 1][0]) == -1))
			ft_exit(strerror(errno), data);
		if (i != num_pipes && (close(fd_pipes[i][1]) == -1))
			ft_exit(strerror(errno), data);
		if (waitpid(pid, &status, 0) == -1)
			ft_exit(strerror(errno), data);
		if (!WIFSIGNALED(status))
			errno = status;
		status = WEXITSTATUS(status);
		if (status)
			errno = status;
	}
	ft_free_pipes(fd_pipes, num_pipes);
	if (dup2(data->std_fd[0], 0) == -1 || dup2(data->std_fd[1], 1) == -1)
		ft_exit(strerror(errno), data);
	ft_free_matrix(&matr);
	free(line);
	tcsetattr(0, 0, &data->my_term);
}

void	ft_free_pipes(int **pipes, int num)
{
	int	i;

	i = -1;
	while (++i < num)
		free((pipes)[i]);
	free(pipes);
}

int	ft_close_all_fd_pipe(int **fd_pipe, int num)
{
	int	i;

	i = -1;
	while (++i < num)
	{
		close(fd_pipe[i][0]);
		close(fd_pipe[i][1]);
	}	
	return (0);
}

