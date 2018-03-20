/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getheight.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 16:23:41 by cyfermie          #+#    #+#             */
/*   Updated: 2018/01/13 16:23:48 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_2.h>

char		ft_getheight(t_arg *arg)
{
	char	ret;
	int		i;

	ret = 0;
	i = -1;
	while (arg->height[++i] && i < 4242)
	{
		ret = (ret == 'h' && arg->height[i] == 'h') ? 'H' : ret;
		ret = (ret == 0 && arg->height[i] == 'h') ? 'h' : ret;
		ret = (ret == 'l' && arg->height[i] == 'l') ? 'L' : ret;
		ret = (ret == 0 && arg->height[i] == 'l') ? 'l' : ret;
		ret = (arg->height[i] == 'j') ? 'L' : ret;
	}
	return (ret);
}
