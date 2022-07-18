/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 10:19:39 by fgradia           #+#    #+#             */
/*   Updated: 2021/08/04 10:25:38 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_minishell.h"

void	ft_cd(char *line, t_data *data)
{
	int		x;
	int		ret;
	char	*tmp;

	x = 0;
	if (!line[x])
		return ;
	while (line[x] == ' ')
		x++;
	if (ft_strchr('\'', line) == -1 || ft_strchr('\"', line) == -1)
	{
		ret = ft_strlen(line) - 1;
		while (line[ret] == ' ')
			ret--;
		line[ret + 1] = '\0';
	}
	tmp = getcwd(NULL, 0);
	if (chdir(line + x) == -1)
	{
		free(tmp);
		ft_write_2(strerror(errno));
		errno = 1;
		return ;
	}
	ft_update_pwd(tmp, data);
}

void	ft_pwd(char *line, t_data *data)
{
	char	*path;
	int		x;

	x = 0;
	while (line[x] && line[x] == ' ')
		x++;
	if (line[x] && line[x] == '-')
	{
		ft_write_2("invalid option");
		errno = 1;
		return ;
	}
	path = NULL;
	path = getcwd(NULL, 0);
	if (!path)
	{
		ft_write_2(strerror(errno));
		errno = 1;
		return ;
	}
	ft_write(path);
	ft_write("\n");
	free(path);
	(void)data;
}

void	ft_echo(char *line)
{
	int	x;
	int	new_line;

	x = 0;
	new_line = 1;
	while (line[x] == ' ')
		x++;
	ft_option_echo(&new_line, &x, line);
	while (line[x])
	{
		ft_write_echo(&x, line);
		if (!line[x])
			break ;
		write(1, &line[x], 1);
		x++;
	}
	if (new_line)
		ft_write("\n");
	errno = 0;
}

void	ft_check_cmd(char *line, t_data *data)
{
	if (line[0] == 'e')
	{
		ft_check_builtin(line, data);
		return ;
	}
	else if (!ft_strncmp(line, "cd ", 3) || ft_strncmp(line, "cd ", 3) == -32)
		ft_cd(line + 2, data);
	else if (!ft_strncmp(line, "pwd ", 4) || ft_strncmp(line, "pwd ", 4) == -32)
		ft_pwd(line + 3, data);
	else if (!ft_strncmp(line, "unset ", 6)
		|| ft_strncmp(line, "unset ", 6) == -32)
		ft_unset(line + 5, data);
	else if (!line[0] || !ft_strncmp(line, "", 1) || ft_last_spaces(line))
		return ;
	else if (ft_check_execve(line, data))
		ft_do_execve(line, data);
	else
	{
		ft_write_2("minishell: command not found");
		errno = 127;
	}
}

void	ft_exec_cmd(char *line, t_data *data)
{
	int			x;
	struct stat	t_stat;

	x = 0;
	tcsetattr(0, 0, &data->old_term);
	while (ft_strchr('$', line + x) != -1)
		ft_env_line(&line, &x, data);
	if (ft_strchr('\'', line) || ft_strchr('\"', line))
		ft_clean_quotes(&line);
	if ((ft_strchr('>', line) >= 0 || ft_strchr('<', line) >= 0)
		&& ft_redir(&line, data) == 0)
		ft_error_redir(&x);
	if (line && x != 666)
		ft_check_cmd(line, data);
	free(line);
	dup2(data->std_fd[1], 1);
	dup2(data->std_fd[0], 0);
	x = errno;
	if (!stat("/tmp/minishell", &t_stat))
		unlink("/tmp/minishell");
	errno = x;
	tcsetattr(0, 0, &data->my_term);
}

void	ft_update_pwd(char *tmp, t_data *data)
{
	char	*new;

	new = ft_strjoin("OLDPWD=", tmp);
	if (new)
		ft_add_env(new, 1, data);
	free(tmp);
	tmp = getcwd(NULL, 0);
	new = ft_strjoin("PWD=", tmp);
	ft_add_env(new, 1, data);
	free(tmp);
}

void	ft_option_echo(int *new_line, int *x, char *line)
{
	int	y;

	y = *x;
	if ((!ft_strncmp(line + *x, "-n ", 3)
			|| ft_strncmp(line + *x, "-n ", 3) == -32)
		&& !ft_strncmp(line + *x, "-n", 2))
	{
		*new_line = 0;
		*x += 3;
	}
	while (line[*x] == ' ')
		(*x)++;
	if (*x != y && line[*x] == '-' && line[*x + 1] == 'n')
		ft_option_echo(new_line, x, line);
}

void	ft_echo_quotes(int *x, char *line, char c)
{
	(*x)++;
	while (line[*x] && line[*x] != c)
	{
		write(1, &line[*x], 1);
		(*x)++;
	}
	(*x)++;
}

void	ft_write_echo(int *x, char *line)
{
	if (line[*x] == ' ' && line[*x + 1])
	{
		if (!ft_last_spaces(line + *x))
			write(1, &line[*x], 1);
		(*x)++;
	}
	while (line[*x] && line[*x] == ' ')
		(*x)++;
	if (line[*x] == 39)
	{
		ft_echo_quotes(x, line, 39);
	}
	if (line[*x] == 34)
	{
		ft_echo_quotes(x, line, 34);
	}
}

void	ft_error_redir(int *x)
{
	*x = 666;
	if (errno > 0 && errno < 102)
	{
		ft_write_2(strerror(errno));
		errno = 1;
		return ;
	}
	ft_write_2("syntax error near unexpected token");
	errno = 258;
}