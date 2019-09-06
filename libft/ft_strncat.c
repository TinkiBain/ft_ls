/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:34:19 by dwisoky           #+#    #+#             */
/*   Updated: 2018/11/30 15:11:19 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *str1, const char *str2, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (n == 0)
		return (str1);
	while (str1[i] != '\0')
		i++;
	while (str2[j] != '\0' && j <= n - 1)
	{
		str1[i + j] = str2[j];
		j++;
	}
	str1[j + i] = '\0';
	return (str1);
}
