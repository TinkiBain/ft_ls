/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lflag.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:33:15 by jterry            #+#    #+#             */
/*   Updated: 2019/03/01 15:58:11 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <pwd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/acl.h>

void				st_mode(mode_t mode, char *buf, char *name, int i)
{
	const char		*chart;

	chart = "rwxrwxrwx";
	if (S_ISDIR(mode))
		buf[0] = 'd';
	else if (S_ISLNK(mode))
		buf[0] = 'l';
	else if (S_ISCHR(mode))
		buf[0] = 'c';
	else if (S_ISBLK(mode))
		buf[0] = 'b';
	else if (S_ISFIFO(mode))
		buf[0] = 'p';
	else if (S_ISSOCK(mode))
		buf[0] = 's';
	else
		buf[0] = '-';
	while (chart[++i])
		if (mode & (1 << (8 - i)))
			buf[i + 1] = chart[i];
		else
			buf[i + 1] = '-';
	buf = ft_buf(buf, i, mode, name);
	buf[11] = '\0';
}

void				minor_major(t_file **file)
{
	char			*minr;
	char			*maj;

	if (S_ISBLK((*file)->st.st_mode) || S_ISCHR((*file)->st.st_mode))
	{
		minr = ft_itoa(major((*file)->st.st_rdev));
		(*file)->bit = ft_strrejoin(s_f(minr, 3, 0), ",");
		maj = ft_itoa(minor((*file)->st.st_rdev));
		(*file)->bit = ft_strrejoin((*file)->bit, s_f(maj, 4, 0));
	}
	else
		(*file)->bit = ft_itoa((*file)->st.st_size);
}

void				cs(size_t *sizof, t_file **file, int *tt)
{
	struct passwd	*t;
	struct group	*g;
	int				i;

	i = 0;
	while (i < 4)
		sizof[i++] = 0;
	while ((*file))
	{
		minor_major(file);
		*tt += (*file)->st.st_blocks;
		t = getpwuid((*file)->st.st_uid);
		g = getgrgid((*file)->st.st_gid);
		(*file)->link = ft_itoa((*file)->st.st_nlink);
		if (sizof[0] < ft_strlen((*file)->link))
			sizof[0] = ft_strlen((*file)->link);
		if (sizof[1] < ft_strlen((*file)->bit))
			sizof[1] = ft_strlen((*file)->bit);
		if (sizof[2] < ft_strlen(t->pw_name))
			sizof[2] = ft_strlen(t->pw_name);
		if (sizof[3] < ft_strlen(g->gr_name))
			sizof[3] = ft_strlen(g->gr_name);
		file = &(*file)->next;
	}
}

void				ft_times(char *tim, t_file *file, int flag)
{
	time_t			time_f;
	int				tm;
	int				i;

	i = -1;
	if (flag & 128)
		time_f = file->st.st_atime;
	else
		time_f = file->st.st_mtime;
	if ((time(NULL) - time_f) > (2628000 * 6))
	{
		i = 0;
		tm = 4;
		while (i < 7)
			(tim)[i++] = ctime(&time_f)[tm++];
		tm = 19;
		while (i < 12)
			(tim)[i++] = ctime(&time_f)[tm++];
	}
	else
		while (++i < 12)
			(tim)[i] = ctime(&time_f)[i + 4];
	(tim)[i] = '\0';
}

void				lflag(t_file *file, int tt, int flag)
{
	char			buf[12];
	struct passwd	*t;
	struct group	*g;
	char			tim[13];
	size_t			sizof[4];

	cs(sizof, &file, &tt);
	print_total(tt, flag);
	while (file)
	{
		if (file->st.st_mode == 0)
		{
			file = file->next;
			continue ;
		}
		ft_times(tim, file, flag);
		t = getpwuid(file->st.st_uid);
		g = getgrgid(file->st.st_gid);
		st_mode(file->st.st_mode, buf, file->path, -1);
		print_l(buf, " ", s_f(file->link, sizof[0], 1), 2);
		print_l(s_b(t->pw_name, sizof[2]), "  ", s_b(g->gr_name, sizof[3]), 3);
		print_l(s_f(file->bit, sizof[1], 1), " ", tim, 1);
		print_link(file);
		file = file->next;
	}
}
