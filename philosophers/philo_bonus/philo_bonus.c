/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 18:02:12 by arrigo            #+#    #+#             */
/*   Updated: 2021/08/06 11:18:38 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_data			data;
	unsigned int	i;
	int				ret;

	if ((ac != 5 && ac != 6) || ft_check_and_init_args(av, &data))
		return (ft_exit_error(NULL, 1, "Error arguments\n"));
	if (ft_init(&data))
		return (ft_exit_error(&data, 2, "Error init\n"));
	if (gettimeofday(&data.tp, NULL))
		return (ft_exit_error(&data, 3, "Error program\n"));
	ret = ft_init_philos(&data);
	if (ret == 4)
		return (ft_exit_error(&data, 4, "Error fork\n"));
	if (ret == 5)
		return (ft_exit_error(&data, 5, "Error thread\n"));
	if (ret == 6)
		return (ft_exit_error(&data, 6, "Error semaphore\n"));
	if (sem_wait(data.semaphore_death) == -1)
		return (ft_exit_error(&data, 7, "Error sem_wait\n"));
	i = 0;
	while (i < data.num_philos)
	{	
		if (kill(data.pid[i], SIGKILL) == -1)
			return (ft_exit_error(&data, 8, "Error kill\n"));
		if (waitpid(data.pid[i], NULL, 0) == -1)
			return (ft_exit_error(&data, 9, "Error waitpid\n"));
		i++;
	}
	return (ft_exit(&data, 0));
}

int	ft_check_and_init_args(char **av, t_data *data)
{
	int				i;
	int				c;
	unsigned int	x;
	long			num;

	i = 0;
	c = 0;
	while (av[++i])
	{
		if (ft_atoi(av[i], &num))
			return (1);
		x = 0;
		while (x < (unsigned int)(sizeof(unsigned int)))
			((unsigned char *)data)[c++] = ((unsigned char *)&num)[x++];
		if (i == 5)
			while (x++ < (unsigned int)(sizeof(long)))
				((unsigned char *)data)[c++] = 0;
	}
	if (i == 5)
		data->num_meals = -1;
	if (!data->num_philos || !data->time_to_die || \
		!data->time_to_eat || !data->time_to_sleep || \
		!data->num_meals)
		return (1);
	return (0);
}

int	ft_init(t_data *data)
{
	data->last_meal = 0;
	data->var_death = 0;
	data->pid = NULL;
	if (ft_init_semaphore("sem_forks", &data->semaphore_forks, \
		data->num_philos) || \
		ft_init_semaphore("sem_death", &data->semaphore_death, 0) || \
		ft_init_semaphore("sem_print", &data->semaphore_print, 1))
		return (1);
	data->pid = malloc(sizeof(pid_t) * data->num_philos);
	if (!data->pid)
		return (1);
	return (0);
}

int	ft_init_semaphore(char *name, sem_t **semaphore, unsigned int value)
{
	*semaphore = sem_open(name, O_CREAT | O_EXCL, 0666, value);
	if (*semaphore == SEM_FAILED)
	{
		if (sem_unlink(name) == -1)
			return (1);
		*semaphore = sem_open(name, O_CREAT | O_EXCL, 0666, value);
		if (*semaphore == SEM_FAILED)
			return (1);
	}
	return (0);
}

int	ft_init_philos(t_data *data)
{
	unsigned int	i;
	pid_t			pid;
	pthread_t		thread_control;

	i = 0;
	while (i < data->num_philos)
	{
		pid = fork();
		if (pid == -1)
			return (4);
		if (pid == 0)
		{
			if (pthread_create(&(thread_control), NULL, \
				ft_control, (void *)&(*data)))
				return (5);
			if (pthread_detach(thread_control))
				return (5);
			data->index_philo = i;
			if (ft_routine(data))
				return (6);
		}
		data->pid[i++] = pid;
		usleep(100);
	}
	return (0);
}
