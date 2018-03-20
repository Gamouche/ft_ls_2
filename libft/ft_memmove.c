/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:42:56 by cyfermie          #+#    #+#             */
/*   Updated: 2017/11/07 15:43:00 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (((unsigned long)src) < ((unsigned long)dest))
	{
		while (n > 0)
		{
			*((char *)(dest + n - 1)) = *((const char *)(src + n - 1));
			--n;
		}
	}
	else if (((unsigned long)src) > ((unsigned long)dest))
	{
		i = 0;
		while (i < n)
		{
			*((char *)(dest + i)) = *((const char *)(src + i));
			++i;
		}
	}
	return (dest);
}
