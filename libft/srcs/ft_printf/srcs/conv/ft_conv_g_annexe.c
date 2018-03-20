/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_g_annexe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 16:03:29 by cyfermie          #+#    #+#             */
/*   Updated: 2018/01/13 16:03:59 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_2.h>

int		ft_calcul_zero_ap(t_arg *arg)
{
	int		tmp;
	int		ret;
	int		mtp;

	tmp = ft_abs((int)(arg->arg.f));
	if (tmp > 0)
		return (0);
	ret = -1;
	mtp = 10;
	while (tmp == 0 && ret < 4242)
	{
		ret++;
		tmp = (arg->arg.f) * mtp;
		mtp *= 10;
	}
	return (ret);
}
