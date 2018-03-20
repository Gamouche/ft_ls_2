/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_str_ud.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 16:15:05 by cyfermie          #+#    #+#             */
/*   Updated: 2018/01/13 16:15:47 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_2.h>

void		ft_fill_str_ud(char **str, long long nb, int *len, t_arg *arg)
{
	t_ull	tmp;

	if (ft_strchr("Uu", arg->conv))
		tmp = nb;
	else
		tmp = (nb < 0) ? -(t_ull)nb : (t_ull)nb;
	while (tmp > 0 && --(*len) >= 0)
	{
		(*str)[*len] = tmp % 10 + '0';
		tmp /= 10;
	}
}
