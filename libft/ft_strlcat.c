/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:08:39 by dwisoky           #+#    #+#             */
/*   Updated: 2018/11/30 14:16:08 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *str1, const char *str2, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (str1[i] != '\0' && i < n)
		i++;
	while (str2[j] != '\0' && j + i + 1 < n)
	{
		str1[i + j] = str2[j];
		j++;
	}
	if (i < n)
		str1[i + j] = '\0';
	return (i + ft_strlen(str2));
}
