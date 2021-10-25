/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:24:28 by aviolini          #+#    #+#             */
/*   Updated: 2020/11/12 10:26:48 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void ft_write2(char *str)
{
	int x;

	x =0;
	while(str[x])
	{
		write(1,&str[x],1);
		x++;
	}
}

void ft_write(int pt, int y,char *newpt,int max, int len)
{	
	int i;
	int c;
	int max2;
	int y2;
	int maxconst;

	maxconst=max;
	max2 = max;
	y2 =y;
	while ((max2 - 1) > 0)
{
	y = y2;
	while((max -1)  > 0)
	{
		newpt[pt * len + y] = 'x';
		y--;
		max--;
	}
	max = maxconst;
	max2--;
	pt--;
}	
	printf("\n%s",newpt);
	ft_write2(newpt);
}


int **ft_finder(int **tabella, char *newpt)
{
	int c;
	int i;
	int max;
	int pt;
	int y;

	max =0;
	c =0;
	y=0;
	while (c<10)
    {
        i=0;
    while (tabella[c][i])
    {
		if (tabella[c][i] > max)
		{
			max = tabella[c][i];
			pt = c;//&tabella[c][i];
			printf("\npt %dy %d max %d \n", pt,i, max);
			y=i;
		}
    //printf("%d",tabella[c][i]);
    i++;
    }
    //printf("\n");i
    c++;
    }
	c = ft_len_rows_tab(tabella);
	newpt[pt * c + y] = 'x';
	printf("%s",newpt);
ft_write(pt,y,newpt,max,c);


return 0;
	
}
