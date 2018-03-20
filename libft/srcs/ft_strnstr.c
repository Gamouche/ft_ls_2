/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:50:50 by cyfermie          #+#    #+#             */
/*   Updated: 2017/11/09 16:16:15 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (*s2 == '\0')
		return ((char *)s1);
	while (*s1 != 0 && n > 0)
	{
		i = 0;
		while (s1[i] == s2[i] && n - i > 0)
		{
			++i;
			if (s2[i] == '\0')
				return ((char *)s1);
		}
		++s1;
		--n;
	}
	return (NULL);
}
