/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 15:13:37 by dwisoky           #+#    #+#             */
/*   Updated: 2018/11/28 14:14:44 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	char			*str3;
	unsigned long	i;
	unsigned long	j;

	i = 0;
	if (*str2 == '\0')
		return ((char *)str1);
	while (str1[i] != '\0' && str1[i] >= 0 && str1[i] <= 127)
	{
		j = 0;
		while (str1[i + j] == str2[j] && i + j < n)
		{
			if (str2[j + 1] == '\0' || j == n)
			{
				str3 = (char*)str1;
				return (&str3[i]);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
