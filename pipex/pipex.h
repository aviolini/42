/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:06:33 by aviolini          #+#    #+#             */
/*   Updated: 2021/06/07 10:44:44 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_data
{
	int			fd_out;
	int			fd_in;
	int			fd_pipe[2];
	char		*path;
	char		**com_matrix;
}				t_data;
/*MAIN*/
void	ft_command_one(char **av, char **env, t_data *all);
void	ft_command_two(char **av, char **env, t_data *all);
void	ft_do_execve(char *command, t_data *all, char **env);
/*TOOLS*/
int		ft_is_a_system_command(char **env, t_data *all);
int		ft_is_a_local_command(char **env, t_data *all);
char	*ft_get_str_from_env(char *to_find, char **env);
char	**ft_all_paths(char **env);
/*EXIT*/
int		ft_exit(t_data *all, int val);
int		ft_exit_perror(char *s, t_data *all);
int		ft_exit_strerror(int my_errno, t_data *all);
/*LIBFT_TOOLS_1*/
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);
int		ft_strchr(char *str, char c);
int		ft_matr_del_and_free(char ***matrix);
/*LIBFT_TOOLS_2*/
char	*ft_strstr(char *str, char *to_find);
char	*ft_strdup(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
/*LIBFT_TOOLS_3*/
char	**ft_split(char const *s, char c);

#endif