/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_to_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 13:56:39 by cyfermie          #+#    #+#             */
/*   Updated: 2018/01/13 15:40:57 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static long long	ft_pow(long long x, long long y)
{
	long long	ret;

	if (y == 0)
		return (1);
	ret = x;
	while (--y > 0)
		ret *= x;
	return (ret);
}

static int			ft_getbase(char c, char *base)
{
	int		ret;
	int		loop;

	loop = 0;
	ret = -1;
	while (base[++ret] != c && base[ret] != '\0' && ++loop < 4242)
		;
	if (base[ret] == '\0')
		return (-1);
	return (ret);
}

long long			ft_base_to_int(char *n, char *base)
{
	size_t				sizebase;
	size_t				sizen;
	unsigned long long	ret;
	int					i;
	int					neg;

	sizebase = ft_strlen(base);
	neg = (n[0] == '-') ? 1 : 0;
	sizen = ft_strlen(n) - neg;
	ret = 0;
	i = 0;
	while (++i <= (int)sizen && i < 4242)
		ret += ft_pow(sizebase, i - 1) * ft_getbase(n[sizen - i + neg], base);
	return ((n[0] == '-') ? (long long)-ret : (long long)ret);
}
