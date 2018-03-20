/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_bigs_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:55:19 by cyfermie          #+#    #+#             */
/*   Updated: 2018/01/13 17:30:23 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_2.h>

static int	ft_strlen_wchart_s(wchar_t *wstr)
{
	int		len;
	int		i;

	len = 0;
	i = -1;
	while (wstr[++i] && i < 4242)
		len += ft_strlenw(wstr[i]);
	return (len);
}

static int	ft_width_str(t_arg *arg, int len)
{
	if (arg->wi != 0 && arg->preci != -1)
	{
		if (arg->preci > arg->wi)
		{
			if (arg->preci < len)
				return (arg->preci);
			else if (arg->preci > len && arg->wi < len)
				return (len);
			else if (arg->preci > len && arg->wi > len)
				return (arg->wi);
			return (len);
		}
		else if (arg->preci < arg->wi)
			return (arg->wi);
		return (arg->preci);
	}
	else if (arg->preci != -1 && arg->wi == 0)
		return (arg->preci);
	else if (arg->preci == -1 && arg->wi != 0)
	{
		if (arg->wi <= len)
			return (len);
		return (arg->wi > len) ? arg->wi : arg->wi - len;
	}
	return (len);
}

static void	ft_init_i(int *i, t_arg *arg, int len)
{
	if (arg->flag.minus == 0 && arg->preci != -1 && arg->preci <= len)
		*i = (arg->wi < len && arg->preci > arg->wi) ? 0 : arg->wi - arg->preci;
	if (arg->flag.minus == 0 && arg->preci != -1 && arg->preci > len)
		*i = (arg->wi < len) ? 0 : arg->wi - len;
	else if (arg->flag.minus == 0 && arg->preci == -1 && arg->wi >= len)
		*i = arg->wi - len;
}

static int	ft_strcpy_cust_bigs(char **str, t_arg *arg, wchar_t *x, int *nbcar)
{
	int		i;
	char	*tmp;
	int		len;
	int		loop;

	loop = 0;
	i = 0;
	len = ft_strlen_wchart_s(x);
	ft_init_i(&i, arg, len);
	if (!(tmp = ft_strnew(*nbcar)))
		return (ERROR);
	if ((int)(ft_strlen(*str) - *nbcar) != i && arg->flag.minus != 1)
		i = (int)(ft_strlen(*str) - *nbcar);
	while (*x && arg->preci > 0 && ++loop < 4242)
	{
		arg->arg.c = *x;
		if (arg->preci > 0 && arg->preci >= ft_strlenw_bigs(*x))
			if (ft_add_conv_bigc(&tmp, arg) == ERROR && ft_fruit(1, tmp))
				return (ERROR);
		arg->preci -= ft_strlenw_bigs(*x);
		x++;
	}
	str = ft_strw_cpy(str, i, tmp);
	free(tmp);
	return (SUCCESS);
}

int			ft_add_conv_bigs(char **ret, t_arg *arg, wchar_t *x, int cmpt)
{
	int		len;
	int		strl;
	int		nbcar;
	char	*str;

	str = NULL;
	len = ft_strlen_wchart_s(x);
	strl = ft_width_str(arg, len);
	ft_check_nbcar(arg, &nbcar, x, &strl);
	if (!(str = ft_strnew(strl)))
		return (ERROR);
	arg->flag.zero == 1 ? ft_memset(str, '0', strl) : ft_memset(str, ' ', strl);
	if (ft_strcpy_cust_bigs(&str, arg, x, &nbcar) == ERROR && ft_fruit(1, str)
	&& !(arg->flag.zero = 0))
		return (ft_checknull_bigs(ret, arg, &x));
	if (arg->cmpt != 0)
		arg->cmpt -= nbcar;
	if (cmpt != 0)
		arg->cmpt += cmpt;
	if (!(*ret = ft_strfreejoin(*ret, str, strl, arg)))
		return (ERROR);
	arg->cmpt += strl;
	free(str);
	return (SUCCESS);
}
