/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 11:19:58 by aviolini          #+#    #+#             */
/*   Updated: 2020/11/12 12:19:52 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

char *ft_original(char *newpt)
{
	int i = 0;
	char *c;
	char original[111];
	
	while (newpt[i] != '\n')
	{
		original[i] = newpt[i];
		i++;
	}

	original[i] = 0;
	c = original;

return c;
}

int		main(int argc, char **argv)
{
	int		fd;
	char	newpt[1024];
	int		c;
		
		if (argc == 1)
        {
            read(0,&newpt,1024);
			main2(newpt);
        }

	c = 1;
	while (c < argc)
	{
		fd = open(argv[c], O_RDONLY, 0);
		read(fd, &newpt, 1024);
		main2(newpt);
		c++;
	}
}	

int	 main2(char *newpt)
{
	int		**tabella;
	int		**square;
	int		**punt;
	char	*original;
	int len;

	original = ft_original(newpt);
	ft_primariga(newpt);
	len = ft_len_row(newpt);
	if (check_map(newpt,original) == 0)
	{
		write(1, "map error\n", 10);
		return (0);
	}
	tabella = ft_tabella(newpt,original, **punt);
	square = ft_campari(tabella);
	punt = ft_finder(tabella,newpt);
	
	return 0;
}

