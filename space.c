/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:53:51 by jterry            #+#    #+#             */
/*   Updated: 2019/03/01 16:01:54 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char				*ft_buf(char *buf, int i, mode_t mode, char *name)
{
	acl_t			tmp;

	buf[i + 1] = ' ';
	if (listxattr(name, NULL, 1, XATTR_NOFOLLOW) > 0)
		buf[i + 1] = '@';
	if ((tmp = acl_get_link_np(name, ACL_TYPE_EXTENDED)))
	{
		acl_free(tmp);
		buf[i + 1] = '+';
	}
	if (mode & 512)
		buf[9] = (buf[9] == 'x' ? 't' : 'T');
	if (mode & 1024)
		buf[6] = (buf[6] == 'x' ? 's' : 'S');
	if (mode & 2048)
		buf[3] = (buf[3] == 'x' ? 's' : 'S');
	return (buf);
}

char				*s_f(char *str, size_t sz, int f)
{
	size_t			i;
	size_t			j;
	char			*tmp;

	j = 0;
	tmp = malloc(sz + 1);
	i = ft_strlen(str);
	while (sz-- != i)
	{
		tmp[j] = ' ';
		j++;
	}
	i = 0;
	while (str[i])
		tmp[j++] = str[i++];
	tmp[j] = '\0';
	if (f == 1)
		free(str);
	return (tmp);
}

char				*s_b(char *str, size_t sz)
{
	size_t			i;
	char			*tmp;

	if (str)
	{
		tmp = malloc(sz + 1);
		i = ft_strlen(str);
		tmp = ft_strcpy(tmp, str);
		while (sz != i)
			tmp[i++] = ' ';
		tmp[i] = '\0';
		return (tmp);
	}
	return (NULL);
}

void				print_l(char *str, char *str1, char *str2, int i)
{
	ft_putstr_bf(str, 0);
	ft_putstr_bf(str1, 0);
	if (str2)
	{
		ft_putstr_bf(str2, 0);
		ft_putstr_bf(str1, 0);
	}
	if (i & 1)
		free(str);
	if (i & 2)
		free(str2);
}

void				print_total(int tt, int flag)
{
	char			*str;

	str = ft_itoa(tt);
	if (flag)
	{
		ft_putstr_bf("total ", 0);
		ft_putstr_bf(str, 0);
		ft_putstr_bf("\n", 0);
		free(str);
	}
}
