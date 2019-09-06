/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:45:52 by dwisoky           #+#    #+#             */
/*   Updated: 2018/11/27 16:59:50 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str1, int c, size_t n)
{
	unsigned long	i;
	const char		*s1;

	s1 = (const char*)str1;
	i = 0;
	while (i < n)
	{
		if (*(s1 + i) == (char)c)
			return ((void*)s1 + i);
		i++;
	}
	return (NULL);
}
