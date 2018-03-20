/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fruit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 13:57:16 by cyfermie          #+#    #+#             */
/*   Updated: 2018/01/13 13:57:18 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>

int		ft_fruit(size_t n, ...)
{
	void	*del;
	va_list	ap;

	va_start(ap, n);
	while (n-- > 0)
		free((del = va_arg(ap, void *)));
	va_end(ap);
	return (1);
}
