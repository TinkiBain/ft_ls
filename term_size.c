/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 18:40:45 by jterry            #+#    #+#             */
/*   Updated: 2019/03/01 15:28:21 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include "ft_ls.h"

int					term(void)
{
	struct winsize	size;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
	return (size.ws_col);
}

void				print_link(t_file *file)
{
	size_t			i;
	char			buf[NAME_MAX + 1];

	ft_putstr_bf(file->name, 0);
	if (S_ISLNK(file->st.st_mode))
	{
		ft_putstr_bf(" -> ", 0);
		i = readlink(file->path, buf, NAME_MAX);
		buf[i] = '\0';
		ft_putstr_bf(buf, 0);
	}
	ft_putstr_bf("\n", 0);
}

int					create_dir(t_file **dir, t_file **file)
{
	if ((*file)->name[0] == '.' && (!(*file)->name[1]
				|| ((*file)->name[1] == '.' && !(*file)->name[2])))
		return (-1);
	(*dir) = (t_file*)malloc(sizeof(t_file));
	(*dir)->path = (*file)->path;
	(*dir)->name = (*file)->name;
	(*dir)->size_name = (*file)->size_name;
	(*dir)->st = (*file)->st;
	(*dir)->next = NULL;
	return (1);
}
