/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:59:18 by zkarapet          #+#    #+#             */
/*   Updated: 2022/09/23 16:34:34 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_main(t_struct *push, t_list **a, t_list **b)
{
	int	i;

	i = -1;
	free(push->index);
	free(push->str);
	while (push->arr[++i])
		free(push->arr[i]);
	free(push->arr);
	free(push);
	freeing(*a);
	freeing(*b);
}

int	is_sorted(t_list *a)
{
	int		i;
	t_list	*temp;

	temp = a;
	while (temp->next)
	{
		if (temp->index > temp->next->index)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int			i;
	t_struct	*push;
	t_list		*a;
	t_list		*b;

	if (argc == 1)
		exit(1);
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
	if (!is_sorted(a))
		algo_rythm(push, &a, &b);
	free_main(push, &a, &b);
}
