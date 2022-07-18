/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:24:14 by aviolini          #+#    #+#             */
/*   Updated: 2021/04/28 17:34:55 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_BONUS_H
# define LIBASM_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include "libasm.h"

	typedef struct		s_list
{
	void			*data;	
	struct s_list	*next;	
}					t_list;

void	ft_list_push_front(t_list **begin_list, void *data); 
int		ft_list_size(t_list *begin_list);
void	ft_list_sort(t_list **begin_list,int (*cmp)());
		//*cmp)(list_ptr->data, list_other_ptr->data);
		//cmp could be for instance ft_strcmp.
void	ft_list_remove_if(t_list **begin_list, void*data_ref, int(*cmp)(), void(*free_fct)(void*));
		//(*cmp)(list_ptr->data, data_ref);
		//(*free_fct)(list_ptr->data)
int		ft_atoi_base(char *str, char *base);

#endif