/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_stack_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:20:51 by aviolini          #+#    #+#             */
/*   Updated: 2021/05/24 22:44:17 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/include/libft.h"
#include "./pushswap.h" 

int	ft_number_operations(t_data *s)
{
	t_list	*temp_b;
	int		i;
	int		c;

	i = 0;
	c = ft_list_size_list(s->b);
	temp_b = *s->b;
	while (temp_b)
	{
		(temp_b)->ops_rb = i;
		(temp_b)->ops_rrb = c;
		(temp_b)->ops_ra = ft_tot_ra(s, temp_b);
		(temp_b)->ops_rra = ft_tot_rra(s, temp_b);
		temp_b = temp_b->next;
		i++;
		c--;
	}
	return (1);
}

int	ft_best_combo(t_data *s)
{
	t_list	*tmp;
	t_tot	tot;

	tmp = *s->b;
	while (tmp)
	{
		ft_calc_totals(&tot, tmp);
		ft_set_flag_and_tot(tot, tmp);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_best_number(t_data *s)
{
	t_list	*temp;
	t_list	*best;

	temp = *s->b;
	best = temp;
	while (temp)
	{
		if (temp->tot < best->tot)
		{
			best = temp;
			best->flag = temp->flag;
		}
		temp = temp->next;
	}
	if (best->flag == 1)
		ft_do_ra_rb(s, best);
	else if (best->flag == 2)
		ft_do_rra_rrb(s, best);
	else if (best->flag == 3)
		ft_do_ra_rrb(s, best);
	else
		ft_do_rb_rra(s, best);
}

void	ft_last_sort(t_data *s)
{
	t_list	*temp;
	int		i;

	if (*(int *)*s->a != s->min)
	{
		temp = *s->a;
		i = 0;
		while (temp && temp->next)
		{
			if ((*(int *)(temp)->data) > (*(int *)(temp->next->data)))
				break ;
			i++;
			temp = temp->next;
		}
		if (i < ft_list_size_list(s->a) / 2)
		{
			while ((*(int *)(*s->a)->data) != s->min)
				ft_ra(s);
		}
		else
		{
			while ((*(int *)(*s->a)->data) != s->min)
				 ft_rra(s);
		}
	}
}
