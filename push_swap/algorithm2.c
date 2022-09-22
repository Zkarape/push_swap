/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:58:33 by zkarapet          #+#    #+#             */
/*   Updated: 2022/09/22 22:43:04 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	counter = 0;
	if (push->len > 100)
		push->k = 30;
	else
		push->k = 15;
	while (counter < push->len)
	{
		if ((*listik_a)->index <= counter)
		{
			pab(listik_b, listik_a, 0, push);
			rab(listik_b, 0, push);
			counter++;
		}
		else if ((*(listik_a))->index <= counter + push->k)
		{
			pab(listik_b, listik_a, 0, push);
			counter++;
		}
		else
			rab(listik_a, 1, push);
	}
}

void	fill_back_to_a(t_list **listik_a, t_list **listik_b, t_struct *push)
{
	push->i = -1;
	push->list_a = listik_a;
	push->list_b = listik_b;
	while (push->list_b && (*push->list_b))
	{
		push->i = -1;
		push->size_b = ft_lst_size(*listik_b);
		push->indx = find_pos(*push->list_b, push->size_b - 1);
		if (push->indx <= push->size_b / 2)
		{
			while (++push->i < push->indx)
				rab(push->list_b, 0, push);
		}
		else if (push->indx > push->size_b / 2)
		{
			while (++push->i < push->size_b - push->indx)
				rrab(push->list_b, 0, push);
		}
		if (!push->indx)
			pab(push->list_a, push->list_b, 1, push);
	}
}

void	algo_rythm(t_struct *push, t_list **listik_a, t_list **listik_b)
{
	if (sorted_or_not(push, listik_a) == 2)
		return ;
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
	free(push->index);
	free(push->str);
	while (push->arr[++i])
		free(push->arr[i]);
	free(push->arr);
	free(push);
	freeing(a);
	freeing(b);
}
