/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:16:57 by dwisoky           #+#    #+#             */
/*   Updated: 2018/11/30 13:50:15 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*ft_nxtwrd(const char *s, int c)
{
	while (*s == c)
		s++;
	return (s);
}

static int			ft_wrdlen(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int			ft_countwrd(const char *s, int c)
{
	int i;

	i = 0;
	while (*s != '\0')
	{
		s = ft_nxtwrd(s, c);
		if (*s == '\0')
			break ;
		i++;
		s = s + ft_wrdlen(s, c);
	}
	return (i);
}

static void			ft_clean(char **str, int i)
{
	while (i > 0)
	{
		i--;
		ft_strdel(&str[i]);
	}
	ft_strdel(&str[i]);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		n;
	int		i;

	if (s == NULL)
		return (NULL);
	n = ft_countwrd(s, c);
	if ((str = (char**)ft_memalloc((n + 1) * sizeof(char*))) == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		s = ft_nxtwrd(s, c);
		str[i] = ft_strsub(s, 0, ft_wrdlen(s, c));
		if (str[i] == NULL)
		{
			ft_clean(str, i);
			return (NULL);
		}
		i++;
		s = s + ft_wrdlen(s, c);
	}
	str[n] = NULL;
	return (str);
}
