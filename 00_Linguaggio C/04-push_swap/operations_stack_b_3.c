/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_stack_b_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 22:07:01 by arrigo            #+#    #+#             */
/*   Updated: 2021/05/24 22:44:03 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/include/libft.h"
#include "./pushswap.h"

int	ft_do_ra_rrb(t_data *s, t_list *temp_b)
{
	int		x;

	x = temp_b->ops_ra;
	while (x > 0)
	{
		ft_ra(s);
		x--;
	}
	x = temp_b->ops_rrb;
	while (x > 0)
	{
		ft_rrb(s);
		x--;
	}
	ft_pa(s);
	return (-1);
}

int	ft_do_rb_rra(t_data *s, t_list *temp_b)
{
	int		x;

	x = temp_b->ops_rb;
	while (x > 0)
	{
		ft_rb(s);
		x--;
	}
	x = temp_b->ops_rra;
	while (x > 0)
	{
		ft_rra(s);
		x--;
	}
	ft_pa(s);
	return (-1);
}

int	ft_do_rra_rrb(t_data *s, t_list *temp_b)
{	
	int		x;

	if (temp_b->ops_rra > temp_b->ops_rrb)
		x = temp_b->ops_rrb;
	else
		x = temp_b->ops_rra;
	while (x-- > 0)
		ft_rrr(s);
	if (temp_b->ops_rra > temp_b->ops_rrb)
		x = temp_b->ops_rra - temp_b->ops_rrb;
	else
		x = temp_b->ops_rrb - temp_b->ops_rra;
	while (x-- > 0)
	{
		if (temp_b->ops_rra > temp_b->ops_rrb)
			ft_rra(s);
		else
			ft_rrb(s);
	}
	ft_pa(s);
	return (-1);
}

int	ft_do_ra_rb(t_data *s, t_list *temp_b)
{	
	int		x;

	if (temp_b->ops_ra > temp_b->ops_rb)
		x = temp_b->ops_rb;
	else
		x = temp_b->ops_ra;
	while (x-- > 0)
		ft_rr(s);
	if (temp_b->ops_ra > temp_b->ops_rb)
		x = temp_b->ops_ra - temp_b->ops_rb;
	else
		x = temp_b->ops_rb - temp_b->ops_ra;
	while (x > 0)
	{
		x--;
		if (temp_b->ops_ra > temp_b->ops_rb)
			ft_ra(s);
		else
			ft_rb(s);
	}
	ft_pa(s);
	return (-1);
}
