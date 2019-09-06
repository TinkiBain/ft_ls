/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:31:35 by dwisoky           #+#    #+#             */
/*   Updated: 2018/11/30 14:05:22 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	s[11];
	char	*str1;
	int		i;
	int		j;

	i = 1;
	j = n < 0 ? -1 : 1;
	s[0] = n % 10 * j + '0';
	n = n / 10;
	while (n * j > 0)
	{
		s[i] = '0' + (j * n) % 10;
		n /= 10;
		i++;
	}
	if (j == -1)
		s[i++] = '-';
	if ((str1 = (char*)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	str1[i] = '\0';
	j = 0;
	while (i--)
		str1[j++] = s[i];
	return (str1);
}
