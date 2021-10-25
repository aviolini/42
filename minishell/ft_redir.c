/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 09:26:04 by aviolini          #+#    #+#             */
/*   Updated: 2021/08/04 10:48:13 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_minishell.h"

int	ft_type_of_redir(char *line, int flag, int *i)
{
	ft_slide_quotes(line, i);
	if ((line[*i] == '>' && line[*i + 1] && line[*i + 1] != '>' && \
		line[*i + 1] == '<') || \
		(line[*i] == '>' && line[*i + 1] && line[*i + 1] == '>' && \
		line[*i + 2] && line[*i + 2] == '>') || \
		(line[*i] == '<' && line[*i + 1] && line[*i + 1] == '<' && \
		line[*i + 2] && line[*i + 2] == '<') || \
		((line[*i] == '<' || line[*i] == '>') && !(line[*i + 1])))
		flag = -1;
	else if (line[*i] == '<' && line[*i + 1] && line[*i + 1] != '<' && \
	line[*i + 1] == '>')
		flag = 5;
	else if (line[*i] == '<' && line[*i + 1] && line[*i + 1] != '<')
		flag = 1;
	else if (line[*i] == '>' && line[*i + 1] && line[*i + 1] != '>')
		flag = 2;
	else if (line[*i] == '>' && line[*i + 1] && line[*i + 1] == '>')
		flag = 3;
	else if (line[*i] == '<' && line[*i + 1] && line[*i + 1] == '<')
		flag = 4;
	if (flag >= 3)
		(*i)++;
	return (flag);
}

char	*ft_name_of_file(char *line, int i, int *x)
{
	int	c;

	(i)++;
	while (line[i] && line[i] == ' ')
		(i)++;
	if (line[i] == '"')
		ft_quotes(line, &i, &c, x);
	else if (line[i] == '\'')
		ft_quotes(line, &i, &c, x);
	else
	{
		c = (i);
		while (line[c] && line[c] != '<' && line[c] != '>' && line[c] != ' ')
			c++;
		*x = c;
	}
	if (c == (i) || c == i + 1)
		return (NULL);
	return (ft_substr(line, i, c - i));
}

int	ft_open_file(char *file, int flag, t_data *data)
{
	int	ret;

	if (file == NULL)
	{
		errno = 2;
		return (0);
	}		
	ret = 0;
	if (flag == 1)
		ret = ft_flag_1(file);
	else if (flag == 2)
		ret = ft_flag_2(file);
	else if (flag == 3)
		ret = ft_flag_3(file);
	else if (flag == 4)
		ret = ft_flag_4(file, data);
	else if (flag == 5)
		ret = ft_flag_5(file);
	free(file);
	return (ret);
}

int	ft_redir(char **line, t_data *data)
{
	t_redir	norm;
	char	*join;

	norm.i = -1;
	norm.x = 0;
	norm.new_line = NULL;
	while ((*line)[++(norm.i)])
	{
		norm.flag = ft_type_of_redir(*line, 0, &(norm.i));
		if (norm.flag > 0)
		{
			if ((norm.i > norm.x) && (norm.i == 0 || norm.flag < 3)
				&& ft_clean_line(*line, &norm.new_line, norm.i, norm.x) == 0)
				return (ft_redir_error(norm.new_line));
			else if ((norm.i > norm.x) && !(norm.i == 0 || norm.flag < 3)
				&& ft_clean_line(*line, &norm.new_line, norm.i - 1, norm.x) == 0)
				return (ft_redir_error(norm.new_line));
			norm.file = ft_name_of_file(*line, norm.i, &norm.x);
			while ((*line)[norm.x] && (*line)[norm.x] != ' '
				&& (*line)[norm.x] != '>' && (*line)[norm.x] != '<')
			{
				norm.i = norm.x - 1;
				join = ft_name_of_file(*line, norm.i, &norm.x);
				ft_strjoin_over(&norm.file, join);
				free(join);
			}
			if (ft_open_file(norm.file, norm.flag, data) == 0)
				return (ft_redir_error(norm.new_line));
			return (1);
		}
		if (norm.flag == -1)
			return (ft_redir_error(norm.new_line));
	}
	if (norm.i > norm.x
		&& ft_clean_line(*line, &norm.new_line, norm.i, norm.x) == 0)
		return (ft_redir_error(norm.new_line));
	free(*line);
	*line = norm.new_line;
	return (1);
}

void	ft_char(t_char **qwe)
{
	t_char	*tmp;
	t_char	*new;

	new = (t_char *)malloc(sizeof(t_char) * 1);
	new->buf = '\n';
	new->next = NULL;
	if (!*qwe)
	{
		*qwe = new;
		return ;
	}
	tmp = *qwe;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

int	ft_ctr_c(int *fd)
{
	close(*fd);
	*fd = open("/tmp/minishell", O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (*fd < 0)
		return (0);
	write(*fd, "\0", 1);
	return (1);
}

void	ft_flag4_reading(t_data *data, int len, int fd, char *file)
{
	t_char	*qwe;
	char	*buf[2];

	qwe = NULL;
	tcsetattr(0, 0, &data->my_term);
	while (ft_reading(&qwe, &len, data))
	{
		if (len == 0 && ft_ctr_c(&fd))
			break ;
		ft_char(&qwe);
		ft_linod_to_line(&buf[0], &buf[1], len, &qwe);
		len = ft_strlen(file);
		if ((ft_strncmp(buf[0], file, len + 1) == '\n'
				&& ft_strncmp(buf[0], file, len) == 0) || buf[0][0] == '\0')
		{
			free(buf[0]);
			free(buf[1]);
			break ;
		}
		write(fd, buf[0], ft_strlen(buf[0]));
		write(data->std_fd[1], ">", 1);
		free(buf[0]);
		free(buf[1]);
	}
}

int	ft_clean_line(char *line, char **new_line, int i, int x)
{
	char	*temp;

	if (!*new_line)
		*new_line = ft_substr(line, x, i - x);
	else
	{
		temp = ft_substr(line, x, i - x);
		if (!temp)
			return (0);
		if (ft_strjoin_over(new_line, temp) == 0)
			return (0);
		free(temp);
	}
	return (1);
}

int	ft_redir_error(char *new_line)
{
	if (new_line)
		free(new_line);
	return (0);
}

