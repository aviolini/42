/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_stack_a_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:51:49 by aviolini          #+#    #+#             */
/*   Updated: 2021/05/24 22:42:36 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/include/libft.h"
#include "./pushswap.h"

int	ft_next_index_data(t_list *temp, int idx, int max_data)
{
	temp = temp->next;
	while (temp && (*(int *)(temp)->data) != max_data)
	{
		if (temp->index == idx)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	ft_check_index(t_data *s, int max_index, int max_data)
{
	int		new_max_data;
	t_list	*temp;

	new_max_data = 0;
	temp = *s->a;
	while (temp && (*(int *)(temp)->data) != max_data)
	{	
		if (temp->index == max_index && \
						!ft_next_index_data(temp, temp->index, max_data))
		{
			new_max_data = (*(int *)(temp)->data);
			temp->index *= -1;
			return (new_max_data);
		}
		temp = temp->next;
	}
	return (new_max_data);
}

void	ft_max_index(t_data *s, int *max_index, int *max_data)
{
	t_list	*temp;

	temp = *s->a;
	*max_index = LIMIT_DOWN_INT;
	*max_data = LIMIT_DOWN_INT;
	while (temp)
	{
		if (temp->index > *max_index)
		{
			*max_index = temp->index;
			 *max_data = (*(int *)(temp)->data);
		}
		temp = temp->next;
	}
	temp = *s->a;
}

int	ft_set_index(t_data *s, int max_index, int max_data)
{
	while (max_index > 0)
	{
		max_index--;
		max_data = ft_check_index(s, max_index, max_data);
	}	
	return (0);
}
