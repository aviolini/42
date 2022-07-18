/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min_of_five.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 23:28:23 by arrigo            #+#    #+#             */
/*   Updated: 2021/05/26 14:28:58 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/include/libft.h"
#include "./pushswap.h"

int	ft_sort_two(t_data *s)
{
	if (ft_list_size_list(s->a) != 2)
		return (0);
	if ((*(int *)(*s->a)->data) > (*(int *)(*s->a)->next->data))
		ft_sa(s);
	return (1);
}

int	ft_sort_three(t_data *s)
{
	if (ft_list_size_list(s->a) != 3)
		return (0);
	if (ft_list_sort_is_sort_incr_num(s->a))
		return (1);
	if (!ft_sort_three_p1(s))
	{
		if ((*(int *)(*s->a)->data) > (*(int *)(*s->a)->next->data) && \
			(*(int *)(*s->a)->data) > (*(int *)(*s->a)->next->next->data) && \
			(*(int *)(*s->a)->next->data) < (*(int *)(*s->a)->next->next->data))
		{	
			ft_ra(s);
		}
		else if ((*(int *)(*s->a)->data) > (*(int *)(*s->a)->next->data) && \
			(*(int *)(*s->a)->data) > (*(int *)(*s->a)->next->next->data) && \
			(*(int *)(*s->a)->next->data) > (*(int *)(*s->a)->next->next->data))
		{	
			ft_sa(s);
			ft_rra(s);
		}
	}
	return (1);
}

int	ft_sort_three_p1(t_data *s)
{
	if ((*(int *)(*s->a)->data) < (*(int *)(*s->a)->next->data) && \
		(*(int *)(*s->a)->data) < (*(int *)(*s->a)->next->next->data) && \
		(*(int *)(*s->a)->next->data) > (*(int *)(*s->a)->next->next->data))
	{	
		ft_rra(s);
		ft_sa(s);
		return (1);
	}
	if ((*(int *)(*s->a)->data) > (*(int *)(*s->a)->next->data) && \
		(*(int *)(*s->a)->data) < (*(int *)(*s->a)->next->next->data) && \
		(*(int *)(*s->a)->next->data) < (*(int *)(*s->a)->next->next->data))
	{	
		ft_sa(s);
		return (1);
	}
	if ((*(int *)(*s->a)->data) < (*(int *)(*s->a)->next->data) && \
		(*(int *)(*s->a)->data) > (*(int *)(*s->a)->next->next->data) && \
		(*(int *)(*s->a)->next->data) > (*(int *)(*s->a)->next->next->data))
	{	
		ft_rra(s);
		return (1);
	}
	return (0);
}

int	ft_sort_four(t_data *s)
{
	if (ft_list_size_list(s->a) != 4)
		return (0);
	if (ft_list_sort_is_sort_incr_num(s->a))
		return (1);
	ft_pb(s);
	ft_sort_three(s);
	if (!ft_sort_four_p1(s))
	{
		if ((*(int *)(*s->b)->data) > (*(int *)(*s->a)->next->data) && \
			(*(int *)(*s->b)->data) < (*(int *)(*s->a)->next->next->data))
		{	
			ft_rra(s);
			ft_pa(s);
			ft_ra(s);
			ft_ra(s);
		}
		else if ((*(int *)(*s->b)->data) > (*(int *)(*s->a)->next->next->data))
		{	
			ft_pa(s);
			ft_ra(s);
		}
	}
	return (1);
}

int	ft_sort_four_p1(t_data *s)
{
	if ((*(int *)(*s->b)->data) < (*(int *)(*s->a)->data))
	{	
		ft_pa(s);
		return (1);
	}
	if ((*(int *)(*s->b)->data) > (*(int *)(*s->a)->data) && \
		(*(int *)(*s->b)->data) < (*(int *)(*s->a)->next->data))
	{	
		ft_ra(s);
		ft_pa(s);
		ft_rra(s);
		return (1);
	}	
	return (0);
}
