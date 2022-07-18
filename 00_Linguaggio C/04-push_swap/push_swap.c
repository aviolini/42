/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 11:57:27 by arrigo            #+#    #+#             */
/*   Updated: 2021/05/26 14:22:17 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/include/libft.h"
#include "./pushswap.h"

int	main(int ac, char **av)
{
	t_data	*s;

	if (!ft_init(&s) || !ft_add_args_to_list(s->a, ac, av))
		ft_exit(s);
	s->i = 0;
	s->flag_st_output = 1;
	if (!ft_list_sort_is_sort_incr_num(s->a))
	{
		if (ft_list_size_list(s->a) <= 5)
			ft_shortcut_sort(s);
		else
		{
			ft_split_stack_a(s);
			while (*s->b)
			{
				ft_number_operations(s);
				ft_best_combo(s);
				ft_best_number(s);
			}
			ft_last_sort(s);
		}
	}
	ft_exit(s);
	return (0);
}

int	ft_shortcut_sort(t_data *s)
{
	int	size_a;
	int	r;

	r = 0;
	size_a = ft_list_size_list(s->a);
	if (size_a == 2)
		r = ft_sort_two(s);
	else if (size_a == 3)
		r = ft_sort_three(s);
	else if (size_a == 4)
		r = ft_sort_four(s);
	else if (size_a == 5)
		r = ft_sort_five(s);
	return (r);
}
