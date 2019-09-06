/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 18:08:33 by dwisoky           #+#    #+#             */
/*   Updated: 2018/11/30 17:20:29 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	size_t	i;
	char	*s;
	char	*s1;

	if (str1 == NULL && str2 == NULL)
		return (NULL);
	if (str1 == str2)
		return (str1);
	s = (char*)str1;
	s1 = (char*)str2;
	i = 0;
	while (i < n)
	{
		s[i] = s1[i];
		i++;
	}
	return (s);
}
