/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standart_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:07:53 by jterry            #+#    #+#             */
/*   Updated: 2019/02/28 16:44:22 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			col_param(int *param, int words)
{
	param[1] = 8 - (param[0] % 8);
	param[2] = term() / (param[0] + param[1]);
	if (param[2] == 0)
		param[2] = 1;
	if ((words % param[2]) != 0 && param[2] != 0)
		param[3] = (words / param[2]) + 1;
	else if (param[2] != 0)
		param[3] = (words / param[2]);
	else
		param[3] = words;
}

static int			check_line(int *param, int words, char **f)
{
	int				i;

	i = 0;
	if ((param[0] + param[1]) > term())
	{
		while (i < words)
		{
			ft_putstr_bf(f[i++], 0);
			ft_putstr_bf("\n", 0);
		}
		return (0);
	}
	return (1);
}

static void			term_out(char **f, int words, int *sz, int *param)
{
	int				t;
	int				i;
	int				y;

	if (check_line(param, words, f) == 0)
		return ;
	t = -1;
	while (++t < param[3])
	{
		y = 0;
		i = t;
		while (i < words)
		{
			ft_putstr_bf(f[i], 0);
			y++;
			while (sz[i] < (param[0] + param[1]) && y < param[2])
			{
				sz[i] += 8;
				ft_putstr_bf("\t", 0);
			}
			i += param[3];
		}
		ft_putstr_bf("\n", 0);
	}
}

int					output(t_file **file, int words)
{
	char			*f[words];
	int				i;
	int				sz[words];
	t_file			*elem;
	int				param[4];

	if (words == 0)
		return (0);
	elem = *file;
	i = 0;
	param[0] = (*file)->size_name;
	while (elem)
	{
		f[i] = elem->name;
		sz[i] = elem->size_name;
		if (param[0] < elem->size_name)
			param[0] = elem->size_name;
		elem = elem->next;
		i++;
	}
	col_param(param, words);
	term_out(f, words, sz, param);
	return (1);
}
