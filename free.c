/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:10:04 by zkarapet          #+#    #+#             */
/*   Updated: 2022/09/12 18:55:57 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freeing(t_list *listik)
{
	t_list	*head;
	t_list	*temp;

	head = listik;
	while (listik)
	{
		temp = listik;
		listik = listik->next;
		free(temp);
	}
}
