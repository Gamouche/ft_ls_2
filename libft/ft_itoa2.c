/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:09:54 by cyfermie          #+#    #+#             */
/*   Updated: 2018/02/15 19:42:21 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>

static size_t	get_size_alloc(int64_t n)
{
	size_t			size_alloc;
	uint64_t		u;

	if (n == 0)
		return (1);
	size_alloc = (n < 0) ? (1) : (0);
	u = (n < 0) ? ((uint64_t)-n) : ((uint64_t)n);
	while (u > 0)
	{
		u = u / 10;
		++size_alloc;
	}
	return (size_alloc);
}

static void		fill_str(char *str, int64_t n, size_t size_alloc)
{
	uint64_t	u;

	str[size_alloc] = '\0';
	if (n == 0)
	{
		*str = '0';
		return ;
	}
	u = (n < 0) ? ((uint64_t)-n) : ((uint64_t)n);
	while (u > 0)
	{
		--size_alloc;
		str[size_alloc] = u % 10 + '0';
		u = u / 10;
	}
	if (n < 0)
		*str = '-';
}

char			*ft_itoa2(int64_t n, char *str)
{
	size_t	size_alloc;

	size_alloc = get_size_alloc(n);
	fill_str(str, n, size_alloc);
	return (str);
}
