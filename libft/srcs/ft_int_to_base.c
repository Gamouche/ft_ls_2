/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_to_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 13:59:37 by cyfermie          #+#    #+#             */
/*   Updated: 2018/01/13 15:42:00 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char		*ft_int_to_base(long long n, char *base)
{
	char				*ret;
	int					size;
	unsigned long long	un;
	int					loop;

	un = (n < 0) ? (unsigned long long)-n : (unsigned long long)n;
	size = (n < 0) ? 2 : 1;
	loop = 0;
	while ((un /= ft_strlen(base)) && ++loop < 4242)
		size++;
	if (!(ret = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ret[0] = (n == 0) ? '0' : '-';
	ret[size] = '\0';
	un = (n < 0) ? (unsigned long long)-n : (unsigned long long)n;
	while (un && ++loop < 4242)
	{
		ret[--size] = base[un % ft_strlen(base)];
		un /= ft_strlen(base);
	}
	return (ret);
}
