/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:16:24 by zkarapet          #+#    #+#             */
/*   Updated: 2022/09/10 19:40:58 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_to_max(t_struct *push)
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
