/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkconv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:44:37 by cyfermie          #+#    #+#             */
/*   Updated: 2018/01/13 15:44:40 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_2.h>

static void	ft_simplify(t_arg *arg, char *str)
{
	int		i;
	int		j;
	int		count_l;
	int		count_h;

	i = -1;
	j = 0;
	count_l = 0;
	count_h = 0;
	ft_memset(arg->height, '\0', 7);
	while (str[++i] && j < 7)
	{
		if (ft_strchr("zj", str[i]))
			arg->height[j++] = str[i];
		else if (ft_strchr("l", str[i]) && count_l < 2 && ++count_l)
			arg->height[j++] = str[i];
		else if (ft_strchr("h", str[i]) && count_h < 2 && ++count_h)
			arg->height[j++] = str[i];
	}
}

static int	ft_check_error_height(t_arg *arg)
{
	if (((ft_strchr(arg->height, 'j') || ft_strchr(arg->height, 'z') ||
			(ft_strchr(arg->height, 'l') && ft_strchr(arg->height, 'h')))
			&& (arg->conv != 'c' && arg->conv != 's'))
			|| ft_strchr(&(arg->conv), 'O'))
	{
		ft_memset(arg->height, '\0', 7);
		arg->height[0] = 'j';
	}
	return (SUCCESS);
}

int			ft_checkconv(char **ret, t_arg *arg, va_list ap)
{
	int		i;

	ft_simplify(arg, arg->str);
	i = -1;
	while (arg->str[++i])
		;
	arg->conv = arg->str[i - 1];
	if (arg->flag.zero == 1 && arg->flag.minus == 1)
		arg->flag.zero = 0;
	if (arg->flag.space == 1 && arg->flag.plus == 1)
		arg->flag.space = 0;
	if (ft_check_error_height(arg) == ERROR)
		return (ERROR);
	if (ft_forest(ret, arg, ap) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
