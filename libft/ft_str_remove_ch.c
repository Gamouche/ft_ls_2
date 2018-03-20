/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_remove_ch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:44:35 by cyfermie          #+#    #+#             */
/*   Updated: 2017/11/11 18:44:36 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_str_remove_ch(char *str, int ch)
{
	size_t	len_alloc;
	char	*new_str;
	size_t	i;

	len_alloc = ft_strlen(str);
	i = 0;
	while (str[i] != '\0')
		if (str[i++] == ch)
			--len_alloc;
	if ((new_str = (char *)malloc(sizeof(char) * (len_alloc + 1))) == NULL)
		return (NULL);
	new_str[len_alloc] = '\0';
	i = 0;
	while (*str != '\0')
	{
		if (*str != ch)
		{
			new_str[i] = *str;
			++i;
		}
		++str;
	}
	return (new_str);
}
