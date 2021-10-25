/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 09:28:03 by aviolini          #+#    #+#             */
/*   Updated: 2021/02/11 15:29:14 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# define BASE16 "0123456789abcdef"
# define BASE16X "0123456789ABCDEF"
# define BASE10 "0123456789"
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct	s_option
{
	int		flag_minus;
	int		flag_zero;
	int		width;
	int		dot;
	int		precision;
	int		total_chars;
	int		num_is_zero;
	int		prev_was_perc;
	int		num_is_neg;
	int		prec_is_arg;
	char	type;
}				t_strutt;

int				ft_printf(const char *str, ...);
void			ft_init_strutt(t_strutt *strutt);
int				ft_char_is_perc(const char *str, int i, t_strutt *strutt);
int				ft_char_is_2perc(const char *str, int i, t_strutt *strutt);
void			ft_use_strutt(t_strutt *strutt, va_list ap);
int				ft_fill_strutt(t_strutt *strutt, const char *str,
				int i, va_list ap);
int				ft_typeflag(t_strutt *strutt, const char *str, int i);
int				ft_typewidth(t_strutt *strutt, const char *str,
				int i, va_list ap);
int				ft_typeprecision(t_strutt *strutt, const char *str,
				int i, va_list ap);
char			ft_typearg(const char *str, int i);
void			ft_d(t_strutt *strutt, va_list ap);
void			ft_s(t_strutt *strutt, va_list ap);
void			ft_c(t_strutt *strutt, va_list ap);
void			ft_xu(t_strutt *strutt, va_list ap, char *base);
void			ft_p(t_strutt *strutt, va_list ap);
int				ft_print_s_fl_min_0(char *str, int len, t_strutt *strutt);
int				ft_print_s_fl_min_1(char *str, int len, t_strutt *strutt);
int				ft_print_dxu(char *str, int len, t_strutt *strutt);
int				ft_print_p(char *str, int len, t_strutt *strutt);
int				ft_space(int y, t_strutt *strutt);
int				ft_zero(int x, t_strutt *strutt);
int				ft_putchar(char *str, int size, t_strutt *strutt);
int				ft_strlen(char *str);
void			ft_perc(t_strutt *strutt);
int				ft_zero_rather_space_sdxu(char *str, int len, t_strutt *strutt);
int				ft_zero_rather_space_p(char *str, int len, t_strutt *strutt);
int				ft_num_is_zero(t_strutt *strutt);
int				ft_num_is_null(t_strutt *strutt);
int				ft_num_is_neg(t_strutt *strutt, int num);
int				ft_size_nbr(int n);
char			*ft_itoa(int n);
int				ft_size_nbr_uns_diffbase(size_t n, char *base);
char			*ft_itoa_base(size_t n, int len, char *base);
char			*ft_strdup(char *str);
int				ft_numarg(char *str);
#endif
