/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfreejoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:48:01 by cyfermie          #+#    #+#             */
/*   Updated: 2018/01/13 15:48:27 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_2.h>

char		*ft_strfreejoin(char *s1, const char *s2, int size_s2, t_arg *arg)
{
	char	*retour;
	int		i;
	int		lens1;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	lens1 = arg->cmpt;
	if (!(retour = (char *)malloc(sizeof(*retour) * (lens1 + size_s2 + 1))))
		return (NULL);
	i = -1;
	while (++i < lens1)
		retour[i] = s1[i];
	i--;
	while (++i < lens1 + size_s2 && i < 4242)
		retour[i] = s2[i - lens1];
	retour[i] = '\0';
	free(s1);
	return (retour);
}
