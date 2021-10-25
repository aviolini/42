/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:29:17 by aviolini          #+#    #+#             */
/*   Updated: 2020/11/12 12:25:49 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int		**ft_campari(int **tabella)
{
	int k;
	int z;
	int c;

	k = 0;
	c = 0;
	while ((k + 1) < 10)
	{
		z = 0;
		while (tabella[k][z + 1])
		{
			while (tabella[k][z] == 1 || tabella[k + 1][z] == 1 ||
					tabella[k][z + 1] == 1 || tabella[k + 1][z + 1] == 1)
				z++;
			if (tabella[k][z] <= tabella[k + 1][z] &&
				   	tabella[k][z] <= tabella[k][z + 1])
					tabella[k + 1][z + 1] = tabella[k][z] + 1;
			else if (tabella[k][z + 1] <= tabella[k + 1][z])
                    tabella[k + 1][z + 1] = tabella[k][z + 1] + 1;
			else
				tabella[k + 1][z + 1] = tabella[k + 1][z] + 1;
			z++;
		}
		k++;
	}
return (tabella);
}
