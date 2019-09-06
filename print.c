/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:12:31 by dwisoky           #+#    #+#             */
/*   Updated: 2019/03/05 19:19:03 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				cr_file(char *name, char *path, t_file **file, int flag)
{
	(*file) = (t_file*)malloc(sizeof(t_file));
	(*file)->path = ft_strjoin(path, name);
	lstat((*file)->path, &(*file)->st);
	(*file)->name = ft_strldup(name, file, flag);
	(*file)->next = NULL;
}

int					fill_dr(char *path, t_file **file, t_file **dir, int flag)
{
	struct dirent	*entry;
	DIR				*dirent;
	int				i;

	i = 0;
	if (!(dirent = opendir(path)))
		return (ls_error('a', path));
	if (path[ft_strlen(path) - 1] != '/')
		path = ft_strjoin(path, "/");
	else
		path = ft_strdup(path);
	while ((entry = readdir(dirent)))
	{
		if (entry->d_name[0] == '.' && !(flag & 1))
			continue ;
		++i;
		cr_file(entry->d_name, path, file, flag);
		if (S_ISDIR((*file)->st.st_mode) && !(flag & 16))
			if (create_dir(dir, file) > 0)
				dir = &(*dir)->next;
		file = &(*file)->next;
	}
	closedir(dirent);
	free(path);
	return (i);
}

void				create_dir_rec(t_file **dir, int flag, int i)
{
	int				count;
	t_file			*dirent;
	t_file			*file;

	while ((*dir))
	{
		file = NULL;
		dirent = NULL;
		if ((i > 0) || (*dir)->next)
		{
			if (i > 0)
				ft_putstr_bf("\n", 0);
			ft_putstr_bf((*dir)->path, 0);
			ft_putstr_bf(":\n", 0);
		}
		count = fill_dr((*dir)->path, &file, &dirent, flag);
		print(&file, &dirent, flag, count);
		dir = &(*dir)->next;
		free_file(file, dirent);
		++i;
	}
}

void				free_file(t_file *file, t_file *dir)
{
	t_file			*tmp;

	while (file != NULL)
	{
		tmp = file;
		file = file->next;
		free(tmp->name);
		free(tmp->path);
		free(tmp);
	}
	while (dir != NULL)
	{
		tmp = dir;
		dir = dir->next;
		free(tmp);
	}
}

void				print(t_file **file, t_file **dir, int flag, int words)
{
	int				i;

	if (!(flag & 1024))
	{
		sort_merge(file, flag);
		sort_merge(dir, flag);
	}
	if (flag & 2 && words)
	{
		lflag(*file, 0, flag);
		i = 1;
	}
	else if (flag & 8 && !(flag & 512))
		i = print_one_file(*file);
	else
		i = output(file, words);
	if (flag & 4)
		create_dir_rec(dir, flag, i);
	else
		create_dir_rec(dir, flag | 16, i);
}
