/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:43:15 by dwisoky           #+#    #+#             */
/*   Updated: 2019/03/01 15:35:15 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			check_sort(t_file *file1, t_file *file2, int flag)
{
	int				i;

	i = 1;
	if (flag & 32)
		i = -1;
	if (flag & 64)
	{
		if (flag & 128)
		{
			if (file2->st.st_atime == file1->st.st_atime)
				return (i * ft_strcmp(file1->name, file2->name));
			else
				return (i * (file2->st.st_atime - file1->st.st_atime));
		}
		else
		{
			if (file2->st.st_mtime == file1->st.st_mtime)
				return (i * ft_strcmp(file1->name, file2->name));
			else
				return (i * (file2->st.st_mtime - file1->st.st_mtime));
		}
	}
	if (flag & 2048 && file2->st.st_size != file1->st.st_size)
		return (i * (file2->st.st_size - file1->st.st_size));
	return (i * (ft_strcmp(file1->name, file2->name)));
}

static int			lenght(t_file *file)
{
	t_file			*source;
	int				i;

	i = 0;
	source = file;
	while (source)
	{
		++i;
		source = source->next;
	}
	return (i);
}

static void			front_b_s(t_file *source, t_file **front, t_file **back)
{
	t_file			*current;
	int				hop;
	int				len;
	int				i;

	i = -1;
	current = source;
	len = lenght(source);
	if (len < 2)
	{
		*front = source;
		*back = NULL;
	}
	else
	{
		hop = (len - 1) / 2;
		while (++i < hop)
			current = current->next;
		*front = source;
		*back = current->next;
		current->next = NULL;
	}
}

static t_file		*sorted_merge(t_file *a, t_file *b, int flag)
{
	t_file			*result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (check_sort(a, b, flag) < 0)
	{
		result = a;
		result->next = sorted_merge(a->next, b, flag);
	}
	else
	{
		result = b;
		result->next = sorted_merge(a, b->next, flag);
	}
	return (result);
}

void				sort_merge(t_file **file, int flag)
{
	t_file			*head;
	t_file			*a;
	t_file			*b;

	head = *file;
	if ((head == NULL) || (head->next == NULL))
		return ;
	front_b_s(head, &a, &b);
	sort_merge(&a, flag);
	sort_merge(&b, flag);
	(*file) = sorted_merge(a, b, flag);
}
