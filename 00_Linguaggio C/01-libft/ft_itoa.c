/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:52:04 by aviolini          #+#    #+#             */
/*   Updated: 2021/01/19 17:22:45 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sznmb(int numb)
{
	int	i;

	i = 0;
	while (numb > 0)
	{
		numb = numb / 10;
		i++;
	}
	return (i);
}

char	*ft_iszero(int n)
{
	if (n == -0 || n == 0)
		return (ft_strdup("0"));
	return (ft_strdup("-2147483648"));
}

char	*ft_itoa(int n)
{
	int		sign;
	int		len;
	char	*ptr;

	len = 0;
	sign = 1;
	if (n < 0 && (n = n * -1) > 0)
		sign = -1;
	if (n == -0 || n == 0 || n == -2147483648)
		return (ft_iszero(n));
	len = ft_sznmb(n);
	if (sign == -1)
		len++;
	if (!(ptr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ptr[len] = '\0';
	len--;
	while (n > 0)
	{
		ptr[len--] = n % 10 + '0';
		n = n / 10;
	}
	if (sign == -1)
		ptr[len] = '-';
	return (ptr);
}
