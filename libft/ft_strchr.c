/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:47:28 by dwisoky           #+#    #+#             */
/*   Updated: 2018/11/28 13:58:38 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	char *str1;

	str1 = (char*)str;
	while (*str1 != '\0' && *str1 >= 0 && *str1 <= 127)
	{
		if (*str1 == ch)
			return (str1);
		str1++;
	}
	if (*str1 == ch)
		return (str1);
	return (NULL);
}
