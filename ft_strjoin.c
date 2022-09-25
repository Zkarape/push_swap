/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:20:02 by zkarapet          #+#    #+#             */
/*   Updated: 2022/09/12 18:40:33 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	j = 0;
	dst = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	while (s1 && i < ft_strlen(s1))
	{
		dst[i] = ((char *)s1)[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		dst[i] = ((char *)s2)[j];
		i++;
		j++;
	}
	free(s1);
	dst[i] = '\0';
	return (dst);
}
