/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:35:02 by zkarapet          #+#    #+#             */
/*   Updated: 2022/09/22 22:41:06 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_pos(t_list *listik, int x)
{
	int		i;
	t_list	*move;

	i = 0;
	move = listik;
	while (move)
	{
		if (move->index == x)
			return (i);
		move = move->next;
		i++;
	}
	return (0);
}

int	find_max(t_list *listik)
{
	int		max;
	t_list	*head;

	head = listik;
	if (!head)
	{
		printf("NULL\n");
		return (0);
	}
	max = head->index;
	if (!head)
	{
		printf("NULL\n");
		return (0);
	}
	while (head && head->next)
	{
		if (head->next->index > max)
			max = head->next->index;
		head = head->next;
	}
	return (max);
}
