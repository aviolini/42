/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 10:05:09 by aviolini          #+#    #+#             */
/*   Updated: 2021/01/19 17:38:44 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *newelement;

	if (!(newelement = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	newelement->content = content;
	newelement->next = NULL;
	return (newelement);
}
