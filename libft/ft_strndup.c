/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:21:27 by cyfermie          #+#    #+#             */
/*   Updated: 2018/01/15 15:45:41 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strndup(const char *s1, size_t n)
{
	char	*ret;
	size_t	i;

	if (!(ret = (char*)malloc(sizeof(*ret) * (n + 1))))
		return (NULL);
	i = 0;
	while (i < n)
	{
		ret[i] = s1[i];
		++i;
	}
	ret[i] = '\0';
	return (ret);
}
