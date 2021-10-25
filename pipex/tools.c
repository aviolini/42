/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 00:49:06 by arrigo            #+#    #+#             */
/*   Updated: 2021/06/07 10:43:50 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_is_a_system_command(char **env, t_data *all)
{
	char	**path_matrix;
	char	*save;
	int		fd;
	int		i;

	path_matrix = ft_all_paths(env);
	i = -1;
	while (path_matrix[++i])
	{
		all->path = ft_strjoin(path_matrix[i], "/");
		save = all->path;
		all->path = ft_strjoin(all->path, all->com_matrix[0]);
		free(save);
		fd = open(all->path, O_RDONLY);
		if (fd > 0)
		{
			close(fd);
			ft_matr_del_and_free(&path_matrix);
			return (1);
		}
		free(all->path);
	}
	all->path = NULL;
	ft_matr_del_and_free(&path_matrix);
	return (0);
}

int	ft_is_a_local_command(char **env, t_data *all)
{
	char	*get_str;
	int		fd;

	get_str = ft_get_str_from_env("PWD", env);
	if (!get_str)
		return (0);
	all->path = ft_strjoin(get_str, "/");
	free(get_str);
	get_str = all->path;
	all->path = ft_strjoin(all->path, all->com_matrix[0]);
	free(get_str);
	fd = open(all->path, O_RDONLY);
	if (fd > 0)
	{
		close(fd);
		return (1);
	}
	free(all->path);
	all->path = NULL;
	return (0);
}

char	*ft_get_str_from_env(char *to_find, char **env)
{
	char	*str;
	int		i;
	int		x;

	i = -1;
	str = NULL;
	while (env[++i])
	{
		if (ft_strstr(env[i], to_find))
		{
			x = ft_strchr(env[i], '=');
			if (x == -1)
				return (NULL);
			str = ft_substr(env[i], ++x, ft_strlen(env[i]));
			break ;
		}
	}
	return (str);
}

char	**ft_all_paths(char **env)
{
	char	*get_str;
	char	**path_matrix;

	get_str = ft_get_str_from_env("PATH", env);
	if (!get_str)
		return (0);
	path_matrix = ft_split(get_str, ':');
	free(get_str);
	return (path_matrix);
}
