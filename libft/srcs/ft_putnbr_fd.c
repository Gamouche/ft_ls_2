/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:16:35 by cyfermie          #+#    #+#             */
/*   Updated: 2017/11/07 16:16:46 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(long long n, int fd)
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
	write(fd, tab + index + 1, 49 - index);
}
