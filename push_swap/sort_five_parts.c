/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_parts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 01:15:42 by arrigo            #+#    #+#             */
/*   Updated: 2021/05/19 09:29:30 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/include/libft.h"
#include "./pushswap.h"

void	ft_sort_five_p1(t_data *s)
{
	if ((*(int *)(*s->b)->next->data) < (*(int *)(*s->a)->data))
	{	
		ft_ra(s);
		ft_pa(s);
		ft_rra(s);
		ft_pa(s);
	}
	else if ((*(int *)(*s->b)->next->data) > (*(int *)(*s->a)->data))
	{	
		ft_ra(s);
		ft_pa(s);
		ft_pa(s);
		ft_rra(s);
	}
}

int	ft_sort_five_p2(t_data *s)
{
	if ((*(int *)(*s->b)->next->data) < (*(int *)(*s->a)->data))
	{	
		ft_ra(s);
		ft_ra(s);
		ft_pa(s);
		ft_rra(s);
		ft_rra(s);
		ft_pa(s);
		return (1);
	}
	else if ((*(int *)(*s->b)->next->data) > (*(int *)(*s->a)->data) && \
		(*(int *)(*s->b)->next->data) < (*(int *)(*s->a)->next->data))
	{	
		ft_ra(s);
		ft_ra(s);
		ft_pa(s);
		ft_rra(s);
		ft_pa(s);
		ft_rra(s);
		return (1);
	}	
	return (0);
}

void	ft_sort_five_p3(t_data *s)
{
	if ((*(int *)(*s->b)->next->data) > (*(int *)(*s->a)->next->data))
	{	
		ft_ra(s);
		ft_ra(s);
		ft_pa(s);
		ft_pa(s);
		ft_rra(s);
		ft_rra(s);
	}
}

int	ft_sort_five_p4(t_data *s)
{
	if ((*(int *)(*s->b)->next->data) < (*(int *)(*s->a)->data))
	{	
		ft_pa(s);
		ft_ra(s);
		ft_pa(s);
		return (1);
	}
	else if ((*(int *)(*s->b)->next->data) > (*(int *)(*s->a)->data) && \
		(*(int *)(*s->b)->next->data) < (*(int *)(*s->a)->next->data))
	{	
		ft_pa(s);
		ft_ra(s);
		ft_ra(s);
		ft_pa(s);
		ft_rra(s);
		return (1);
	}	
	return (0);
}

void	ft_sort_five_p5(t_data *s)
{
	if ((*(int *)(*s->b)->next->data) > (*(int *)(*s->a)->next->data) && \
		(*(int *)(*s->b)->next->data) < (*(int *)(*s->a)->next->next->data))
	{	
		ft_pa(s);
		ft_rra(s);
		ft_pa(s);
		ft_ra(s);
		ft_ra(s);
		ft_ra(s);
	}
	else if ((*(int *)(*s->b)->next->data) > \
							(*(int *)(*s->a)->next->next->data))
	{	
		ft_pa(s);
		ft_pa(s);
		ft_ra(s);
		ft_ra(s);
	}	
}
