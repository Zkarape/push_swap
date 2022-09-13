/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:33:50 by zkarapet          #+#    #+#             */
/*   Updated: 2022/09/13 17:23:10 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sab(t_list *listik, int flag, t_struct *push)
{
	t_list	*s;

	s = listik;
	if (s && s->next)
	{
		s->index = s->index + s->next->index;
		s->next->index = s->index - s->next->index;
		s->index = s->index - s->next->index;
		if (flag == 1)
			write(1, "sa\n", 3);
		else if (flag == 0)
			write(1, "sb\n", 3);
		push->k++;
		return (1);
	}
	return (0);
}

int	pab(t_list **listik_a, t_list **listik_b, int flag, t_struct *push)
{
	t_list	*add;
	t_list	*next_b;

	add = malloc(sizeof(t_list));
	next_b = (*listik_b)->next;
	if (!add)
		return (0);
	add->x = (*listik_b)->x;
	add->index = (*listik_b)->index;
	ft_lstadd_front(listik_a, add);
	free((*listik_b));
	(*listik_b) = next_b;
	if (flag == 1)
		write(1, "pa\n", 3);
	else if (flag == 0)
		write(1, "pb\n", 3);
	push->k++;
	return (1);
}

int	rab(t_list **listik, int flag, t_struct *push)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!(*listik))
		return (0);
	if (!new)
		return (0);
	new->x = (*listik)->x;
	new->index = (*listik)->index;
	ft_lstadd_back(listik, new);
	*listik = (*listik)->next;
	new->next = NULL;
	if (flag == 1)
		write(1, "ra\n", 3);
	else if (flag == 0)
		write(1, "rb\n", 3);
	push->k++;
	return (1);
}

int	rrab(t_list **listik, int flag, t_struct *push)
{
	t_list	*new;
	t_list	*head;
	t_list	*last;

	head = *listik;
	if (!*listik)
		return (0);
	while (*listik && (*listik)->next && (*listik)->next->next)
		*listik = (*listik)->next;
	last = *listik;
	new = (*listik)->next;
	*listik = head;
	ft_lstadd_front(listik, new);
	last->next = NULL;
	if (flag == 1)
		write(1, "rra\n", 4);
	else if (flag == 0)
		write(1, "rrb\n", 4);
	push->k++;
	return (1);
}
