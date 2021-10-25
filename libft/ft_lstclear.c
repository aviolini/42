/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 12:41:38 by aviolini          #+#    #+#             */
/*   Updated: 2021/01/21 10:53:34 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *ptr;
	t_list *ptr2;

	if (!lst || !del)
		return ;
	ptr = *lst;
	ptr2 = *lst;
	while (ptr)
	{
		ptr2 = ptr2->next;
		del(ptr->content);
		free(ptr);
		ptr = ptr2;
	}
	*lst = NULL;
}
