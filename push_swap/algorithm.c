/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:58:33 by zkarapet          #+#    #+#             */
/*   Updated: 2022/09/10 21:50:49 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted_or_not(t_struct *push, t_list **listik)
{
	int		i;
	t_list	*head;

	i = 0;
	head = *listik;
	while (i <= push->len && head && head->next)
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

void	fill_b(t_list **listik_a, t_list **listik_b, t_struct *push)
{
	int 	counter;
	t_list	**list_a;
	t_list	**list_b;

	counter = 0;
	list_a = listik_a;
	list_b = listik_b;
	while (counter < push->len)
	{
		if ((*list_a)->index <= counter)
		{
			if (!pab(list_b, list_a, 0))
				ft_error("error appeared1!");
			if(!rab(list_b, 0))
				ft_error("error appeared2!");
			counter++;
		}
		else if ((*list_a)->index <= counter + 2)
		{
			if (!pab(list_b, list_a, 0))
				ft_error("error appeared3!");
			counter++;
		}
		else
		{
			if(!rab(list_a, 1))
				ft_error("error appeared4!");
		}
	}
}

void	fill_back_to_a(t_list **listik_a, t_list **listik_b, t_struct *push)
{
	int		size_of_b;
	int		max_index;
	int		index;
	int 	i;
	t_list	**list_a;
	t_list	**list_b;

	list_a = listik_a;
	list_b = listik_b;
	size_of_b = ft_lstsize(listik_b);
	while (1)
	{
		i = -1;
		max_index = find_max(*listik_b);
		index = find_pos(*listik_b, max_index);
		if (max_index == (*listik_b)->index)
		{
			if (!pab(list_a, list_b, 1))
				ft_error("error appeared1!");
		}
		if (index <= size_of_b / 2)
		{
			while (++i < index)
			{
				if(!rab(list_b, 0))
					ft_error("error appeared2!");
			}
		}
		i = -1;
		else
		{
			while (++i < size_of_b - index)
			{
				if (!rrab(list_b, 0))
					ft_error("error appeared2!");
			}
		}
}

void	algo_rythm(t_struct *push, t_list **listik_a, t_list **listik_b)
{
	int		i;
	int		counter;
	t_list	**head;

	i = -1;
	counter = 0;
	head = listik_a;
	if (sorted_or_not(push, listik_a))
		ft_error("already sorted");
	fill_b(listik_a, listik_b, push);
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
	a = NULL;
	b = NULL;
	add_to_list(&a, push);
	indexing(a, push);
	algo_rythm(push, &a, &b);
	while (a)
	{
		printf("index_a == %d x == %d\n", a->index, a->x);
		a = a->next;
	}
	while (b)
	{
		printf("index_b == %d x == %d\n", b->index, b->x);
		b = b->next;
	}
}
