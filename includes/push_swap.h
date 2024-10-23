/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:32:48 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/16 18:45:40 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef struct s_dlist
{
	int				content;
	int				index;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}	t_dlist;

typedef struct s_lists
{
	t_dlist	*a;
	t_dlist	*b;
	size_t	count;

}	t_lists;

typedef struct s_order
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	rr;
	int	rrr;
	int	sa;
	int	sb;
}	t_order;

//CHECKER functions
int		content_checker(char **argv);
int		doubles_checker(char **argv);
void	ps_checker(t_lists *stacks, char *line);
void	ps_checker(t_lists *stacks, char *line);
void	ps_checker_last(t_lists *stacks, char *line);
void	ps_checker_error(int argc);

//BUILDER functions
t_lists	*list_builder(t_lists *stacks, char **argv);
t_lists	*ps_stacks_init(t_lists *stacks);

//LISTER functions
t_dlist	*ps_lstnew(int content, int index	);
void	ps_lstadd_back(t_dlist **lst, t_dlist *new);
void	ps_lstadd_front(t_dlist **lst, t_dlist *new);
int		ps_lstsize(t_dlist *lst);
t_dlist	*ps_lstlast(t_dlist *lst);
t_dlist	*ps_secondlast(t_dlist *lst);
t_dlist	*ps_lstfirst(t_dlist *lst);
void	ps_lstclear(t_dlist **lst);

//OPERATOR functions
t_dlist	*ps_lstswap(t_dlist *first);
t_lists	*ps_lstpushb(t_lists *stacks);
t_lists	*ps_lstpusha(t_lists *stacks);
t_dlist	*ps_lstrotate(t_dlist *lst);
t_dlist	*ps_lstrrotate(t_dlist *lst);

//SWAPPER functions
t_lists	*ps_sa(t_lists *stacks, int flag);
t_lists	*ps_sb(t_lists *stacks, int flag);
t_lists	*ps_ss(t_lists *stacks, int flag);

//PUSHER functions
t_lists	*ps_pb(t_lists *stacks, int flag);
t_lists	*ps_pa(t_lists *stacks, int flag);

//ROTATOR functions
t_lists	*ps_rb(t_lists *stacks, int flag);
t_lists	*ps_ra(t_lists *stacks, int flag);
t_lists	*ps_rr(t_lists *stacks, int flag);

//RROTATOR functions
t_lists	*ps_rrb(t_lists *stacks, int flag);
t_lists	*ps_rra(t_lists *stacks, int flag);
t_lists	*ps_rrr(t_lists *stacks, int flag);

//SSORTER functions
t_lists	*sort(t_lists *stacks);
t_lists	*ps_ssort(t_lists *stacks);
t_lists	*sort_3(t_lists *stacks);
t_lists	*sort_4(t_lists *stacks);
t_lists	*sort_5(t_lists *stacks);
int		is_sorted(t_lists *stacks);

//BSORTER functions
t_lists	*ps_bsort(t_lists *stacks);
t_lists	*ps_return(t_lists *stacks);
t_lists	*ps_finalize(t_lists *stacks);
int		ps_find_cheapest_position(t_lists *stacks, t_order **order);
t_lists	*ps_process_pos(t_lists *stacks, t_order *order, int cheapest_position);

//COST_CALCULATOR functions
int		ps_a_pos_in_b(t_lists *stacks, int value);
int		ps_index(int n, t_dlist *stack);
int		ps_position_bcost(int b_size, int position, t_order **order);
int		ps_position_acost(int a_size, int position, t_order **order);
int		ps_discounter(int cost, t_order **order);
int		ps_final_cost(t_lists *stacks, int value, t_order **order);
int		ps_cheapest_position(t_lists *stacks, t_order **order);

//ORDER_MANAGER functions
int		ps_b_pos_order(t_lists *stacks, int value);
t_order	*ps_fill_order(t_lists *stacks, t_order *order, int a, int b);
t_order	*ps_handle_a(t_order *order, int a, int a_size);
t_order	*ps_handle_b(t_order *order, int b, int b_size);
t_order	*ps_order_init(t_order *order);
t_order	*ps_order_discounter(t_order *order);
t_order	*ps_order(t_lists *stacks, t_order *order, int a, int b);

//EXECUTER functions
t_lists	*ps_execute(t_lists *stacks, t_order *order);
t_lists	*ps_execute_continue(t_lists *stacks, t_order *order);

//MINIMIZER functions
int		ps_s_index(t_dlist *stack);
int		ps_new_bmin(int value, t_dlist *b);
t_lists	*ps_amin_to_top(t_lists *stacks, t_dlist *stack, int s_index);
t_lists	*ps_bmin_to_top(t_lists *stacks, t_dlist *stack, int s_index);

//MAXIMIZER functions
int		ps_m_index(t_dlist *stack);
int		ps_new_bmax(int value, t_dlist *b);
t_lists	*ps_amax_to_top(t_lists *stacks, t_dlist *stack, int m_index);
t_lists	*ps_bmax_to_top(t_lists *stacks, t_dlist *stack, int m_index);

//RETURNER functions
t_lists	*ps_return_num(t_lists *stacks, int value);
int		ps_b_pos_in_a(t_lists *stacks, int value);
int		ps_mid_return(t_lists *stacks, int value);

#endif
