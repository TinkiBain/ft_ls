/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:23:02 by dwisoky           #+#    #+#             */
/*   Updated: 2018/11/30 14:06:14 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*str;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while ((*s == ' ' || *s == '\n' || *s == '\t') && *s != '\0')
		s++;
	while (s[i] != '\0')
		i++;
	if (i > 1)
		i--;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i--;
	if ((str = (char*)malloc(i + 2)) == NULL)
		return (NULL);
	while (j <= i)
	{
		str[j] = s[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}
