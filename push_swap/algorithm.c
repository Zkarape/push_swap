/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:58:33 by zkarapet          #+#    #+#             */
/*   Updated: 2022/09/09 22:12:07 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted_or_not(t_struct *push, t_list *listik)
{
	int		i;
	t_list	*head;

	i = 0;
	head = listik;
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

void	fill_b(t_list *listik_a, t_list *listik_b)
{
	int 	counter;
	int		i = -1;
	t_list	*list_a;
	t_list	*list_b;

	counter = 0;
	list_a = listik_a;
	list_b = listik_b;
	while (++i < 5)
	{
		if (list_a->index <= counter)
		{
			if (!pab(&list_b, &list_a, 0))
				ft_error("error appeared1!");
			if(!rab(&list_b, 0))
				ft_error("error appeared2!");
			counter++;
		}
		else if (list_a->index <= counter + 2)
		{
			if (!pab(&list_b, &list_a, 0))
				ft_error("error appeared3!");
			counter++;
		}
		else
		{
			if(!rab(&list_a, 1))
				ft_error("error appeared4!");
		}
	}
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
	fill_b(listik_a, listik_b);
//	while (listik_b)
//	{
//		printf("index_b == %d x == %d\n", listik_b->index, listik_b->x);
//		listik_b = listik_b->next;
//	}
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
//	b->index = 9;
//	b->x = 10;
	add_to_list(a, push);
//	indexing(a, push);
//	algo_rythm(push, a, b);
//	while (head)
//	{
//		printf("head == %d x == %d\n", head->index, head->x);
//		head = head->next;
//	}
//	rab(&a, 1);
//	pab(&b, &a, 0);
//	rab(&b, 0);	
//	pab(&b, &a, 0);
//	pab(&b, &a, 0);
//	rab(&b, 0);
//	pab(&b, &a, 0);
//	rab(&b, 0);
	i = 5;
//	while (i--)
//	{
//		printf("index_a == %d x == %d\n", a->index, a->x);
//	}
//	while (a)
//	{
//		printf("index_a == %d x == %d\n", a->index, a->x);
//		printf("in_b == %d x == %d\n", b->index, b->index);
//		a = a->next;
//		b = b->next;
//	}
}
