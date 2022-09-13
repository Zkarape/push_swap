/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:17:50 by zkarapet          #+#    #+#             */
/*   Updated: 2022/09/13 17:23:07 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

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
	int		max;
	int		i;
	char	**arr;
	int		len;
	int		size_b;
	int		k;
	t_list	**list_a;
	t_list	**list_b;
}	t_struct;

void	freeing(t_list *listik);
int		find_max(t_list *listik);
int		find_pos(t_list *listik, int x);
int		ft_lst_size(t_list **listik);
void	add_to_list(t_list **listik, t_struct *push);
void	indexing(t_list *listik, t_struct *push);
void	sort_to_max(t_struct *push);
char	**ft_split(char *str, char c);
int		ft_atoi(const char *str);
void	ft_error(char *s);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
void	parsing(t_struct *push);
t_list	*ft_lstnew(int x);
int		ft_lstadd_back(t_list **listik, t_list *new_one);
int		sab(t_list *listik, int flag, t_struct *push);
void	ft_lstadd_front(t_list **listik, t_list *new_one);
int		pab(t_list **listik_a, t_list **listik_b, int flag, t_struct *push);
int		rab(t_list **listik, int flag, t_struct *push);
int		rrab(t_list **listik, int flag, t_struct *push);

#endif
