/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 19:08:54 by arrigo            #+#    #+#             */
/*   Updated: 2021/08/03 15:56:26 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_exit_error(t_data *data, int status, char *s)
{
	printf("%s", s);
	if (data)
		return (ft_exit(data, status));
	return(status);
}

int	ft_exit(t_data *data, int status)
{
	printf(DEF"Finished\n");
	if (sem_close(data->semaphore_forks) == -1 || \
		sem_close(data->semaphore_death) == -1 || \
		sem_close(data->semaphore_print) == -1)
		printf("Error sem_close\n");
	if (sem_unlink("sem_forks") == -1 || \
		sem_unlink("sem_death") == -1 || \
		sem_unlink("sem_print") == -1)
		printf("Error sem_unlink\n");
	free(data->pid);
	return (status);
}

unsigned int	ft_time(struct timeval tp)
{
	struct timeval	tp2;
	unsigned int	r;

	gettimeofday(&tp2, NULL);
	r = tp.tv_sec * MSEC + tp.tv_usec / MSEC;
	r = tp2.tv_sec * MSEC + tp2.tv_usec / MSEC - r;
	return (r);
}

int	ft_atoi(char *line, long *num)
{
	int	i;

	(*num) = 0;
	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (!line[i])
		return (1);
	while (line[i] && line[i] != ' ')
	{
		if ((line[i] < '0' || line[i] > '9'))
			return (1);
		(*num) = (line[i] - 48) + (10 * (*num));
		i++;
	}
	while (line[i])
		if (line[i++] != ' ')
			return (1);
	if ((*num) > LIMIT_UP_UINT)
		return (1);
	return (0);
}
