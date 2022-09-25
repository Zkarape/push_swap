/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:58:33 by zkarapet          #+#    #+#             */
/*   Updated: 2022/09/23 14:57:21 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_b(t_list **listik_a, t_list **listik_b, t_struct *push)
{
	int	counter;

	counter = 0;
	if (push->len > 100)
		push->k = 30;
	else
		push->k = 15;
	while (counter < push->len)
	{
		if ((*listik_a)->index <= counter)
		{
			pab(listik_b, listik_a, 0);
			rab(listik_b, 0);
			counter++;
		}
		else if ((*(listik_a))->index <= counter + push->k)
		{
			pab(listik_b, listik_a, 0);
			counter++;
		}
		else
			rab(listik_a, 1);
	}
}

void	fill_back_to_a(t_list **listik_a, t_list **listik_b, t_struct *push)
{
	while (listik_b && (*listik_b))
	{
		push->i = -1;
		push->size_b = ft_lst_size(*listik_b);
		push->indx = find_pos(*listik_b, push->size_b - 1);
		if (push->indx <= push->size_b / 2)
		{
			while (++push->i < push->indx)
				rab(listik_b, 0);
		}
		else if (push->indx > push->size_b / 2)
		{
			while (++push->i < push->size_b - push->indx)
				rrab(listik_b, 0);
		}
		if (!push->indx)
			pab(listik_a, listik_b, 1);
	}
}

void	for_three(t_list **listik_a, t_struct *push)
{
	int	indx;

	push->len = 3;
	indx = find_pos(*listik_a, 2);
	if (indx == 1)
		rrab(listik_a, 1);
	else if (!indx)
		rab(listik_a, 1);
	if (!sorted_or_not(push, listik_a))
		sab(*listik_a, 1);
}

void	for_five(t_list **listik_a, t_list **listik_b, t_struct *push)
{
	push->size_a = push->len;
	push->i1 = -1;
	while (++push->i1 < push->len - 3)
	{
		push->i = -1;
		push->indx = find_pos(*listik_a, push->size_a - 1);
		if (push->indx <= push->size_a / 2)
			while (++push->i < push->indx)
				rab(listik_a, 1);
		else
			while (++push->i < push->size_a - push->indx)
				rrab(listik_a, 1);
		pab(listik_b, listik_a, 0);
		push->size_a--;
	}
	for_three(listik_a, push);
	push->size_b = ft_lst_size(*listik_b);
	if (push->size_b > 1 && (*listik_b)->index > (*listik_b)->next->index)
		sab(*listik_b, 0);
	while (push->size_b)
	{
		pab(listik_a, listik_b, 1);
		rab(listik_a, 1);
		push->size_b--;
	}
}

void	algo_rythm(t_struct *push, t_list **listik_a, t_list **listik_b)
{
	if (sorted_or_not(push, listik_a))
		;
	if (push->len > 5)
	{
		fill_b(listik_a, listik_b, push);
		fill_back_to_a(listik_a, listik_b, push);
	}
	else if (push->len == 3)
		for_three(listik_a, push);
	else
		for_five(listik_a, listik_b, push);
}
