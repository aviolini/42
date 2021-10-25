/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 13:19:08 by aviolini          #+#    #+#             */
/*   Updated: 2021/08/04 11:00:05 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <errno.h>
# include <sys/wait.h>
# include <semaphore.h>
# include <fcntl.h> 
# include <sys/stat.h> 
# include <string.h>
# include <signal.h> 

# define LIMIT_UP_UINT 4294967295
# define MAX_N_THREADS_MAC 4095
# define SEC		1000000
# define MSEC	1000

# define DEF  "\x1B[0m"
# define RED  "\x1B[31m"
# define GRN  "\x1B[32m"
# define YEL  "\x1B[33m"
# define BLU  "\x1B[34m"
# define MAG  "\x1B[35m"
# define CYN  "\x1B[36m"
# define WHT  "\x1B[37m"

typedef struct s_data
{
	unsigned int	num_philos;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	long			num_meals;
	struct timeval	tp;
	sem_t			*semaphore_forks;
	sem_t			*semaphore_death;
	sem_t			*semaphore_print;
	pid_t			*pid;
	int				var_death;
	unsigned int	last_meal;
	unsigned int	index_philo;
}					t_data;

unsigned int	ft_time(struct timeval tp);
int				ft_has_taken_fork(t_data *data);
int				ft_is_eating(t_data *data);
int				ft_is_sleeping_and_is_thinking(t_data *data);
void			*ft_control(void *arg);
int				ft_routine(t_data *data);
int				ft_init_philos(t_data *data);
int				ft_exit_error(t_data *data, int status, char *s);
int				ft_init_semaphore(char *name, sem_t **semaphore, \
				unsigned int value);
int				ft_init(t_data *data);
int				ft_exit(t_data *data, int status);
int				ft_atoi(char *line, long *num);
int				ft_check_and_init_args(char **av, t_data *data);

#endif 
