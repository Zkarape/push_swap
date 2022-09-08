/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:17:50 by zkarapet          #+#    #+#             */
/*   Updated: 2022/09/08 21:33:12 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_list
{
	int				x;
	int				index;
	struct s_list	*next;
}	t_list;

typedef	struct	s_struct
{
	int		argc;
	char	*str;
	char	**av;
	char	*main_str;
	int		*index;
	char	**arr;
	int		min;
	int		len;
	int		*res;
}	t_struct;

void	add_to_list(t_list *listik, t_struct *push);
void	indexing(t_list *listik, t_struct *push);
void	sort(t_struct *push);
char	**ft_split(char *str, char c);
int		ft_atoi(const char *str);
void	ft_error(char *s);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
void	parsing(t_struct *push);
t_list	*ft_lstnew(int	x);
void	ft_lstadd_back(t_list *listik, t_list *new_one);
int		sab(t_list *listik, int flag);
void	ft_lstadd_front(t_list **listik, t_list *new_one);
int		pab(t_list **listik_a, t_list **listik_b, int flag);
int	rab(t_list **listik, int flag);
int	rrab(t_list **listik, int flag);

#endif
