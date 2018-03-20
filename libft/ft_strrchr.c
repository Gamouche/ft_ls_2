/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:49:54 by cyfermie          #+#    #+#             */
/*   Updated: 2017/11/07 15:50:00 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	*begin;

	begin = s;
	while (*s != '\0')
		++s;
	while (*s != c)
	{
		if (s == begin)
			return (NULL);
		--s;
	}
	return ((char *)s);
}
