/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:16:24 by zkarapet          #+#    #+#             */
/*   Updated: 2022/09/07 18:30:11 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_struct *push)
{
	int	i;
	int	tmp;

	i = 1;
	while (i < push->len)
	{
		if (push->index[i] < push->index[i - 1])
		{
			tmp = push->index[i];
			push->index[i] = push->index[i - 1];
			push->index[i - 1] = tmp;
			i = 0;
		}
		i++;
	}
}

//int	main(int ac, char **av)
//{
//	t_struct *push;
//	int	i = 0;
//	push = malloc(sizeof(t_struct));
//	push->argc = ac;
//	push->av = av;
//	parsing(push);
//	sort(push);
//	while (i < push->len)
//	{
//		printf("ind == %d\n", push->index[i]);
//		i++;
//	}
//}
