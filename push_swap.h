/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:17:50 by zkarapet          #+#    #+#             */
/*   Updated: 2022/09/23 18:48:15 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				x;
	int				index;
	struct s_list	*next;
}	t_list;

typedef struct s_struct
{
	int		argc;
	char	*str;
	char	**av;
	int		*index;
	int		indx;
	int		indx1;
	int		max;
	int		max1;
	int		i;
	int		i1;
	char	**arr;
	int		len;
	int		size_b;
	int		size_a;
	int		k;
}	t_struct;

void		freeing(t_list *listik);
int			find_max(t_list *listik);
int			find_pos(t_list *listik, int x);
int			ft_lst_size(t_list *listik);
void		add_to_list(t_list **listik, t_struct *push);
void		indexing(t_list *listik, t_struct *push);
void		sort_to_max(t_struct *push);
char		**ft_split(char *str, char c);
long long	ft_atoi(const char *str);
void		ft_error(char *s);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strlen(char *str);
void		parsing(t_struct *push);
t_list		*ft_lstnew(int x);
t_list		*ft_lstadd_back(t_list *listik, t_list *new);
int			sab(t_list *listik, int flag);
void		ft_lstadd_front(t_list **listik, t_list *new_one);
int			pab(t_list **listik_a, t_list **listik_b, int flag);
int			rab(t_list **listik, int flag);
int			rrab(t_list **listik, int flag);
int			sorted_or_not(t_struct *push, t_list **listik);
void		algo_rythm(t_struct *push, t_list **listik_a, t_list **listik_b);

#endif
