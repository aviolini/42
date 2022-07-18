/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 21:47:40 by aviolini          #+#    #+#             */
/*   Updated: 2020/10/29 17:29:35 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		if ((str[i] >= 'a' && str[i] <= 'z') && ((str[i - 1] >= 32 &&
						str[i - 1] <= 47) || (str[i - 1] >= 58 &&
						str[i - 1] <= 64) || (str[i - 1] >= 91 &&
						str[i - 1] <= 96) || (str[i - 1] >= 123 &&
						str[i - 1] <= 126)))
		{
			str[i] = str[i] - 32;
		}
		i++;
	}
	return (str);
}