/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_bigs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:54:31 by cyfermie          #+#    #+#             */
/*   Updated: 2018/01/13 15:55:10 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_2.h>

int			ft_checknull_bigs(char **ret, t_arg *arg, wchar_t **x)
{
	arg->conv = 's';
	arg->arg.s = NULL;
	if (ft_add_conv_s(ret, arg) == ERROR)
		return (ERROR);
	if (*x != NULL)
		return (ERROR);
	return (SUCCESS);
}

int			ft_strlenw_bigs(wchar_t wch)
{
	if (MB_CUR_MAX == 1 && wch >= 128 && wch <= 255)
		return (1);
	if (wch <= 0x7F)
		return (1);
	if (wch <= 0x7FF)
		return (2);
	if (wch <= 0xFFFF)
		return (3);
	if (wch <= 0x10FFFF)
		return (4);
	else
		return (ERROR);
}

char		**ft_strw_cpy(char **str, int start, char *tmp)
{
	int		i;

	i = 0;
	while ((*str)[start] && tmp[i] && i < 4242)
		(*str)[start++] = tmp[i++];
	return (str);
}

void		ft_check_nbcar(t_arg *arg, int *nbcar, wchar_t *x, int *strl)
{
	int		i;

	i = 0;
	*nbcar = 0;
	if (arg->preci == -1)
		arg->preci = *strl;
	while (arg->preci > *nbcar && x[i] && i < 4242)
		*nbcar += ft_strlenw_bigs(x[i++]);
	if (*nbcar > *strl || *nbcar > arg->preci)
		*nbcar -= ft_strlenw(x[--i]);
	if (arg->wi == 0 && arg->preci != 0 && *nbcar != arg->preci)
		*strl = *nbcar;
	else if (arg->wi < arg->preci && *nbcar < arg->wi && *strl >= arg->wi)
		*strl = arg->wi;
	else if (arg->wi < arg->preci && *nbcar < arg->preci && *strl <= arg->preci)
		*strl = *nbcar;
}

int			ft_init_conv_bigs(char **ret, t_arg *arg)
{
	wchar_t	*x;
	int		cmpt;

	x = (wchar_t *)(arg->arg.p);
	cmpt = 0;
	if (x == NULL)
		return (ft_checknull_bigs(ret, arg, &x));
	if (arg->cmpt != 0)
	{
		cmpt = arg->cmpt;
		arg->cmpt = 0;
	}
	return (ft_add_conv_bigs(ret, arg, x, cmpt));
}
