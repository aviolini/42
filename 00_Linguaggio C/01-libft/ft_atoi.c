/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:08:25 by aviolini          #+#    #+#             */
/*   Updated: 2021/01/14 12:41:21 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t			i;
	long long int	neg;
	long long int	ret;

	i = 0;
	neg = 1;
	ret = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		if ((ret > 922337203685477580) && (str[i] - '0') > 7)
			return ((neg == 1) ? -1 : 0);
		ret = ret * 10 + *(str + i) - 48;
		i++;
	}
	return (ret * neg);
}
