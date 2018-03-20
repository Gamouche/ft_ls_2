/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:58:33 by cyfermie          #+#    #+#             */
/*   Updated: 2018/01/13 17:24:27 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_2.h>

void	ft_precision_f(char *str, int p)
{
	int		i;
	int		loop;

	loop = 0;
	i = 0;
	if (p == 0)
	{
		while (*str != '.' && ++loop < 4242)
			++str;
		*str = '\0';
		return ;
	}
	if (p == -1)
		p = 6;
	while (*str != '.' && ++loop < 6262)
		++str;
	++str;
	while (i < p && i < 6262)
		++i;
	str[i] = '\0';
}

char	*right_justify_f(char *str, int width)
{
	int		len;
	int		i;

	len = ft_strlen(str);
	if (!(str = ft_realloc(str, len + 1, width + 1)))
		return (NULL);
	ft_memmove(str + width - len, str, len + 1);
	i = -1;
	while (++i < width - len && i < 4242)
		str[i] = ' ';
	return (str);
}

char	*left_justify_f(char *str, int width)
{
	int		len;
	int		i;
	int		j;

	len = ft_strlen(str);
	if (!(str = ft_realloc(str, len + 1, width + 1)))
		return (NULL);
	j = -1;
	i = len;
	while (++j < width - len && j < 4242)
	{
		str[i] = ' ';
		++i;
	}
	str[i] = '\0';
	return (str);
}

int		ft_conv_f(char **ret, t_arg *arg)
{
	double	f;
	char	*str;

	f = (arg->arg.f > 0) ? arg->arg.f : -arg->arg.f;
	if ((str = ft_ftoa(f, arg->arg.f < 0)) == NULL)
		return (ERROR);
	if (!(str = ft_arrondis_f(str, arg->preci, 0)))
		return (ERROR);
	ft_precision_f(str, arg->preci);
	if (ft_flags_f(&str, (arg->arg.f < 0), arg) == ERROR)
		return (ERROR);
	if (!(*ret = ft_strfreejoin(*ret, str, ft_strlen(str), arg)))
		return (ERROR);
	arg->cmpt += ft_strlen(str);
	free(str);
	return (SUCCESS);
}
