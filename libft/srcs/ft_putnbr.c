/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:16:00 by cyfermie          #+#    #+#             */
/*   Updated: 2017/11/07 16:16:09 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

ssize_t		ft_putnbr(long long n)
{
	char				tab[50];
	unsigned short		index;
	unsigned long long	u;

	index = 49;
	u = (n < 0) ? ((unsigned long long)-n) : ((unsigned long long)n);
	while (u > 0)
	{
		tab[index] = u % 10 + '0';
		--index;
		u = u / 10;
	}
	if (n < 0)
	{
		tab[index] = '-';
		--index;
	}
	else if (n == 0)
	{
		tab[index] = '0';
		--index;
	}
	return (write(STDOUT_FILENO, tab + index + 1, 49 - index));
}
