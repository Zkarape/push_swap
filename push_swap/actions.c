/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:33:50 by zkarapet          #+#    #+#             */
/*   Updated: 2022/09/02 16:44:53 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sab(t_list *listik)
{
	t_list	*s;

	s = listik;
	if (s && s->next)
	{
		s->index = s->index + s->next->index;
		s->next->index = s->index - s->next->index;
		s->index = s->index - s->next->index;
		return (1);
	}
	return (0);
}

int	pab(t_list *listik_a, t_list *listik_b)
{
	t_list	*add;

	add = listik_b;
	if (!listik_b)
		return (0);
	ft_lstadd_front(&listik_a, add);
	return (1);
}

int	rab(t_list *listik)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	new->x = listik->x;
	new->index = listik->index;
	if (!new)
		return (0);
	ft_lstadd_back(listik, new);
	new->next = NULL;
	return (1);
}

int	rrab(t_list **listik)
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
	return (1);
}
