/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 23:28:59 by arrigo            #+#    #+#             */
/*   Updated: 2021/05/19 09:29:33 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/include/libft.h"
#include "./pushswap.h"

int	ft_sort_five(t_data *s)
{
	if (ft_list_size_list(s->a) != 5)
		return (0);
	if (ft_list_sort_is_sort_incr_num(s->a))
		return (1);
	ft_sort_five_p0(s);
	if ((*(int *)(*s->b)->data) < (*(int *)(*s->a)->data))
	{	
		ft_pa(s);
		ft_pa(s);
	}
	else if ((*(int *)(*s->b)->data) > (*(int *)(*s->a)->data) && \
		(*(int *)(*s->b)->data) < (*(int *)(*s->a)->next->data))
		ft_sort_five_p1(s);
	else if ((*(int *)(*s->b)->data) > (*(int *)(*s->a)->next->data) && \
		(*(int *)(*s->b)->data) < (*(int *)(*s->a)->next->next->data))
	{	
		if (!ft_sort_five_p2(s))
			ft_sort_five_p3(s);
	}
	else if ((*(int *)(*s->b)->data) > (*(int *)(*s->a)->next->next->data))
	{
		if (!ft_sort_five_p4(s))
			ft_sort_five_p5(s);
	}
	return (1);
}

void	ft_sort_five_p0(t_data *s)
{
	ft_pb(s);
	ft_pb(s);
	ft_sort_three(s);
	if ((*(int *)(*s->b)->data) < (*(int *)(*s->b)->next->data))
		ft_sb(s);
}
