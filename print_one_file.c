/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_one_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 20:27:49 by dwisoky           #+#    #+#             */
/*   Updated: 2019/02/27 14:05:12 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				print_one_file(t_file *file)
{
	int			i;

	i = 0;
	while (file)
	{
		++i;
		ft_putstr_bf(file->name, 0);
		ft_putstr_bf("\n", 0);
		file = file->next;
	}
	return (i);
}
