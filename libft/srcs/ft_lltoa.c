/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:02:17 by cyfermie          #+#    #+#             */
/*   Updated: 2018/01/13 14:02:18 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_lltoa(long long n)
{
	int					size_str;
	char				*str;
	unsigned long long	n2;

	n2 = (n < 0) ? (unsigned long long)-n : (unsigned long long)n;
	size_str = (n < 0) ? 2 : 1;
	while ((n2 /= 10))
		size_str++;
	if (!(str = (char*)malloc(sizeof(*str) * (size_str + 1))))
		return (0);
	str[size_str] = '\0';
	n2 = (n < 0) ? (unsigned long long)-n : (unsigned long long)n;
	while (--size_str >= 0)
	{
		str[size_str] = n2 % 10 + '0';
		n2 /= 10;
	}
	str[0] = (n < 0) ? '-' : str[0];
	return (str);
}
