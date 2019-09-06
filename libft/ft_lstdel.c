/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:04:40 by dwisoky           #+#    #+#             */
/*   Updated: 2018/12/01 15:20:40 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;
	t_list *srp;

	if (alst == NULL || del == NULL)
		return ;
	srp = *alst;
	while (srp != NULL)
	{
		tmp = srp->next;
		ft_lstdelone(&srp, del);
		srp = tmp;
	}
	*alst = NULL;
}
