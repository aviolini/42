/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:01:12 by aviolini          #+#    #+#             */
/*   Updated: 2020/10/29 13:58:32 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (i < size - 1)
	{
		while (src[i] != 0)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = 0;
		i++;
	}
	return (i - 1);
}
