/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 16:05:30 by dwisoky           #+#    #+#             */
/*   Updated: 2019/02/28 16:38:39 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		fill_flag(char c, int *flag)
{
	if (c == 'l')
	{
		*flag &= ~(1 << 3);
		*flag &= ~(1 << 9);
	}
	if (c == 'C')
	{
		*flag &= ~(1 << 3);
		*flag &= ~(1 << 1);
	}
	if (c == 'f')
		*flag |= 1;
	if (c == '1')
	{
		*flag &= ~(1 << 1);
		*flag &= ~(1 << 9);
	}
	if (c == 't')
		*flag &= ~(1 << 11);
	if (c == 'S')
		*flag &= ~(1 << 6);
}

void		flag_check(char *av, int *flag, char *flags)
{
	int		i;

	while (*av)
	{
		i = 0;
		while (i < 13)
		{
			if (*av == flags[i])
			{
				fill_flag(*av, flag);
				*flag |= 1 << i;
				break ;
			}
			++i;
		}
		if (i == 13)
			ls_error(*av, NULL);
		av++;
	}
}

int			parsing_flag(int ac, char **av, int *flag)
{
	*flag = 0;
	if (!(isatty(fileno(stdout))))
		*flag |= 1 << 3;
	while (av[ac] && av[ac][0] == '-' && av[ac][1])
	{
		if (av[ac][1] == '-' && !(av[ac][2]))
			return (++ac);
		flag_check(&av[ac][1], flag, "alR1drtuFCfSp");
		++ac;
	}
	return (ac);
}
