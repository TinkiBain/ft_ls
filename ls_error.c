/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 19:44:43 by dwisoky           #+#    #+#             */
/*   Updated: 2019/02/28 20:03:19 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ls_error(char c, char *str)
{
	if (str == NULL)
	{
		write(2, "ft_ls: illegal option -- ", 25);
		write(2, &c, 1);
		write(2, "\n", 1);
		ft_putstr_fd("usage: ft_ls [CFRSadrtufpl1] [file ...]\n", 2);
		exit(1);
	}
	else if (errno != 0)
	{
		ft_putstr_bf(NULL, 1);
		write(2, "ft_ls: ", 7);
		write(2, str, ft_strlen(str));
		write(2, ": ", 2);
		perror(NULL);
	}
	return (0);
}
