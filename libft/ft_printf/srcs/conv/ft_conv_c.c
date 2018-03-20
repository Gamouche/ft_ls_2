/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:57:02 by cyfermie          #+#    #+#             */
/*   Updated: 2018/01/13 15:57:21 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_2.h>

int		ft_add_conv_c(char **ret, t_arg *arg)
{
	char	*tmp;
	size_t	size;

	size = (arg->wi > 0) ? arg->wi : 1;
	if (!(tmp = ft_strnew(size)))
		return (ERROR);
	if (arg->flag.zero == 1 && arg->flag.minus == 0)
		ft_memset(tmp, '0', size);
	else if (!(ft_memset(tmp, ' ', size)))
		return (ERROR);
	if ((arg->flag).minus == 1)
		tmp[0] = arg->arg.c;
	else
		tmp[size - 1] = arg->arg.c;
	if (!(*ret = ft_strfreejoin(*ret, tmp, size, arg)))
		return (ERROR);
	arg->cmpt += size;
	free(tmp);
	return (SUCCESS);
}

int		ft_length_cs(t_arg *arg)
{
	int		i;
	int		count_l;

	i = -1;
	count_l = 0;
	while (arg->str[++i] && i < 4242)
		if (ft_strchr("l", arg->str[i]))
			++count_l;
	if (count_l % 2 == 0)
		return (SUCCESS);
	else
		return (ERROR);
}

int		ft_conv_c(char **ret, t_arg *arg)
{
	if (arg->conv == 'C' || (arg->conv == 'c' && ft_length_cs(arg) == ERROR))
		return (ft_add_conv_bigc(ret, arg));
	return (ft_add_conv_c(ret, arg));
}
