/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_stack_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 12:00:42 by aviolini          #+#    #+#             */
/*   Updated: 2021/05/24 22:43:28 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/include/libft.h"
#include "./pushswap.h"

void	ft_split_stack_a(t_data *s)
{
	int		max_index;
	int		max_data;

	ft_list_find_data_min_max_med(s->a, &(s->min), \
											&(s->max), &(s->med));
	ft_subsequence(s);
	ft_max_index(s, &max_index, &max_data);
	ft_set_index(s, max_index, max_data);
	ft_pre_split_stack_a(s, max_index, max_data);
	while ((*s->a)->index > 0)
	{
		if ((*s->a)->index == max_index)
		{
			max_index++;
			ft_ra(s);
		}
		if ((*s->a)->index > 0)
			ft_pb(s);
	}	
}

void	ft_pre_split_stack_a(t_data *s, int max_index, int max_data)
{
	max_index--;
	while (max_index)
	{
		if ((*s->a)->index >= 0)
		{
			if (max_index == max_index + 1 && \
								(*(int *)(*s->a)->data) > max_data)
			{
				max_data = (*(int *)(*s->a)->data);
				(*s->a)->index = -1;
				ft_ra(s);
			}
			else
				ft_pb(s);
		}
		else
		{
			max_index--;
			ft_ra(s);
		}
	}	
}

void	ft_write_index(t_list *temp)
{
	int	num;
	int	idx;

	num = (*(int *)(temp)->data);
	idx = temp->index;
	temp = temp->next;
	while (temp)
	{
		if ((*(int *)(temp)->data) > num && temp->index <= idx)
			(temp->index)++;
		temp = temp->next;
	}
}

void	ft_subsequence(t_data *s)
{
	t_list	*temp;

	temp = *s->a;
	while (temp)
	{
		temp->index = 1;
		temp = temp->next;
	}
	temp = *s->a;
	while (temp)
	{
		ft_write_index(temp);
		temp = temp->next;
	}
}
