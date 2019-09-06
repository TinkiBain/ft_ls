/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:29:45 by dwisoky           #+#    #+#             */
/*   Updated: 2018/11/30 18:07:10 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	size_t	i;

	if (str1 == NULL && str2 == NULL)
		return (NULL);
	if (str1 == str2)
		return (str1);
	if (n == 0)
		return (str1);
	i = 0;
	if (str1 > str2)
	{
		i = n;
		while (i > 0)
		{
			i--;
			((char *)str1)[i] = ((char *)str2)[i];
		}
	}
	else
		while (i < n)
		{
			((char *)str1)[i] = ((char *)str2)[i];
			i++;
		}
	return (str1);
}
