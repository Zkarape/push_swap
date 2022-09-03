/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:45:36 by zkarapet          #+#    #+#             */
/*   Updated: 2022/09/03 18:36:29 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_to_list(t_list *listik, t_struct *push)
{
	int	i;

	i = 1;
	listik->x = push->index[0];
	while (i < push->len)
	{
		ft_lstadd_back(listik, ft_lstnew(push->index[i]));
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

int	main(int argc, char **argv)
{
	int			i;
	t_struct	*push;

	i = -1;
	push = malloc(sizeof(t_struct));
	if (!push)
		ft_error("malloc failed");
	push->av = argv;
	push->argc = argc;
	parsing(push);
	t_list	*a = malloc(sizeof(t_list));
//	t_list	*b = malloc(sizeof(t_list));
//	t_list	*c = malloc(sizeof(t_list));
//	b->x = 10;
//	b->index = -10;
//	c->x = 20;
//	c->index = -20;
	a->next = NULL;
//	b->next = c;
//	c->next = NULL;
	add_to_list(a, push);
	indexing(a, push);
	rrab(&a);
	while (a)
	{
		printf("index == %d x == %d\n", a->index, a->x);
		a = a->next;
	}
}
