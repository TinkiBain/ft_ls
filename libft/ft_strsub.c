/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:12:23 by dwisoky           #+#    #+#             */
/*   Updated: 2018/11/30 13:49:30 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	if (s == NULL)
		return (NULL);
	i = start;
	j = 0;
	if ((str = (char*)malloc(len + 1)) == NULL)
		return (NULL);
	while (i < start + len)
	{
		str[i - start] = s[start + j];
		i++;
		j++;
	}
	str[i - start] = '\0';
	return (str);
}
