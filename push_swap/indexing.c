/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:45:36 by zkarapet          #+#    #+#             */
/*   Updated: 2022/09/02 21:52:54 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_to_list(t_list *listik, t_struct *push)
{
	int	i;

	i = 0;
	while (i < push->len)
	{
		ft_lstadd_back(listik, ft_lstnew(push->index[i]));
		i++;
	}
}

void	indexing(t_list *listik, t_struct *push)
{
	int		i = push->len;
	int		k = 0;
	t_list	*head;

	head = listik;
	sort(push);
	while (head && head->next)
	{
		while (i > 0 && push->index[i] != head->x)
			i--;
//			if (push->index[i] == head->x)
//			{
//				printf("%d\n", push->index[0]);
//				printf("index[i] == %d i == %d x == %d\n",  push->index[i], i, head->x);
//				head->index = i;
//				break ;
//			}
//			i++;
		if (i != 0)
			head->index = i;
		printf("%d\n", i);
		i = push->len;
		head = head->next;
	}
}

int	main(int argc, char **argv)
{
	int i = -1;
	t_struct	*push;
	push = malloc(sizeof(t_struct));
	if (!push)
		ft_error("malloc failed");
	push->av = argv;
	push->argc = argc;
	parsing(push);
	t_list	*a = malloc(sizeof(t_list));
//	t_list	*b = malloc(sizeof(t_list));
	//t_list	*c = malloc(sizeof(t_list));
	a->x = ft_atoi(argv[1]);
//	b->x = ft_atoi(argv[2]);
//	c->x = ft_atoi(argv[3]);
	a->next = NULL;
//	b->next = NULL;
//	c->next = NULL;
//	rrab(&a);
//	printf("t == %d\n", t);
//	ft_lstadd_front(&a, b);
	add_to_list(a, push);
	indexing(a, push);
	while (++i < push->len)
		printf("k == %d i == %d\n", push->index[i], i);
	while (a && a->next)
	{
		printf("index == %d x == %d\n", a->index, a->x);
		a = a->next;
	}
}
