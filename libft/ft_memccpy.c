/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 18:12:12 by dwisoky           #+#    #+#             */
/*   Updated: 2018/11/30 15:05:11 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *str1, const void *str2, int c, size_t n)
{
	size_t	i;
	char	*s1;
	char	*s2;

	i = 0;
	s1 = (char*)str1;
	s2 = (char*)str2;
	while (i < n)
	{
		s1[i] = s2[i];
		if ((unsigned char)s2[i] == (unsigned char)c)
			return (&s1[++i]);
		i++;
	}
	return (NULL);
}
