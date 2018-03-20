/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:53:58 by cyfermie          #+#    #+#             */
/*   Updated: 2018/01/13 19:25:39 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_2.h>

int			ft_conv_b(char **ret, t_arg *arg)
{
	int			i;
	int			size;
	int			start;
	long long	nb;
	char		*new_ret;

	size = (arg->preci == -1) ? 64 : arg->preci;
	size += (arg->flag.hashtag == 1) ? 2 : 0;
	size += 2;
	if (!(new_ret = ft_strnew(size)))
		return (ERROR);
	new_ret[0] = '0';
	new_ret[1] = (arg->conv == 'b') ? 'b' : 'B';
	nb = arg->arg.d;
	start = (arg->flag.hashtag == 1) ? 2 : 0;
	i = size - start - 2;
	while (--i >= 0)
		new_ret[size - i - 1] = ((nb >> i) & 1) + '0';
	if (!(*ret = ft_strfreejoin(*ret, new_ret, size, arg)))
		return (ERROR);
	arg->cmpt += size;
	free(new_ret);
	return (SUCCESS);
}
