/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 21:57:57 by arrigo            #+#    #+#             */
/*   Updated: 2021/05/26 14:28:23 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

typedef struct s_data
{
	t_list	**a;
	t_list	**b;
	t_list	**steps;
	int		max;
	int		min;
	int		med;
	int		i;
	int		flag_st_output;
}			t_data;

typedef struct s_tot
{
	int		tot_r;
	int		tot_rr;
	int		tot_ra_rrb;
	int		tot_rb_rra;	
}				t_tot;

/*MAIN PUSH_SWAP*/
int		ft_shortcut_sort(t_data *s);
/*MAIN CHECKER*/
void	ft_do_steps(t_data *s, t_list *temp);
/*INIT AND EXIT*/
int		ft_init(t_data **s);
void	ft_exit(t_data *s);
void	ft_exit_error(t_data *s);
/*ARG*/
int		ft_av_is_empty(char *s);
int		ft_check_ac(int ac, char **av);
int		ft_check_arg(char *s);
int		ft_insert_arg(t_list **a, char *s, int *i);
int		ft_add_args_to_list(t_list **a, int ac, char **av);
/*SORT_MIN_OF_FIVE*/
int		ft_sort_two(t_data *s);
int		ft_sort_three(t_data *s);
int		ft_sort_three_p1(t_data *s);
int		ft_sort_four(t_data *s);
int		ft_sort_four_p1(t_data *s);
/*SORT FIVE*/
int		ft_sort_five(t_data *s);
void	ft_sort_five_p0(t_data *s);
/*SORT_FIVE_PARTS*/
void	ft_sort_five_p1(t_data *s);
int		ft_sort_five_p2(t_data *s);
void	ft_sort_five_p3(t_data *s);
int		ft_sort_five_p4(t_data *s);
void	ft_sort_five_p5(t_data *s);
/*DEFINE STEPS*/
int		ft_sa(t_data *s);
int		ft_sb(t_data *s);
int		ft_ss(t_data *s);
int		ft_pa(t_data *s);
int		ft_pb(t_data *s);
/*DEFINE STEPS2*/
int		ft_ra(t_data *s);
int		ft_rb(t_data *s);
int		ft_rr(t_data *s);
/*DEFINE STEPS3*/
int		ft_rra(t_data *s);
int		ft_rrb(t_data *s);
int		ft_rrr(t_data *s);
/* OPERATIONS_STACK_A*/
void	ft_split_stack_a(t_data *s);
void	ft_pre_split_stack_a(t_data *s, int max_index, int max_data);
void	ft_subsequence(t_data *s);
void	ft_write_index(t_list *temp);
/* OPERATIONS_STACK_A_2*/
int		ft_next_index_data(t_list *temp, int idx, int max_data);
int		ft_check_index(t_data *s, int max_index, int max_data);
void	ft_max_index(t_data *s, int *max_index, int *max_data);
int		ft_set_index(t_data *s, int max_index, int max_data);
/* OPERATIONS_STACK_B*/
int		ft_number_operations(t_data *s);
int		ft_best_combo(t_data *s);
void	ft_best_number(t_data *s);
void	ft_last_sort(t_data *s);
/* OPERATIONS_STACK_B_2*/
int		ft_tot_rra(t_data *s, t_list *temp_b);
int		ft_tot_ra(t_data *s, t_list *temp_b);
void	ft_calc_totals(t_tot *tot, t_list *tmp);
void	ft_set_flag_and_tot(t_tot tot, t_list *tmp);
/* OPERATIONS_STACK_B_3*/
int		ft_do_ra_rrb(t_data *s, t_list *temp_b);
int		ft_do_rb_rra(t_data *s, t_list *temp_b);
int		ft_do_rra_rrb(t_data *s, t_list *temp_b);
int		ft_do_ra_rb(t_data *s, t_list *temp_b);

#endif