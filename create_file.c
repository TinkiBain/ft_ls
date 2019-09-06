/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 20:59:37 by dwisoky           #+#    #+#             */
/*   Updated: 2019/03/01 16:22:38 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			*flag_f(t_file **file, int flag)
{
	if (S_ISDIR((*file)->st.st_mode))
		return ("/");
	else if (S_ISFIFO((*file)->st.st_mode) && flag & 256)
		return ("|");
	else if (S_ISLNK((*file)->st.st_mode) && flag & 256)
		return ("@");
	else if (S_ISSOCK((*file)->st.st_mode) && flag & 256)
		return ("=");
	else if (((*file)->st.st_mode & 1) && ((*file)->st.st_mode & 8)
			&& ((*file)->st.st_mode & 64) && flag & 256)
		return ("*");
	return ("\0");
}

char			*ft_lstrcat(char *str1, char *str2, int *len)
{
	int			i;

	i = 0;
	while (str1[i] != '\0')
		i++;
	while (*str2 != '\0')
	{
		str1[i] = *str2;
		i++;
		str2++;
	}
	str1[i] = '\0';
	*len = i;
	return (str1);
}

char			*ft_strldup(char *str, t_file **file, int flag)
{
	int			i;
	int			len;
	char		*src;

	i = 0;
	len = 0;
	if ((flag & 4096 || flag & 256) && (!S_ISDIR((*file)->st.st_mode)
				|| (flag & 16)))
		str = ft_lstrcat(str, flag_f(file, flag), &len);
	else
		while (str[len] != '\0')
			len++;
	if ((src = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while (i <= len)
	{
		src[i] = str[i];
		i++;
	}
	(*file)->size_name = len;
	return (src);
}

int				new_f(t_file **file, t_file **dir, int flag, char *name)
{
	t_file		*tmp;

	tmp = (t_file*)malloc(sizeof(t_file));
	tmp->path = ft_strdup(name);
	if (flag & 2)
		lstat(name, &tmp->st);
	else
		stat(name, &tmp->st);
	tmp->name = ft_strldup(name, &tmp, flag);
	tmp->next = NULL;
	if ((S_ISDIR(tmp->st.st_mode) && !(flag & 16)))
	{
		(*dir) = tmp;
		return (0);
	}
	(*file) = tmp;
	return (1);
}

int				create_file(char **av, int flag, t_file **file, t_file **dir)
{
	int			i;
	struct stat	st;

	i = 0;
	if (!(*av))
		return (new_f(file, dir, flag, "."));
	--av;
	while (*(++av))
	{
		if (stat(*av, &st) < 0)
		{
			ls_error('a', *av);
			continue ;
		}
		if (new_f(file, dir, flag, *av) == 0)
		{
			dir = &(*dir)->next;
			continue ;
		}
		++i;
		file = &(*file)->next;
	}
	return (i);
}
