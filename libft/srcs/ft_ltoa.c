/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:03:20 by cyfermie          #+#    #+#             */
/*   Updated: 2018/01/13 14:03:21 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_ltoa(long n)
{
	int				size_str;
	char			*str;
	unsigned long	n2;

	n2 = (n < 0) ? (unsigned long)-n : (unsigned long)n;
	size_str = (n < 0) ? 2 : 1;
	while ((n2 /= 10))
		size_str++;
	if (!(str = (char*)malloc(sizeof(*str) * (size_str + 1))))
		return (0);
	str[size_str] = '\0';
	n2 = (n < 0) ? (unsigned long)-n : (unsigned long)n;
	while (--size_str >= 0)
	{
		str[size_str] = n2 % 10 + '0';
		n2 /= 10;
	}
	str[0] = (n < 0) ? '-' : str[0];
	return (str);
}
