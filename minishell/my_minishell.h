/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 11:23:52 by aviolini          #+#    #+#             */
/*   Updated: 2021/08/04 10:47:45 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_MINISHELL_H
# define MY_MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <dirent.h>
# include <errno.h>
# include <string.h>
# include <curses.h>
# include <term.h>
# include <termios.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>

extern int	g_pid;

typedef struct s_redir
{
	int		i;
	char	*new_line;
	int		flag;
	int		x;
	char	*file;
}	t_redir;

typedef struct s_int
{
	int				x;
	struct s_int	*next;
}	t_int;

typedef struct s_char
{
	unsigned char	buf;
	struct s_char	*prev;
	struct s_char	*next;
}	t_char;

typedef struct s_read
{
	char			*line;
	int				pos;
	struct s_read	*next;
}	t_read;

typedef struct s_data
{
	struct termios	old_term;
	struct termios	my_term;
	t_read			**cmd_head;
	t_read			**env_head;
	char			**envp;
	int				env_len;
	char			**args;
	int				std_fd[2];
	int				flag;
}	t_data;

/*	ft_arrow.c	*/
void	ft_line_to_linod(t_char **line_head, char *line);
void	ft_arrow_up(t_char **line_head, t_data *data, int x, int *len);
int		ft_ctrl_l(t_char **line_head);
int		ft_canc(t_char **line_head, int *len);
int		ft_new_line(t_char **line_head, int *len, char buf, t_data *data);

/*	ft_buf_to_list.c	*/
int		ft_buf_to_node(int len, int x, char *buf, t_read *new);
void	ft_append_read(t_read *new, t_read **head);
void	ft_buf_to_list(char *buf, t_data *data);

/*	ft_check_exportline.c	*/
void	ft_env_join(char **str, t_data *data);
void	ft_check_exportline(char *str, int x, int fix, t_data *data);
void	ft_len_new(char **new, char *str);
void	ft_find_arg(char *str, int *x, int y, char ***matr);
void	ft_matrline(char *str, t_data *data);

/*		ft_check_quotes.c	*/
int		ft_check_quote(char	*line);
void	ft_clean_clean(char **line, int e, int s);
int		ft_check_clean(char **line, int *x, int s, char c);
void	ft_clean_quotes(char **line);

/*		ft_env_line.c	*/
int		ft_get_var(char **var, int *len, t_data *data);
void	ft_var_line(char *var, char **line, int x, t_data *data);
int		ft_env_quotes(int *z, int *x, char *tmp);
void	ft_env_line(char **line, int *x, t_data *data);

/*		ft_exec_cmd.c	*/
void	ft_cd(char *line, t_data *data);
void	ft_pwd(char *line, t_data *data);
void	ft_echo(char *line);
void	ft_check_cmd(char *line, t_data *data);
void	ft_exec_cmd(char *line, t_data *data);
void	ft_update_pwd(char *tmp, t_data *data);
void	ft_option_echo(int *new_line, int *x, char *line);
void	ft_echo_quotes(int *x, char *line, char c);
void	ft_write_echo(int *x, char *line);
void	ft_error_redir(int *x);

/*		ft_exec_pipe.c	*/
int		ft_init_pipes(char *line, int ***fd_pipes, t_data *data);
void	ft_exec_pipes(char *line, t_data *data);
void	ft_free_pipes(int **pipes, int num);
int		ft_close_all_fd_pipe(int **fd_pipe, int num);

/*		ft_execve*/
int		ft_check_execve(char *line, t_data *data);
void	ft_do_execve(char *line, t_data *data);
void	ft_sign_ign_quit(int sig);
void	ft_sign_ign_int(int sig);
void	ft_kill_child(int sig);
void	ft_execve_failed(char *line, t_data *data);

/*		ft_exit.c		*/
void	ft_free_env_read(t_read **head);
void	ft_free_read(t_read **head);
void	ft_exit_cmd(char *line, t_data *data);
void	ft_exit_num(int num, t_data *data);
void	ft_exit(char *str, t_data *data);

/*		ft_get_env.c	*/
void	ft_print_env(t_read **head);
void	ft_unset(char *line, t_data *data);
void	ft_env(char *line, t_data *data);
void	ft_export(char *line, t_data *data);
void	ft_get_env(char **env, t_data *data);
char	*ft_itoa_errno(int num);
void	ft_list_to_matr(t_read **env_head, char ***envp, t_data *data);
void	ft_fix_env(char **line);
int		ft_search_env(char *line, int len, t_data *data);
void	ft_add_env(char *line, int fix, t_data *data);

/*		ft_print_sort.c	*/
int		ft_strstr(char *find, char *str);
void	ft_init_pos(t_read **head);
int		ft_check_double(t_read **head);
void	ft_get_pos(t_read **head, t_data *data);
void	ft_print_sort(t_read **head, t_data *data);

/*		ft_read_ops.c	*/
int		ft_read_special(t_char **line_head, t_data *data, int *x, int *len);
int		ft_ctrl_d(t_char **line_head);
int		ft_reading(t_char **line_head, int *len, t_data *data);
void	ft_read_ops(t_char *line_head, t_read *cmd, t_data *data);

/*		ft_redir.c*/
int		ft_redir(char **line, t_data *data);
void	ft_char(t_char **qwe);
int		ft_ctr_c(int *fd);
void	ft_flag4_reading(t_data *data, int len, int fd, char *file);
int		ft_clean_line(char *line, char **new_line, int i, int x);
int		ft_redir_error(char *new_line);

/*		minishell.c		***		MAIN	***		*/			
void	ft_init_term(t_data *data);
void	ft_no_arg(t_data *data);
void	ft_arg(char *av, char **env);

/*ft_split*/
size_t	ft_cntwrds(char const *s, char c);
char	**ft_split(char const *s, char c);

/*utils_basic2*/
int		ft_strjoin_over(char **s1, char const *s2);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *str);
int		ft_free_matrix(char ***matrix);

/*	utils_basic.c	*/
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, int len);
int		ft_strchr(char c, char *s1);
int		ft_strlen(char *str);
void	ft_write(char *str);

/*	utils_exec_cmd.c	*/


/*	utils_exec_pippe.c		*/
// void	ft_free_pipes(int **pipes, int num);
// int		ft_close_all_fd_pipe(int **fd_pipe, int num);
// void	ft_pipe_exit(char *line, char **matr, t_data *data);
// void	ft_child(int *x, int **fd_pipes, char *matrx, t_data *data);
// void	ft_no_pipe(char **matr, char *line, t_data *data);

/*	utils_execve.c	*/
// void	ft_sign_ign_quit(int sig);
// void	ft_sign_ign_int(int sig);
// void	ft_kill_child(int sig);
// void	ft_execve_failed(char *line, t_data *data);

/*	utils_exportline.c	*/
int		ft_check_format(char c);
int		ft_error_export(void);
int		ft_check_spaces(char *str, int *x);
void	ft_check_empty(char **str);
int		ft_last_spaces(char *str);

/*	utils_flagredir.c	*/
int		ft_flag_1(char *file);
int		ft_flag_2(char *file);
int		ft_flag_3(char *file);
int		ft_flag_4(char *file, t_data *data);
int		ft_flag_5(char *file);

/*	utils_get_env.c	*/


/*	utils_quotes.c	*/
int		ft_cpy_matr(char **matr, char **new);
void	ft_utils_quotes(int *a, int *z, char *str, char **new);
int		ft_line_forward(char **line, int *z, int *x, char c);
void	ft_quotes(char *line, int *i, int *c, int *x);
void	ft_slide_quotes(char *line, int *i);

/*	utils_random.c		*/
void	ft_write_2(char *str);
void	ft_exit_error(t_data *data);
int		ft_free_env(t_read	*tmp, t_data *data);
int		ft_empty_line(int *len, t_char **line_head);
void	ft_check_builtin(char *line, t_data *data);

/*	utils_read_ops.c	*/
int		ft_read_len(t_read **cmd_head);
void	ft_add_front_read(t_read *new, t_read **head);
void	ft_linod_to_line(char **line, char **line2,
			int len, t_char **line_head);
void	ft_buffering(char buf, int *len, t_char **line_head);
void	ft_restart_reading(t_char *line_head,
			int *len, t_read *cmd);

/*	utils_redir.c		*/
// void	ft_charrr(t_char **qwe);
// int		ft_ctr_c(int *fd);
// void	ft_flag4_reading(t_data *data, int len, int fd, char *file);
// int		ft_clean_line(char *line, char **new_line, int i, int x);
// int		ft_redir_error(char *new_line);

/*	utils_t_char.c		*/
int		ft_char_len(t_char **line_head);
void	ft_free_char(t_char **line_head);
void	ft_write_char(t_char **line_head);
void	ft_canc_char(t_char **line_head);

#endif
