/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:45:36 by zkarapet          #+#    #+#             */
/*   Updated: 2022/09/09 22:18:54 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_to_list(t_list *listik, t_struct *push)
{
	int	i;

	i = 0;
	while (i < push->len)
	{
		ft_lstadd_back(&listik, ft_lstnew(push->index[i]));
		//printf("i am still here\n");
		i++;
	}
}

void	indexing(t_list *listik, t_struct *push)
{
	int		i;
	t_list	*head;

	head = listik;
	sort(push);
	i = 0;
	while (head)
	{
		while (i < push->len && push->index[i] != head->x)
			i++;
		head->index = i;
		i = 0;
		head = head->next;
	}
}
