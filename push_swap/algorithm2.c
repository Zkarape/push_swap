/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:58:33 by zkarapet          #+#    #+#             */
/*   Updated: 2022/09/22 21:41:45 by zkarapet         ###   ########.fr       */
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
	int	i;
	int	x;

	counter = 0;
	i = 0;
	if (push->len > 100)
		x = 30;
	else
		x = 15;
	while (counter < push->len)
	{
		if ((*listik_a)->index <= counter)
		{
			if (!pab(listik_b, listik_a, 0, push))
				ft_error("error appeared1!");
			if (!rab(listik_b, 0, push))
				ft_error("error appeared2!");
			counter++;
		}
		else if ((*(listik_a))->index <= counter + x)
		{
			if (!pab(listik_b, listik_a, 0, push))
				ft_error("error appeared3!");
			counter++;
		}
		else
			if (!rab(listik_a, 1, push))
				ft_error("error appeared4!");
	}
//	push->list_b = listik_b;
//	while (*push->list_b)
//	{
//		printf("index == %d\n", (*push->list_b)->index);
//		*push->list_b = (*push->list_b)->next;
//	}
}

void	fill_back_to_a(t_list **listik_a, t_list **listik_b, t_struct *push)
{
	if (sorted_or_not(push, listik_b))
		ft_error("sorted");
	int	max_pos;
	int	pos;
	int	i = -1;
	push->list_a = listik_a;
	push->list_b = listik_b;
	push->size_b = ft_lst_size(*listik_b);
//	printf("b == %d\n",push->size_b);
	while (*listik_b && listik_b && push->size_b)
	{
		max_pos = find_pos(*listik_b, push->size_b - 1);
		if (max_pos	<= push->size_b / 2)
		{
			while (max_pos != 0)
			{
				rab(listik_b, 0, push);
				max_pos = find_pos(*listik_b, push->size_b - 1);
			}
		}
		else
		{
			while (max_pos != 0)
			{
				rrab(listik_b, 0, push);
				max_pos = find_pos(*listik_b, push->size_b - 1);
			}
		}
//		while (!max_pos)
//		{
//			if (max_pos	< push->size_b / 2)
//				rab(listik_b, 0, push);
//			else
//				rrab(listik_b, 0, push);
//		}
		pab(listik_a, listik_b, 1, push);
		push->size_b--;
	}
//	while (*push->list_a)
//	{
//		printf("index == %d\n", (*push->list_a)->index);
//		(*push->list_a) = (*push->list_a)->next;
//	}
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
	if (sorted_or_not(push, listik_a) == 2)
		exit(0);
	if (sorted_or_not(push, listik_a))
		ft_error("already sorted");
	fill_b(listik_a, listik_b, push);
	fill_back_to_a(listik_a, listik_b, push);
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
//	fill_b(&a, &b, push);
	algo_rythm(push, &a, &b);
//	while (1)
	{
		//printf("%d\n", a->index);
		//a = a->next;
	}
//	printf("k == %d\n", push->k);
//	free(push->index);
//	freeing(a);
//	freeing(b);
//	while (1);
}
