/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:58:33 by zkarapet          #+#    #+#             */
/*   Updated: 2022/09/17 20:51:37 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <math.h>

int	sorted_or_not(t_struct *push, t_list **listik)
{
	int		i;
	t_list	*head;

	i = -1;
	head = *listik;
	if (!(*listik))
		return (2);
	while (++i <= push->len && head && push->index[i] == head->x)
		head = head->next;
	if (i == push->len)
		return (1);
	return (0);
}

void	fill_b(t_list **listik_a, t_list **listik_b, t_struct *push)
{
	int	counter;
	int	ras;
	int	max;
	int	i;
	int flag;

	counter = 0;
	ras = 0;
	i = 0;
	push->list_a = listik_a;
	push->list_b = listik_b;
	max = find_max(*listik_a);
	
	while (counter < push->len)
	{
		//printf("ras == %d\n", ras);
		//printf("address of a == %p\n", (*listik_a));
		if ((*(push->list_a))->index <= counter)
		{
			if ()
		    if (!pab(push->list_b, push->list_a, 0, push))
				ft_error("error appeared1!");
			if (!rab(push->list_b, 0, push))
				ft_error("error appeared2!");
			counter++;
		}
		else if ((*(push->list_a))->index <= counter + sqrt(push->len))
		{
			if (!pab(push->list_b, push->list_a, 0, push))
				ft_error("error appeared3!");
			ras++;
			counter++;
		}
		else
		{
			if (!rab(push->list_a, 1, push))
				ft_error("error appeared4!");
			ras++;
		}
	}
}

void	sort_a_in_place(t_list **listik_a, t_list **listik_b, t_struct *push)
{
	fill_b(listik_a, listik_b, push);
	t_list **a;
	t_list **b;

	a = listik_a;
	b = listik_b;
//	printf("add is == %p\n", *listik_a);
//	while (*a)
//	{
//		printf("index == %d\n", (*a)->x);
//		*a = (*a)->next;
//	}
//	while (b)
//	{
//		printf("%d\n", b->index);
//		b = b->next;
//	}
//	push->i1 = -1;
	int j = 0;
//	push->list_a1 = listik_a;
//	push->size_a = ft_lst_size(*listik_a);
//	while (++j < 6)
//	{
		printf("placei cikln em\n");
		push->i1 = -1;
		push->max1 = find_max(*push->list_a1);
//		push->indx1 = find_pos(*push->list_a1, push->max1);
//		if (push->indx1 <= push->size_a / 2)
//		{
//			while (++push->i1 < push->indx1)
//			{
//				printf("Anverj em \n");
//				if (!rab(push->list_a1, 0, push))
//					ft_error("error appeared2!");
//			}
//		}
//		else
//			while (++push->i1 < push->size_a - push->indx1)
//				if (!rrab(push->list_a1, 0, push))
//					ft_error("error appeared2!");
//	}
}

void	fill_back_to_a(t_list **listik_a, t_list **listik_b, t_struct *push)
{
	push->i = -1;
	push->list_a = listik_a;
	push->list_b = listik_b;
	push->size_b = ft_lst_size(*listik_b);
	while (push->list_b && (*push->list_b))
	{
		push->i = -1;
		push->max = find_max(*push->list_b);
		push->indx = find_pos(*push->list_b, push->max);
		if (!push->indx)
			if (!pab(push->list_a, push->list_b, 1, push))
				ft_error("error appeared1!");
		if (push->indx <= push->size_b / 2)
		{
			while (++push->i < push->indx)
			{
				printf("Anverj em back to a\n");
				if (!rab(push->list_b, 0, push))
					ft_error("error appeared2!");
			}
		}
		else
			while (++push->i < push->size_b - push->indx)
				if (!rrab(push->list_b, 0, push))
					ft_error("error appeared2!");
	}
}

void	algo_rythm(t_struct *push, t_list **listik_a, t_list **listik_b)
{
	int		i;
	int		counter;
	t_list	**head;

	push->k = 0;
	i = -1;
	counter = 0;
	head = listik_a;
	printf("address == %p *** %d\n", *listik_a, (*listik_a)->index);
//	if (sorted_or_not(push, listik_a) == 2)
//		exit(0);
//	if (sorted_or_not(push, listik_a))
//		ft_error("already sorted");
//	while (!sorted_or_not(push, listik_a))
//	{
		sort_a_in_place(listik_a, listik_b, push);
		fill_back_to_a(listik_a, listik_b, push);
//	}
}

int	main(int argc, char **argv)
{
	int			i;
	t_struct	*push;
	t_list		*a;
	t_list		*b;

	a = malloc(sizeof(t_list));
	b = malloc(sizeof(t_list));
	push = malloc(sizeof(t_struct));
	i = -1;
	a = NULL;
	b = NULL;
	if (!push)
		ft_error("malloc failed");
	push->av = argv;
	push->argc = argc;
	parsing(push);
	add_to_list(&a, push);
	indexing(a, push);
	algo_rythm(push, &a, &b);
	while (a)
	{
		printf("%d\n", a->index);
		a = a->next;
	}
//	printf("k == %d\n", push->k);
//	free(push->index);
//	freeing(a);
//	freeing(b);
//	while (1);
}
