/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:58:33 by zkarapet          #+#    #+#             */
/*   Updated: 2022/09/07 18:35:19 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted_or_not(t_struct *push, t_list *listik)
{
	int		i;
	t_list	*head;

	i = 0;
	head = listik;
	while (i <= push->len)
	{
		if (push->index[i] != head->x)
			break;
		i++;
		head = head->next;
	}
	if (i == push->len)
		return (1);//sorted
	return (0);//not sorted
}

void	algo_rythm(t_struct *push, t_list *listik_a, t_list *listik_b)
{
	int		i;
	int		counter;
	t_list	*head;

	i = -1;
	counter = 0;
	head = listik_a;
	if (sorted_or_not(push, listik_a))
		ft_error("already sorted");
	while (!sorted_or_not(push, listik_a))
	{
		if (listik_a->index <= counter)
		{
			if (!pab(&listik_b, &listik_a))
				ft_error("error appeared!");
			if(!rab(&listik_b))
				ft_error("error appeared!");
			counter++;
		}
		else if (listik_a->index <= counter++)
		{
			if (!pab(&listik_b, &listik_a))
				ft_error("error appeared!");
			counter++;
		}
		else
		{
			if(!rab(&listik_b))
				ft_error("error appeared!");
		}
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
	t_list	*b = malloc(sizeof(t_list));
	a->next = NULL;
	b->next = NULL;
	b->index = 9;
	b->x = 10;
	add_to_list(a, push);
	indexing(a, push);
//	pab(&b, &a);
	pab(&a, &b);
//	rab(&a);
//	algo_rythm(push, a, b);
	while (b)
	{
		printf("index_b == %d x == %d\n", b->index, b->x);
		b = b->next;
	}
//	while (a)
//	{
//		printf("index_a == %d x == %d\n", a->index, a->x);
//		printf("in_b == %d x == %d\n", b->index, b->index);
//		a = a->next;
//		b = b->next;
//	}
}
