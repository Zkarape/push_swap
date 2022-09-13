/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:58:33 by zkarapet          #+#    #+#             */
/*   Updated: 2022/09/13 19:12:48 by zkarapet         ###   ########.fr       */
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
	int		counter;

	counter = 0;
	push->list_a = listik_a;
	push->list_b = listik_b;
	while (counter < push->len)
	{
		if ((*(push->list_a))->index <= counter)
		{
			if (!pab(push->list_b, push->list_a, 0, push))
				ft_error("error appeared1!");
			if (!rab(push->list_b, 0, push))
				ft_error("error appeared2!");
			printf("2nd\n");
			counter++;
		}
		else if ((*(push->list_a))->index <= counter + sqrt(push->len))
		{
			if (!pab(push->list_b, push->list_a, 0, push))
				ft_error("error appeared3!");
			counter++;
		}
		else
			if (!rab(push->list_a, 1, push))
				ft_error("error appeared4!");
	}
}

void	fill_back_to_a(t_list **listik_a, t_list **listik_b, t_struct *push)
{
	push->i = -1;
	push->list_a = listik_a;
	push->list_b = listik_b;
	push->size_b = ft_lst_size(listik_b);
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
				if (!rab(push->list_b, 0, push))
					ft_error("error appeared2!");
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
	if (sorted_or_not(push, listik_a) == 2)
		exit(0);
	if (sorted_or_not(push, listik_a))
		ft_error("already sorted");
//	while (!sorted_or_not(push, listik_a))
//	{
		fill_b(listik_a, listik_b, push);
		fill_back_to_a(listik_a, listik_b, push);
//	}
}

int	main(int argc, char **argv)
{
	int			i;
	t_struct	*push;
	t_list		*a;
	t_list		*b;

//	a = malloc(sizeof(t_list));
//	if (!a)
//		return 
//	b = malloc(sizeof(t_list));
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
	//	printf("%d\n", a->index);
		a = a->next;
	}
//	printf("k == %d\n", push->k);
//	free(push->index);
//	freeing(a);
//	freeing(b);
//	while (1);
}
