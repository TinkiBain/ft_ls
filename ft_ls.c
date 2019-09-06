/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 16:03:36 by dwisoky           #+#    #+#             */
/*   Updated: 2019/02/28 16:40:30 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			main(int ac, char **av)
{
	int		words;
	t_file	*dir;
	t_file	*file;
	int		flag;

	file = NULL;
	dir = NULL;
	ac = parsing_flag(1, av, &flag);
	if (!(isatty(fileno(stdout))))
		flag |= 1 << 3;
	words = create_file(&av[ac], flag, &file, &dir);
	print(&file, &dir, flag, words);
	free_file(file, NULL);
	free_file(dir, NULL);
	ft_putstr_bf(NULL, 1);
}
