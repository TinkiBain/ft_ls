/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_nb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:14:10 by dwisoky           #+#    #+#             */
/*   Updated: 2019/02/18 08:39:00 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putendl_nb(char *s, int num)
{
	static char str[1000];
	static int	i;

	if (i == 999 || num == 0)
	{
		write(1, str, i);
		i = 0;
		return ;
	}
	while (*s != '\0' && s != NULL)
	{
		if (i == 999)
		{
			write(1, str, i);
			i = 0;
		}
		str[i] = *s;
		++i;
		s++;
	}
}
