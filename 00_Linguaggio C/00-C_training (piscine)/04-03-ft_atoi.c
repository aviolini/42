/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 08:50:37 by aviolini          #+#    #+#             */
/*   Updated: 2020/11/03 14:09:27 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int		i;
	char	sign;
	int		risultato;

	risultato = 0;
	i = 0;
	while (str[i] && (str[i] == '\t' || str[i] == '\n' ||
str[i] == '\v' || str[i] == '\f' || str[i] == '\r' || str[i] == ' '))
		i++;
	sign = str[i++];
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if ((sign == '+' && str[i] == '-') || (sign == '+' && str[i] == '-'))
			sign = '-';
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		risultato = risultato * 10;
		risultato = risultato + (str[i] - '0');
		i++;
	}
	if (sign == '-')
		risultato = risultato * -1;
	return (risultato);
}
