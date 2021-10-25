/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:24:14 by aviolini          #+#    #+#             */
/*   Updated: 2021/04/23 17:11:40 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>

unsigned long	ft_strlen(const char *s);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strcpy1(char *dst, const char *src);
char			*ft_strcpy2(char *dst, const char *src);
int				ft_strcmp(const char *str1, const char *str2);
int				ft_strcmp1(const char *str1, const char *str2);
ssize_t			ft_write(int fd, const void *buf, size_t count);
ssize_t			ft_read(int fd, void *buf, size_t nbyte);
char			*ft_strdup(const char *s);

#endif