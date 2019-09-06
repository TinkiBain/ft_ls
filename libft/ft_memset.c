/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:53:10 by dwisoky           #+#    #+#             */
/*   Updated: 2018/11/22 13:08:44 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *memptr, int val, size_t num)
{
	char			*str;
	unsigned long	i;
	long			j;

	i = 0;
	j = num;
	if (j < 0)
		return (NULL);
	str = (char*)memptr;
	while (i < num)
	{
		str[i] = val;
		i++;
	}
	return (str);
}
