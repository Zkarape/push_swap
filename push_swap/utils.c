/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:38:43 by zkarapet          #+#    #+#             */
/*   Updated: 2022/09/09 22:19:18 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	unsigned int	res;
	int				min;
	int				i;

	min = 1;
	res = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			min = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * min);
}

t_list	*ft_lstnew(int x)
{
	t_list	*t;

	t = malloc(sizeof(t_list));
	if (!t)
		return (NULL);
	t->x = x;
	t->next = NULL;
	return (t);
}

void	ft_lstadd_front(t_list **listik, t_list *new)
{
	new->next = *listik;
	*listik = new;
}

int	ft_lstadd_back(t_list **listik, t_list *new_one)
{
	t_list	*last;

	if ((*listik) == NULL)
		(*listik) = new_one;
	last = *listik;
	printf("%p\n", last);
	while (last && last->next)
	{
//		printf("%d\n", last->next->x);
		last = last->next;
	}
	last->next = new_one;
	return (1);
}
