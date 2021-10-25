/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 11:57:06 by arrigo            #+#    #+#             */
/*   Updated: 2021/05/26 14:34:37 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/include/libft.h"
#include "./pushswap.h"

void	ft_do_steps(t_data *s, t_list *temp)
{
	if (!ft_strcmp((char *)temp->data, "rra"))
		ft_rra(s);
	else if (!ft_strcmp((char *)temp->data, "rrb"))
		ft_rrb(s);
	else if (!ft_strcmp((char *)temp->data, "rrr"))
		ft_rrr(s);
	else if (!ft_strcmp((char *)temp->data, "sa"))
		ft_sa(s);
	else if (!ft_strcmp((char *)temp->data, "sb"))
		ft_sb(s);
	else if (!ft_strcmp((char *)temp->data, "ss"))
		ft_ss(s);
	else if (!ft_strcmp((char *)temp->data, "pa"))
		ft_pa(s);
	else if (!ft_strcmp((char *)temp->data, "pb"))
		ft_pb(s);
	else if (!ft_strcmp((char *)temp->data, "ra"))
		ft_ra(s);
	else if (!ft_strcmp((char *)temp->data, "rb"))
		ft_rb(s);
	else if (!ft_strcmp((char *)temp->data, "rr"))
		ft_rr(s);
	else
		ft_exit_error(s);
}

int	main(int ac, char **av)
{
	t_data	*s;
	char	*line;

	if (ac == 1)
		exit (0);
	if (!ft_init(&s) || !ft_add_args_to_list(s->a, ac, av))
		ft_exit(s);
	s->flag_st_output = 0;
	while (get_next_line(0, &line) > 0)
	{
		ft_list_add_node_back_list(s->steps, line, T_S);
		free(line);
		line = NULL;
	}
	while (*s->steps)
	{
		ft_do_steps(s, *s->steps);
		ft_list_del_node_by_node(s->steps, *s->steps);
	}
	if (ft_list_sort_is_sort_incr_num(s->a))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_exit(s);
	return (0);
}
