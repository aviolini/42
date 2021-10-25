/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:49:57 by aviolini          #+#    #+#             */
/*   Updated: 2021/06/07 11:05:48 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_exit(t_data *all, int val)
{
	if (all->path)
		free(all->path);
	all->path = NULL;
	ft_matr_del_and_free(&all->com_matrix);
	exit (val);
}

int	ft_exit_perror(char *s, t_data *all)
{
	perror(s);
	ft_exit(all, 1);
	return (0);
}

int	ft_exit_strerror(int my_errno, t_data *all)
{
	ft_putstr_fd("Error: ", 1);
	ft_putstr_fd(strerror(my_errno), 1);
	ft_putchar_fd('\n', 1);
	ft_exit(all, 1);
	return (0);
}
