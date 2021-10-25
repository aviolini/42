/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_stack_b_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:30:39 by aviolini          #+#    #+#             */
/*   Updated: 2021/05/24 22:43:51 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/include/libft.h"
#include "./pushswap.h"

int	ft_tot_rra(t_data *s, t_list *temp_b)
{	
	t_list	*temp_a;
	int		x;

	temp_a = *s->a;
	x = ft_list_size_list(s->a) - 1;
	while (temp_a && temp_a->next)
	{	
		if ((*(int *)(temp_b)->data) > (*(int *)(temp_a)->data) && \
					(*(int *)(temp_b)->data) < (*(int *)(temp_a->next->data)))
			return (x);
		else if ((*(int *)(temp_a)->data) > (*(int *)(temp_a->next->data)))
		{
			if ((*(int *)(temp_b)->data) > (*(int *)(temp_a)->data) || \
					(*(int *)(temp_b)->data) < (*(int *)(temp_a->next->data)))
				return (x);
		}
		x--;
		temp_a = temp_a->next;
	}
	return (0);
}

int	ft_tot_ra(t_data *s, t_list *temp_b)
{	
	t_list	*temp_a;
	int		x;

	temp_a = *s->a;
	x = 1;
	while (temp_a && temp_a->next)
	{
		if ((*(int *)(temp_b)->data) > (*(int *)(temp_a)->data) && \
					(*(int *)(temp_b)->data) < (*(int *)(temp_a->next->data)))
			return (x);
		else if ((*(int *)(temp_a)->data) > (*(int *)(temp_a->next->data)))
		{
			if ((*(int *)(temp_b)->data) > (*(int *)(temp_a)->data) || \
					(*(int *)(temp_b)->data) < (*(int *)(temp_a->next->data)))
				return (x);
		}
		x++;
		temp_a = temp_a->next;
	}
	return (0);
}

void	ft_calc_totals(t_tot *tot, t_list *tmp)
{
	if (tmp->ops_ra > tmp->ops_rb)
		tot->tot_r = tmp->ops_ra;
	else
		tot->tot_r = tmp->ops_rb;
	if (tmp->ops_rra > tmp->ops_rrb)
		tot->tot_rr = tmp->ops_rra;
	else
		tot->tot_rr = tmp->ops_rrb;
	tot->tot_ra_rrb = tmp->ops_ra + tmp->ops_rrb;
	tot->tot_rb_rra = tmp->ops_rb + tmp->ops_rra;
}

void	ft_set_flag_and_tot(t_tot tot, t_list *tmp)
{
	if (tot.tot_r < tot.tot_rr && tot.tot_r < tot.tot_ra_rrb && \
											tot.tot_r < tot.tot_rb_rra)
	{
		tmp->flag = 1;
		tmp->tot = tot.tot_r;
	}
	else if (tot.tot_rr < tot.tot_r && tot.tot_rr < tot.tot_ra_rrb && \
											tot.tot_rr < tot.tot_rb_rra)
	{
		tmp->flag = 2;
		tmp->tot = tot.tot_rr;
	}
	else if (tot.tot_ra_rrb < tot.tot_r && tot.tot_ra_rrb < tot.tot_rr && \
											tot.tot_ra_rrb < tot.tot_rb_rra)
	{
		tmp->flag = 3;
		tmp->tot = tot.tot_ra_rrb;
	}
	else
	{
		tmp->flag = 4;
		tmp->tot = tot.tot_rb_rra;
	}	
}
