/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 10:17:42 by aviolini          #+#    #+#             */
/*   Updated: 2020/11/02 14:18:26 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int y;
	unsigned int x;
	unsigned int i;

	y = 0;
	x = 0;
	i = 0;
	while (dest[x])
		x++;
	while (src[y])
		y++;
	if ((size - 1) < x)
		return (y + size);
	while ((x + i) < size - 1)
	{
		dest[x + i] = src[i];
		i++;
	}
	dest[x + i] = 0;
	return (x + y);
}
