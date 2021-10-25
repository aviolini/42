/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 11:55:46 by aviolini          #+#    #+#             */
/*   Updated: 2021/08/04 10:29:24 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_minishell.h"

void	ft_print_env(t_read **head)
{
	t_read	*tmp;

	tmp = *head;
	while (tmp)
	{
		if (!ft_strstr("=''", tmp->line))
		{	
			ft_write(tmp->line);
			ft_write("\n");
		}
		tmp = tmp->next;
	}
}

void	ft_unset(char *line, t_data *data)
{
	int		len;
	int		x;
	char	**matr;

	len = 0;
	x = 0;
	while (line[x] == ' ')
		x++;
	while (line[x + len] && (line[x + len] != ' ' && line[x + len] != '='))
		len++;
	if (!line[x])
		return ;
	matr = ft_split(line + x, ' ');
	x = 0;
	while (matr[x])
	{
		len = 0;
		while (matr[x][len] && (matr[x][len] != ' ' && matr[x][len] != '='))
			len++;
		ft_search_env(matr[x], len, data);
		ft_list_to_matr(data->env_head, &data->envp, data);
		free(matr[x]);
		x++;
	}
	free(matr);
}

void	ft_env(char *line, t_data *data)
{
	int	x;

	x = 0;
	while (line[x] && line[x] == ' ')
		x++;
	if (!line[x])
		ft_print_env(data->env_head);
	else
	{
		ft_write("bad option or too many arguments\n");
		errno = 1;
	}
}

void	ft_export(char *line, t_data *data)
{
	int	x;

	x = 0;
	while (line[x] && line[x] == ' ')
		x++;
	if (!line[x])
	{
		ft_print_sort(data->env_head, data);
		return ;
	}
	ft_matrline(line + x, data);
}

void	ft_get_env(char **env, t_data *data)
{
	int		x;
	t_read	*new;

	x = 0;
	while (env[x])
	{
		new = (t_read *)malloc(sizeof(t_read) * 1);
		new->line = ft_strdup(env[x]);
		new->pos = 1;
		new->next = NULL;
		ft_append_read(new, data->env_head);
		x++;
	}
	data->env_len = x;
	data->envp = (char **)malloc(sizeof(char *) * (x + 1));
	x = 0;
	while (x < data->env_len)
	{
		data->envp[x] = env[x];
		x++;
	}
	data->envp[x] = NULL;
}

char	*ft_itoa_errno(int num)
{
	char	*new;
	int		tmp;
	int		x;

	tmp = num;
	x = 3;
	while (tmp > 10)
	{
		tmp /= 10;
		x++;
	}
	new = (char *)malloc(sizeof(char) * (x + 1));
	new[x--] = '\0';
	while (num >= 10)
	{
		new[x--] = num % 10 + 48;
		num /= 10;
	}
	new[x--] = num + 48;
	while (x)
		new[x--] = ' ';
	return (new);
}

void	ft_list_to_matr(t_read **env_head, char ***envp, t_data *data)
{
	char	**new;
	t_read	*tmp;
	int		x;

	x = 0;
	tmp = *env_head;
	new = (char **)malloc(sizeof(char *) * (data->env_len + 1));
	while (tmp)
	{
		new[x] = tmp->line;
		x++;
		tmp = tmp->next;
	}	
	new[x] = NULL;
	free(*envp);
	*envp = new;
}

void	ft_fix_env(char **line)
{
	int		x;
	int		len;
	char	*fixed;

	x = 0;
	len = ft_strlen(*line);
	if ((*line)[len - 1] == '=')
		(*line)[--len] = '\0';
	fixed = (char *)malloc(sizeof(char) * (len + 4));
	len = 0;
	while ((*line)[len + x])
	{
		while ((*line)[len + x] == ' ')
			len++;
		if (!(*line)[len + x])
			break ;
		fixed[x] = (*line)[len + x];
		x++;
	}
	fixed[x++] = '=';
	fixed[x++] = '\'';
	fixed[x++] = '\'';
	fixed[x] = '\0';
	*line = fixed;
}

int	ft_search_env(char *line, int len, t_data *data)
{
	t_read	*tmp;
	t_read	*tmp_x;

	tmp = *data->env_head;
	tmp_x = tmp;
	if (!ft_strncmp(line, tmp->line, len)
		&& !ft_strncmp(line, tmp->line, len + 1))
	{
		*data->env_head = (*data->env_head)->next;
		return (ft_free_env(tmp, data));
	}
	while (tmp)
	{
		tmp_x = tmp;
		tmp = tmp->next;
		if (tmp && !ft_strncmp(line, tmp->line, len)
			&& (!ft_strncmp(line, tmp->line, len + 1)
				|| ft_strncmp(line, tmp->line, len + 1) == -61))
		{
			tmp_x->next = tmp->next;
			return (ft_free_env(tmp, data));
		}
	}
	return (0);
}

void	ft_add_env(char *line, int fix, t_data *data)
{
	t_read	*new;

	new = (t_read *)malloc(sizeof(t_read) * 1);
	new->line = ft_strdup(line);
	new->next = NULL;
	ft_unset(line, data);
	if (fix)
	{
		free(line);
	}
	ft_append_read(new, data->env_head);
	data->env_len++;
	ft_list_to_matr(data->env_head, &data->envp, data);
}