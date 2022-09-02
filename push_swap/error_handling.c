/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:48:27 by zkarapet          #+#    #+#             */
/*   Updated: 2022/08/27 17:50:26 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *s)
{
	int	i;

	i = -1;
	while(s[++i]);
	return (i);
}

void	ft_error(char *s)
{
	write(1, s, ft_strlen(s));
	exit(1);
}
