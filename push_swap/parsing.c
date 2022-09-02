/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:17:34 by zkarapet          #+#    #+#             */
/*   Updated: 2022/09/02 21:50:52 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nothing_but_int(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (2);
	while (str[++i] && ((str[i] >= '0' && str[i] <= '9') || str[i] == '+'
			|| str[i] == ' ' || str[i] == '\t' || str[i] == '-'));
	if (!str[i])//&& ft_atoi(str))
		return (1);
	else
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
	int	i;
	int	k;

	k = -1;
	push->str = "";
	i = 1;
	while (i < push->argc)
	{	
		push->str = ft_strjoin(push->str, push->av[i]);
		push->str = ft_strjoin(push->str, " ");
		i++;
	}
	push->arr = ft_split(push->str, ' ');
	if (!push->arr)
		return;
	i = -1;
	while (push->arr[++i])
		if (!nothing_but_int(push->arr[i]) )//|| !ft_atoi(push->arr[i]))
			ft_error("not int");
	while (++k < i)
		push->index[k] = ft_atoi(push->arr[k]);
	push->len = i;
	if (!check_doubles(push))
		ft_error("doubles found");
}

//int main(int ac, char **av)
//{
//	t_struct *push;
//	push = malloc(sizeof(t_struct));
//
//	int	i = -1;
//	push->argc = ac;
//	push->av = av;
//	parsing(push);
//	while (++i < push->len)
//	{
//		printf("k ==== %d\n", push->index[i]);
//		printf("arr ==== %s\n", push->arr[i]);
//	}
//}
