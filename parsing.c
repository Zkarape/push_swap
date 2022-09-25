/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:17:34 by zkarapet          #+#    #+#             */
/*   Updated: 2022/09/25 15:47:31 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nothing_but_int(char *str)
{
	int	i;

	i = -1;
	if (!str || !*str)
		return (0);
	while (str[++i] && (str[i] >= '0' && str[i] <= '9'))
		;
	if (str[0] == '-' || str[0] == '+')
		while (str[++i] && (str[i] >= '0' && str[i] <= '9'))
			;
	if (!str[i])
		return (1);
	return (0);
}

int	check_doubles(t_struct *push)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < push->len)
	{
		j = i;
		while (++j < push->len)
			if (push->index[i] == push->index[j])
				return (0);
	}
	return (1);
}

void	parsing(t_struct *push)
{
	int		i;
	int		k;

	k = -1;
	push->str = NULL;
	i = 1;
	while (i < push->argc)
	{
		push->str = ft_strjoin(push->str, push->av[i]);
		push->str = ft_strjoin(push->str, " ");
		i++;
	}
	push->arr = ft_split(push->str, ' ');
	i = -1;
	while (push->arr[++i])
		if (!nothing_but_int(push->arr[i]))
			ft_error("NOT ACCEPTED!!");
	push->index = malloc(sizeof(int) * i);
	while (++k < i)
		push->index[k] = ft_atoi(push->arr[k]);
	push->len = i;
	if (!check_doubles(push))
		ft_error("doubles found");
}
