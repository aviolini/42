/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:43:28 by aviolini          #+#    #+#             */
/*   Updated: 2021/08/02 14:50:09 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_control(void *arg)
{
	t_data			*data;
	unsigned int	r;

	data = (t_data *)arg;
	while (!data->var_death)
	{	
		r = ft_time(data->tp);
		if ((r - data->last_meal) >= data->time_to_die && !data->var_death)
		{
			data->var_death++;
			if (sem_wait(data->semaphore_print) == -1)
				printf("Error sem_wait\n");
			if (data->var_death == 1 && data->num_meals != 0)
				printf(RED"%u\t%d died\n"DEF, r, data->index_philo + 1);
			data->var_death++;
			if (sem_post(data->semaphore_death) == -1)
				printf("Error sem_post\n");
		}
		usleep(10);
	}
	return ((void *)0);
}

int	ft_routine(t_data *data)
{
	while (data->num_meals)
	{
		if (ft_has_taken_fork(data))
			return (1);
		if (data->num_philos == 1)
			if (sem_post(data->semaphore_print) == -1)
				return (2);
		if (ft_has_taken_fork(data))
			return (1);
		if (ft_is_eating(data) || ft_is_sleeping_and_is_thinking(data))
			return (1);
		if (data->num_meals != -1)
			data->num_meals--;
	}
	if (sem_post(data->semaphore_death) == -1)
		return (1);
	return (0);
}

int	ft_has_taken_fork(t_data *data)
{
	if (sem_wait(data->semaphore_forks) == -1)
		return (1);
	if (sem_wait(data->semaphore_print) == -1)
		return (1);
	if (!data->var_death)
		printf(CYN"%u\t%u has taken a fork\n"DEF, \
			ft_time(data->tp), data->index_philo + 1);
	if (sem_post(data->semaphore_print) == -1)
		return (2);
	return (0);
}

int	ft_is_eating(t_data *data)
{
	data->last_meal = ft_time(data->tp);
	if (sem_wait(data->semaphore_print) == -1)
		return (1);
	if (!data->var_death)
		printf(YEL"%u\t%u is eating\n"DEF, data->last_meal, \
			data->index_philo + 1);
	if (sem_post(data->semaphore_print) == -1)
		return (1);
	usleep(data->time_to_eat * MSEC);
	if (sem_post(data->semaphore_forks) == -1)
		return (2);
	if (sem_post(data->semaphore_forks) == -1)
		return (2);
	return (0);
}

int	ft_is_sleeping_and_is_thinking(t_data *data)
{
	if (sem_wait(data->semaphore_print) == -1)
		return (1);
	if (!data->var_death)
		printf(MAG"%u\t%u is sleeping\n"DEF, ft_time(data->tp), \
			data->index_philo + 1);
	if (sem_post(data->semaphore_print) == -1)
		return (2);
	usleep(data->time_to_sleep * MSEC);
	if (sem_wait(data->semaphore_print) == -1)
		return (1);
	if (!data->var_death)
		printf(GRN"%u\t%u is thinking\n"DEF, ft_time(data->tp), \
			data->index_philo + 1);
	if (sem_post(data->semaphore_print) == -1)
		return (2);
	return (0);
}
