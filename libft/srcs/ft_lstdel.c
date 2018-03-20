/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:40:19 by cyfermie          #+#    #+#             */
/*   Updated: 2017/11/08 16:40:20 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next_elem;

	while (*alst != NULL)
	{
		next_elem = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = next_elem;
	}
}
