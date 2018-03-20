/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_modulo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 16:06:10 by cyfermie          #+#    #+#             */
/*   Updated: 2018/01/13 16:06:14 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_2.h>

int		ft_conv_modulo(char **ret, t_arg *arg)
{
	char	*tmp;
	int		size;

	size = 1;
	if (arg->wi > 0)
		size = arg->wi;
	if (!(tmp = ft_strnew(size)))
		return (ERROR);
	if (arg->flag.zero == 1)
		ft_memset(tmp, '0', size);
	else
		ft_memset(tmp, ' ', size);
	if (arg->flag.minus == 1)
		tmp[0] = '%';
	else
		tmp[size - 1] = '%';
	if (!(*ret = ft_strfreejoin(*ret, tmp, size, arg)) && ft_fruit(1, tmp))
		return (ERROR);
	arg->cmpt += size;
	free(tmp);
	return (SUCCESS);
}
