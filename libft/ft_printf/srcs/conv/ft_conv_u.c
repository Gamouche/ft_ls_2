/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 16:11:18 by cyfermie          #+#    #+#             */
/*   Updated: 2018/01/13 16:21:33 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_2.h>

static int	ft_nb_len_u(t_arg *arg)
{
	t_ull	tmp;
	int		nb_len;

	tmp = arg->arg.u;
	nb_len = 1;
	while ((tmp /= 10) && nb_len < 4242)
		nb_len++;
	return (nb_len);
}

static int	ft_no_precision(char **new_ret, t_arg *arg, int len)
{
	int		nb_len;

	nb_len = ft_nb_len_u(arg);
	len = (nb_len > len) ? nb_len : len;
	if (!((*new_ret) = malloc(sizeof(**new_ret) * (len + 1))))
		return (ERROR);
	(*new_ret)[len] = '\0';
	*new_ret = (arg->flag.zero == 1) ? ft_memset(*new_ret, '0', len) :
		ft_memset(*new_ret, ' ', len);
	nb_len = (arg->flag.minus == 0) ? len : nb_len;
	ft_fill_str_ud(new_ret, arg->arg.u, &nb_len, arg);
	if (arg->arg.u == 0)
		(*new_ret)[--nb_len] = '0';
	return (SUCCESS);
}

static int	ft_width(char **new_ret, char **new_nb, t_arg *arg)
{
	int	len;
	int	nb_len;

	len = arg->wi;
	if ((arg->preci == -1) && (ft_no_precision(new_ret, arg, len) == ERROR))
		return (ERROR);
	else if (arg->preci != -1)
	{
		nb_len = ft_strlen(*new_nb);
		len = (nb_len > len) ? nb_len : len;
		if (!(*new_ret = malloc(sizeof(**new_ret) * (len + 1))) &&
				ft_fruit(1, *new_nb))
			return (ERROR);
		(*new_ret)[len] = '\0';
		if (arg->preci < arg->wi && ft_memset(*new_ret, ' ', len))
			if (arg->flag.minus == 0)
				ft_strncpy((*new_ret) + len - nb_len, *new_nb, nb_len);
			else
				ft_strncpy(*new_ret, *new_nb, nb_len);
		else if (ft_fruit(1, *new_ret)
				&& !(*new_ret = ft_strdup(*new_nb)) && ft_fruit(1, *new_nb))
			return (ERROR);
	}
	return (SUCCESS);
}

static int	ft_precision(char **new_nb, t_arg *arg)
{
	int		len;
	int		nb_len;

	nb_len = ft_nb_len_u(arg);
	len = arg->preci;
	len = (nb_len > len) ? nb_len : len;
	if (!((*new_nb) = malloc(sizeof(**new_nb) * (len + 1))))
		return (ERROR);
	ft_memset(*new_nb, '0', len);
	(*new_nb)[len] = '\0';
	ft_fill_str_ud(new_nb, arg->arg.u, &len, arg);
	return (SUCCESS);
}

int			ft_conv_u(char **ret, t_arg *arg)
{
	char	*new_nb;
	char	*new_ret;
	int		len;

	new_nb = NULL;
	if (ft_strchr("u", arg->conv) && arg->height[0] == '\0')
		arg->arg.u = (unsigned int)arg->arg.u;
	if (arg->preci == 0 && arg->arg.u == 0)
		return (ft_regle_zero(ret, arg));
	if (arg->preci != -1)
	{
		if (ft_precision(&new_nb, arg) == ERROR)
			return (ERROR);
	}
	if (ft_width(&new_ret, &new_nb, arg) == ERROR)
		return (ERROR);
	free(new_nb);
	len = ft_strlen(new_ret);
	if (!(*ret = ft_strfreejoin(*ret, new_ret, len, arg)))
		return (ERROR);
	arg->cmpt += len;
	free(new_ret);
	return (SUCCESS);
}
