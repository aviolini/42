/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulloa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 12:05:34 by fulloa-s          #+#    #+#             */
/*   Updated: 2020/11/12 12:20:37 by fulloa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# define PERMS 0666

void	*ft_primariga(char *newpt);
int		**ft_tabella(char *newpt, char *original, int **punt);
int		**ft_finder(int **tabella, char *newpt);
int		**ft_campari(int **tabella);
char	ft_find_empty(char *map);
char	ft_find_obs(char *map);
char	ft_find_full(char *map);
int		main2(char *newpt);
int		check_map(char *map, char *original);
int		ft_num(char newpt, int tab, char *original);
void	ft_write2(char *newpt);
int		ft_len_row(char *map);
int		ft_len_rows_tab(int **tabella);

#endif
