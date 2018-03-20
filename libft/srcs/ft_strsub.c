/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:01:49 by cyfermie          #+#    #+#             */
/*   Updated: 2017/11/09 16:24:58 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*strsub;
	size_t	index;

	if (s == NULL)
		return (NULL);
	strsub = (char *)malloc(sizeof(char) * (len + 1));
	if (strsub == NULL)
		return (NULL);
	index = 0;
	while (index < len)
	{
		strsub[index] = s[start + index];
		++index;
	}
	strsub[index] = '\0';
	return (strsub);
}
