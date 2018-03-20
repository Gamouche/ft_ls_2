/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_e.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:58:04 by cyfermie          #+#    #+#             */
/*   Updated: 2018/01/13 17:28:21 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_2.h>

void		ft_flag_zero_neg_e(char *s, char *n, t_arg *arg)
{
	int i;

	i = -1;
	if (arg->flag.zero == 1 && n[0] == '-')
	{
		while (s[++i] == '0' && i < 4242)
			;
		s[i] = '0';
		s[0] = '-';
	}
}

void		ft_flag_space_plus_e(char *s, char *n, t_arg *arg)
{
	if (arg->flag.space == 1 && n[0] != '-')
	{
		if (arg->flag.minus == 1)
			ft_memmove(s + 1, s, ft_strlen(s) - 1);
		s[0] = ' ';
	}
	else if (arg->flag.plus == 1 && n[0] != '-')
	{
		if (arg->flag.minus == 1)
		{
			ft_memmove(s + 1, s, ft_strlen(s) - 1);
			s[0] = '+';
		}
		else if (arg->flag.zero == 1)
			s[0] = '+';
		else
			s[ft_strlen(s) - ft_strlen(n) - 1] = '+';
	}
}

int			ft_flags_e(char **nr, char *nn, t_arg *arg)
{
	int		ln;

	ln = ((t_ull)arg->wi > ft_strlen(nn)) ? arg->wi : (int)ft_strlen(nn);
	ln += ((arg->flag.space == 1 || arg->flag.plus == 1) && nn[0] != '-' &&
			(t_ull)arg->wi <= ft_strlen(nn)) ? 1 : 0;
	if (!(*nr = malloc(sizeof(**nr) * (ln + 1))))
		return (ERROR);
	(*nr)[ln] = '\0';
	*nr = (arg->flag.zero == 1) ? ft_memset(*nr, '0', ln) :
		ft_memset(*nr, ' ', ln);
	if (arg->flag.minus == 0)
		ft_strncpy((*nr) + ln - ft_strlen(nn), nn, ft_strlen(nn));
	else
		ft_strncpy(*nr, nn, ft_strlen(nn));
	if (arg->flag.zero == 1)
		ft_flag_zero_neg_e(*nr, nn, arg);
	if (arg->flag.space == 1 || arg->flag.plus == 1)
		ft_flag_space_plus_e(*nr, nn, arg);
	return (SUCCESS);
}

int			ft_conv_e(char **ret, t_arg *arg)
{
	char	*new_nb;
	char	*new_ret;
	int		len;

	if (arg->arg.f == 0.0)
	{
		if (!(new_nb = ft_strdup("0.000000e+00")))
			return (ERROR);
	}
	else
	{
		if (ft_precision_e(&new_nb, arg) == ERROR && ft_fruit(1, new_nb))
			return (ERROR);
	}
	if (ft_flags_e(&new_ret, new_nb, arg) == ERROR &&
			ft_fruit(2, new_ret, new_nb))
		return (ERROR);
	free(new_nb);
	len = ft_strlen(new_ret);
	if (!(*ret = ft_strfreejoin(*ret, new_ret, len, arg)) &&
			ft_fruit(1, new_ret))
		return (ERROR);
	arg->cmpt += len;
	free(new_ret);
	return (SUCCESS);
}
